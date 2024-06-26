#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "closeDict.h"

Dictionary createCloseDict(){
    Dictionary d;
    d.List = malloc(sizeof(Person)*10);
    d.size = 10;
    d.count = 0;

    for(int i=0;i<d.size;i++){
        strcpy(d.List[i].name.lName, EMPTY);
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
void insertCloseDict(Dictionary *d, Queue *acl, Person p){
    int j;
    float thresh = (float)d->count/d->size;
    printf("THRESH %.2f\n", thresh);
    if(thresh<THRESHOLD){
        if(!searchCloseDict(*d, p.name)){
            int key = hashFunction(p.name.lName, d->size);
            printf("INSERT INDEX %d\n", key);
            for(j=0;j<d->size && (strcmp(d->List[key].name.lName, EMPTY)!=0 && strcmp(d->List[key].name.lName, DELETED)!=0 );key = (key+1)%d->size, j++){}
            if(j<d->size){
                d->List[key] = p;
            }
            d->count++;
            enqueue(acl, p);
        }else{
            printf("Person Existed!\n");
        }
    }
    else{
        resizeDictionary(d, acl);
        insertCloseDict(d, acl, p);
    }
}
bool searchCloseDict(Dictionary d, Name n){
    bool ret = false;
    int key = hashFunction(n.lName, d.size), j;
    for(j=0;j<d.size && (strcmp(d.List[key].name.fName, n.fName)!=0 || strcmp(d.List[key].name.lName, n.lName)!=0); key = (key+1)%d.size, j++){}
    if(j!=d.size){
        ret = true;
    }
    return ret;

}
void updateCloseDict(Dictionary *d, Name n, Person p){
    int j;
    if(searchCloseDict(*d, n)){
        int key = hashFunction(p.name.lName, d->size);
        for(j=0;j<d->size && (strcmp(d->List[key].name.fName, p.name.fName)!=0 && strcmp(d->List[key].name.lName, p.name.lName)!=0 );key = (key+1)%d->size, j++){}
        if(j<d->size){
            d->List[key] = p;
            printf("UPDATED INFORMATION\n");
            printf("Name: %s %s\n", d->List[key].name.fName, d->List[key].name.lName);
            printf("Address: %s, %s, %s, %s %d\t",d->List[key].address.street, d->List[key].address.barangay, d->List[key].address.city, d->List[key].address.province, d->List[key].address.zipCode);
        }
    }

}
void updateName(Dictionary *d, Queue *acl, Name n, Person p){

    deleteCloseDict(d, n);
    insertCloseDict(d, acl, p);

}
void deleteCloseDict(Dictionary *d, Name n){

    if(searchCloseDict(*d, n)){
        int j;
        int key = hashFunction(n.lName, d->size);
        for(j=0;j<d->size && (strcmp(d->List[key].name.fName, n.fName)!=0 && strcmp(d->List[key].name.lName, n.lName)!=0 );key = (key+1)%d->size, j++){}
        if(j<d->size){
            strcpy(d->List[key].name.lName, DELETED);
        }
    }else{
        printf("Person does not exist\n");
    }
}
void visualize(Dictionary d){

    int i;
    for(i=0;i<d.size;i++){
        printf("INDEX %d\n", i);
        if(strcmp(d.List[i].name.lName, EMPTY)==0){
            printf("EMPTY=====\n");
        }else if(strcmp(d.List[i].name.lName, DELETED)==0){
            printf("DELETED=====\n");
        }else{
            printf("Name: %s %s\n", d.List[i].name.fName, d.List[i].name.lName);
            printf("Address: %s, %s, %s, %s, %d\n", d.List[i].address.street, d.List[i].address.barangay, d.List[i].address.city, d.List[i].address.province, d.List[i].address.zipCode);
        }
    }

}
void resizeDictionary(Dictionary *d, Queue *acl){
    int i, j=0, k;
    Person val;
    free(d->List);
    d->size = d->size+3;
    d->List = malloc(sizeof(Person)*d->size);
    for(i=0;i<d->size;i++){
        strcpy(d->List[i].name.lName, EMPTY);
    }

    while(j<d->count){
        val = front(*acl);
        dequeue(acl);
        if(!searchCloseDict(*d, val.name)){
            int key = hashFunction(val.name.lName, d->size);
            printf("INSERT NEW INDEX %d\n", key);
            for(k=0;k<d->size && (strcmp(d->List[key].name.lName, EMPTY)!=0 && strcmp(d->List[key].name.lName, DELETED)!=0 );key = (key+1)%d->size, k++){}
            if(k<d->size){
                d->List[key] = val;
            }
            enqueue(acl, val);
        }else{
            printf("Person Exists!\n");
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