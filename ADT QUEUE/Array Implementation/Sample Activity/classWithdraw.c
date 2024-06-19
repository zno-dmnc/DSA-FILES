#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "classWithdraw.h"

void initStack(classStack *s){
    s->top = -1;
}
void initQueue(ReservedQ *q){
    q->front = 1;
    q->rear = 0;
}
bool stack_push(classStack *s, studentInfo stud){
    bool ret = false;
    if(!isFullStack(*s)){
        s->classList[++s->top] = stud;
        ret = true;
    }

    return ret;

}
bool stack_pop(classStack *s){
    bool ret = false;
    if(!isEmptyStack(*s)){
        s->top--;
        ret = true;
    }

    return ret;

}
studentInfo stack_peek(classStack s){
    return s.classList[s.top];
}
bool isEmptyStack(classStack s){
    return (s.top==-1) ? true : false;
}
bool isFullStack(classStack s){
    return (s.top==MAX-1) ? true : false;
}
void displayStack(classStack s){
    classStack temp;
    studentInfo val;
    initStack(&temp);

    while(!isEmptyStack(s)){
        val = stack_peek(s);
        printf("Student Name: %s, %s\n", val.name.lastName, val.name.firstName);
        printf("ID Number: %d\n", val.idNum);
        printf("Gender: %c\n", val.gender);
        printf("Birthday: %d %d\n", val.bdate.month, val.bdate.year);
        printf("Age: %d\n", val.age);
        printf("Year Level: %d\n", val.yrLevel);
        printf("====================\n\n");
        stack_pop(&s);
        stack_push(&temp, val);
    }

    while(!isEmptyStack(temp)){
        val = stack_peek(temp);
        stack_pop(&temp);
        stack_push(&s, val);
    }
    

}
bool enqueue(ReservedQ *q, studentInfo stud){
    bool ret = false;
    if(!isFullQueue(*q)){
        q->rear = (q->rear+1)%MAX;
        q->stud[q->rear] = stud;
        ret = true;
    } else{
        printf("Queue is Full!\n");
    }

    return ret;
}
bool dequeue(ReservedQ *q){
    bool ret = false;
    if(!isEmptyQueue(*q)){
        q->front = (q->front+1)%MAX;
        ret = true;
    }

    return ret;

}
studentInfo front(ReservedQ q){
    return q.stud[q.front];
}
studentInfo rear(ReservedQ q){
    return q.stud[q.rear];
}
bool isEmptyQueue(ReservedQ q){
    return ((q.rear+1)%MAX==q.front) ? true : false;
}

bool isFullQueue(ReservedQ q){
    return ((q.rear+2)%MAX==q.front) ? true : false;
}
void displayQueue(ReservedQ q){
    ReservedQ temp;
    studentInfo val;
    initQueue(&temp);

    while(!isEmptyQueue(q)){
        val = front(q);
        printf("Name: %s %s\n", val.name.firstName, val.name.lastName);
        printf("Birthdate: %d, %d\n", val.bdate.month, val.bdate.year);
        printf("Age: %d\n", val.age);
        printf("Gender: %c\n", val.gender);
        printf("ID Number: %d\n", val.idNum);
        printf("=============================\n\n");
        dequeue(&q);
        enqueue(&temp, val);
    }

    while(!isEmptyQueue(temp)){
        val = front(temp);
        dequeue(&temp);
        enqueue(&q, val);
    }

}

void enroll(studentInfo stud, classStack *s, ReservedQ *q){
    if(!isFullStack(*s)){
        stack_push(s, stud);
        printf("Student Enrolled in Class!\n");
    }else{
        enqueue(q, stud);
        printf("Class is full! Student is waitlisted!\n");
    }
}
void withdraw(int id, classStack *s, ReservedQ *q){
    classStack temp;
    studentInfo val;
    initStack(&temp);

    if(!isEmptyStack(*s)){
        while(!isEmptyStack(*s)){
            val = stack_peek(*s);
            stack_pop(s);
            (val.idNum!=id) ? stack_push(&temp, val) : printf("Student Withdrawn!\n");
            
        }

        while(!isEmptyStack(temp)){
            val = stack_peek(temp);
            stack_pop(&temp);
            stack_push(s, val);
        }

        if(!isEmptyQueue(*q)){
            val = front(*q);
            dequeue(q);
            stack_push(s, val);
        }
    }

    

}

