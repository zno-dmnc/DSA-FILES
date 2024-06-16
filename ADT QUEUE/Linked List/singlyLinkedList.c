#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "singlyLinkedList.h"


void initQueue(Queue *q){
    q->head = NULL;
    q->tail = NULL;

}
bool enqueue(Queue *q, studentInfo newStud){
    bool ret = false;
    classRecordPtr newS = malloc(sizeof(classRecord));

    if(newS!=NULL){
        newS->student = newStud;
        newS->next = NULL;
        if(isEmpty(*q)){
            q->head = newS;
        }else{
            q->tail->next = newS;
        }
        q->tail = newS;
        ret = true;
    }
    return true;
}
bool dequeue(Queue *q){
    bool ret = false;
    if(!isEmpty(*q)){
        classRecordPtr temp;
        temp = q->head;
        if(q->head->next==NULL){
            q->tail = NULL;
        }
        q->head = temp->next;
        free(temp);
        ret = true;
    }

    return ret;
    
}
studentInfo front(Queue q){
    return q.head->student;
}
studentInfo rear(Queue q){
    return q.tail->student;
}
bool isEmpty(Queue q){
    return (q.head==NULL) ? true : false;
}

Queue allMale(Queue *q){
    Queue temp, male;
    studentInfo val;
    initQueue(&temp);
    initQueue(&male);

    while(!isEmpty(*q)){
        val = front(*q);
        dequeue(q);
        if(val.gender == 'M'){
            enqueue(&male, val);
        }else{
            enqueue(&temp, val);
        }
    }

    while(!isEmpty(temp)){
        val = front(temp);
        dequeue(&temp);
        enqueue(q, val);
    }

    return male;
}

Queue get21(Queue *q){
    Queue temp, studs;
    studentInfo val;
    initQueue(&temp);
    initQueue(&studs);

    while(!isEmpty(*q)){
        val = front(*q);
        dequeue(q);
        if(val.age >= 21){
            enqueue(&studs, val);
        }
        enqueue(&temp, val);
    }

    while(!isEmpty(temp)){
        val = front(temp);
        dequeue(&temp);
        enqueue(q, val);
    }

    return studs;

}

void display(Queue q){
    while(q.head!=NULL){
        printf("Name: %s %s\n", q.head->student.name.fName, q.head->student.name.lName);
        printf("Birthdate: %d, %d\n", q.head->student.birthday.month, q.head->student.birthday.year);
        printf("Age: %d\n", q.head->student.age);
        printf("Gender: %c\n", q.head->student.gender);
        printf("ID Number: %d\n", q.head->student.idNum);
        printf("=============================\n\n");
        q.head = q.head->next;
    }
}