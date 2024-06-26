#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "openDIct.h"


Dictionary createOpenDict(){
    Dictionary d;
    d.List = malloc(sizeof(Node)*10);
    d.count = 0;
    d.size = 10;

    for(int i=0;i<d.size;i++){
        d.List[i] = NULL;
    }

    return d;

}
int hashFunction(char *key, int size){

    int i, ret=0;
    for(i=0;i<strlen(key);i++){
        ret = ret + key[i];
    }
    ret = ret%size;

    return ret;
}
void insertOpenDict(Dictionary *d, Queue *acl,  Person p){
    int key;
    NodePtr *trav;
    float thresh = (float)d->count/d->size;
        if(thresh<THRESHOLD){
            if(!searchOpenDict(*d, p.name)){
                NodePtr newP = malloc(sizeof(struct node));
                if(newP!=NULL){
                    newP->p = p;
                    key = hashFunction(p.name.lName, d->size);
                    printf("INSERT INDEX %d\n", key);
                    trav = &d->List[key];
                    while(*trav!=NULL && strcmp((*trav)->p.name.lName, p.name.lName)<0){
                        trav = &(*trav)->next;
                    }
                    newP->next = *trav;
                    *trav = newP;
                    d->count++;

                }

                enqueue(acl, p);
            }else{
                printf("Person Existed!\n");
            }
        }else{
            resizeDictionary(d, acl);
            insertOpenDict(d, acl, p);
        }

}
bool searchOpenDict(Dictionary d, Name n){
    bool ret = false;
    int key = hashFunction(n.lName, d.size);
    NodePtr trav = d.List[key];
    while(trav!=NULL && (strcmp(trav->p.name.fName, n.fName)!=0 || strcmp(trav->p.name.lName, n.lName)!=0)){
        trav = trav->next;
    }
    if(trav!=NULL){
        ret = true;
    }

    return ret;

}
void updateOpenDict(Dictionary *d, Name n, Person p){

    if(searchOpenDict(*d, n)){
        int key = hashFunction(n.lName, d->size);
        NodePtr *trav = &d->List[key];
        while(*trav!=NULL && (strcmp((*trav)->p.name.fName, n.fName)!=0 || strcmp((*trav)->p.name.lName, n.lName)!=0)){
            trav = &(*trav)->next;
        }
        if(*trav!=NULL){
            (*trav)->p = p;
            printf("UPDATED INFORMATION\n");
            printf("Name: %s %s\n", (*trav)->p.name.fName, (*trav)->p.name.lName);
            printf("Address: %s, %s, %s, %s %d\t",(*trav)->p.address.street, (*trav)->p.address.barangay, (*trav)->p.address.city, (*trav)->p.address.province, (*trav)->p.address.zipCode);
        }

    }else{
        printf("Person Not Found");
    }



}
void updateName(Dictionary *d, Queue *acl, Name n, Person p){

    NodePtr temp;
    if(searchOpenDict(*d, n)){
        int key = hashFunction(n.lName, d->size);
        NodePtr *trav = &d->List[key];
        while(*trav!=NULL && (strcmp((*trav)->p.name.fName, n.fName)!=0 || strcmp((*trav)->p.name.lName, n.lName)!=0)){
            trav = &(*trav)->next;
        }
        if(*trav!=NULL){
            temp = *trav;
            *trav = temp->next;
            free(temp);
        }

    }else{
        printf("Person Not Found");
    }

    Queue tempq;
    Person val;
    initQueue(&tempq);

    while(!isEmpty(*acl)){
        val = front(*acl);
        dequeue(acl);
        if((strcmp(val.name.fName, n.fName)==0 && strcmp(val.name.lName, n.lName)==0)){
            val = p;
        }
        enqueue(&tempq, val);
    }

    while(!isEmpty(tempq)){
        val = front(tempq);
        dequeue(&tempq);
        enqueue(acl, val);
    }


    NodePtr newP = malloc(sizeof(struct node));
    if(newP!=NULL){
        newP->p = p;
        int key = hashFunction(p.name.lName, d->size);
        NodePtr *trav = &d->List[key];
        while(*trav!=NULL && strcmp((*trav)->p.name.lName, p.name.lName)<0){
            trav = &(*trav)->next;
        }
        newP->next = *trav;
        *trav = newP;
        printf("UPDATED INFORMATION\n");
            printf("Name: %s %s\n", (*trav)->p.name.fName, (*trav)->p.name.lName);
            printf("Address: %s, %s, %s, %s %d\t",(*trav)->p.address.street, (*trav)->p.address.barangay, (*trav)->p.address.city, (*trav)->p.address.province, (*trav)->p.address.zipCode);
    }
}
void deleteOpenDict(Dictionary *d, Queue *acl, Name n){
    NodePtr temp;
    if(searchOpenDict(*d, n)){
        int key = hashFunction(n.lName, d->size);
        NodePtr *trav = &d->List[key];
        while(*trav!=NULL && (strcmp((*trav)->p.name.fName, n.fName)!=0 || strcmp((*trav)->p.name.lName, n.lName)!=0)){
            trav = &(*trav)->next;
        }
        if(*trav!=NULL){
            temp = *trav;
            *trav = temp->next;
            free(temp);
        }

    }else{
        printf("Person Not Found");
    }

    Queue tempq;
    initQueue(&tempq);
    Person val;

    while(!isEmpty(*acl)){
        val = front(*acl);
        dequeue(acl);
        if((strcmp(val.name.fName, n.fName)!=0 || strcmp(val.name.lName, n.lName)!=0)){
            enqueue(&tempq, val);
        }
    }
    while(!isEmpty(tempq)){
        val = front(tempq);
        dequeue(&tempq);
        enqueue(acl, val);
    }

    d->count--;

}
void visualize(Dictionary d){
    int i;
    NodePtr trav;
    printf("COUNT: %d", d.count);
    for(i=0;i<d.size;i++){
        trav = d.List[i];
        printf("INDEX: %d\n", i);
        if(trav==NULL){
            printf("NULL==========\n");
        }
        while(trav!=NULL){
            printf("Name: %s %s\n", trav->p.name.fName, trav->p.name.lName);
            printf("Address: %s, %s, %s, %s, %d\n", trav->p.address.street, trav->p.address.barangay, trav->p.address.city, trav->p.address.province, trav->p.address.zipCode);
            trav = trav->next;
        }
    }
}

void resizeDictionary(Dictionary *d, Queue *acl){
    int i, j=0;
    NodePtr *trav, temp;
    Person val;
    for(i=0;i<d->size;i++){
        trav = &(*d).List[i];
        while(*trav!=NULL){
            temp = *trav;
            *trav = temp->next;
            free(temp);
        }
    }
    free(d->List);
    d->size = d->size+3;
    d->List = malloc(sizeof(Node)*(d->size));

    for(int i=0;i<d->size;i++){
        d->List[i] = NULL;
    }

    while(j<d->count){
        val = front(*acl);
        dequeue(acl);
        if(!searchOpenDict(*d, val.name)){
            NodePtr newP = malloc(sizeof(struct node));
            if(newP!=NULL){
                newP->p = val;
                int key = hashFunction(val.name.lName, d->size);
                trav = &d->List[key];
                while(*trav!=NULL && strcmp((*trav)->p.name.lName, val.name.lName)<0){
                    trav = &(*trav)->next;
                }
                newP->next = *trav;
                *trav = newP;
            }

            enqueue(acl, val);
        }else{
            printf("Person Existed!\n");
        }
        j++;
    }


}

void initQueue(Queue *q){
    q->front = NULL;
    q->rear = NULL;
}
void enqueue(Queue *q, Person p){
    NodePtr newP = malloc(sizeof(Node));
    if(newP!=NULL){
        newP->p = p;
        newP->next = NULL;
        if(isEmpty(*q)){
            q->front = newP;
        }else{
            q->rear->next = newP;
        }
        q->rear = newP;
    }

}
void dequeue(Queue *q){

    if(!isEmpty(*q)){
        NodePtr temp = q->front;
        if(q->front->next==NULL){
            q->rear = NULL;
        }
        q->front = temp->next;
        free(temp);
    }

}
Person front(Queue q){
    return q.front->p;
}
bool isEmpty(Queue q){
    return (q.front==NULL) ? true : false;
}