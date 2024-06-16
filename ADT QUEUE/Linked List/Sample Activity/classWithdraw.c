#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "classWithdraw.h"

void initStack(classStack *s){
    s->top = -1;
}
void initQueue(reserveQueue *q){
    q->head = NULL;
    q->tail = NULL;
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
bool enqueue(reserveQueue *q, studentInfo stud){
    bool ret = false;

    nodePtr newStud = malloc(sizeof(Node));
    if(newStud!=NULL){
        newStud->stud = stud;
        newStud->next = NULL;
        if(q->head==NULL){
            q->head = newStud;
        }else{
            q->tail->next = newStud;
        }
        q->tail = newStud;
        ret = true;
    }

    return ret;
}
bool dequeue(reserveQueue *q){
    bool ret = false;
    nodePtr temp;
    
    if(!isEmptyQueue(*q)){
        temp = q->head;
        if(q->head->next==NULL){
            q->tail = NULL;
        }
        q->head = q->head->next;
        free(temp);
        ret = true;
    }

    return ret;

}
studentInfo front(reserveQueue q){
    return q.head->stud;
}
studentInfo rear(reserveQueue q){
    return q.tail->stud;
}
bool isEmptyQueue(reserveQueue q){
    return (q.head==NULL) ? true : false;

}
void displayQueue(reserveQueue q){
    printf("Queued Reserved Students:\n");
    while(q.head!=NULL){
        printf("Student Name: %s, %s\n", q.head->stud.name.lastName, q.head->stud.name.firstName);
        printf("ID Number: %d\n", q.head->stud.idNum);
        printf("Gender: %c\n", q.head->stud.gender);
        printf("Birthday: %d %d\n", q.head->stud.bdate.month, q.head->stud.bdate.year);
        printf("Age: %d\n", q.head->stud.age);
        printf("Year Level: %d\n", q.head->stud.yrLevel);
        printf("====================\n\n");
        q.head = q.head->next;
    }

}

void enroll(studentInfo stud, classStack *s, reserveQueue *q){
    if(!isFullStack(*s)){
        stack_push(s, stud);
        printf("Student Enrolled in Class!\n");
    }else{
        enqueue(q, stud);
        printf("Class is full! Student is waitlisted!\n");
    }
}
void withdraw(int id, classStack *s, reserveQueue *q){
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

