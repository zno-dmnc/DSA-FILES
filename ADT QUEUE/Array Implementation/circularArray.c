#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "circularArray.h"

void initCircular(CircularQ *q){
    q->front = 1;
    q->rear = 0;
}
bool enqueue (CircularQ *q, studentInfo newStud){
    bool ret = false;
    if(!isFull(*q)){
        q->rear = (q->rear+1)%MAX;
        q->stud[q->rear] = newStud;
        ret = true;
    } else{
        printf("Queue is Full!\n");
    }

    return ret;

}
bool dequeue (CircularQ *q){
    if(!isEmpty(*q)){
        q->front = (q->front+1)%MAX;
    }
}
studentInfo front(CircularQ q){
    return q.stud[q.front];
}
studentInfo rear(CircularQ q){
    return q.stud[q.rear];
}
bool isEmpty (CircularQ q){
    return ((q.rear+1)%MAX==q.front) ? true : false;
}
bool isFull(CircularQ q){
    return ((q.rear+2)%MAX==q.front) ? true : false;
}
void display(CircularQ q){
    CircularQ temp;
    studentInfo val;
    initCircular(&temp);

    while(!isEmpty(q)){
        val = front(q);
        printf("Name: %s %s\n", val.name.fName, val.name.lName);
        printf("Birthdate: %d, %d\n", val.birthday.month, val.birthday.year);
        printf("Age: %d\n", val.age);
        printf("Gender: %c\n", val.gender);
        printf("ID Number: %d\n", val.idNum);
        printf("=============================\n\n");
        dequeue(&q);
        enqueue(&temp, val);
    }

    while(!isEmpty(temp)){
        val = front(temp);
        dequeue(&temp);
        enqueue(&q, val);
    }

}