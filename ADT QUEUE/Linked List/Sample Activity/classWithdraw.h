#ifndef classWithdraw
#define classWithdraw

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct{
    char firstName[20];
    char lastName[20];
}Name;

typedef struct{
    int month;
    int year;
}Birthdate;

typedef struct{
    Name name;
    Birthdate bdate;
    int age;
    int idNum;
    char gender;
    int yrLevel;
}studentInfo;

typedef struct{
    studentInfo classList[MAX];
    int top;
}classStack;

typedef struct node{
    studentInfo stud;
    struct node *next;
}Node, *nodePtr;

typedef struct{
    nodePtr head;
    nodePtr tail;
}reserveQueue;

void initStack(classStack *s);
void initQueue(reserveQueue *q);
bool stack_push(classStack *s, studentInfo stud);
bool stack_pop(classStack *s);
studentInfo stack_peek(classStack s);
bool isEmptyStack(classStack s);
bool isFullStack(classStack s);
void displayStack(classStack s);
bool enqueue(reserveQueue *q, studentInfo stud);
bool dequeue(reserveQueue *q);
studentInfo front(reserveQueue q);
studentInfo rear(reserveQueue q);
bool isEmptyQueue(reserveQueue q);
void displayQueue(reserveQueue q);
void enroll(studentInfo stud, classStack *s, reserveQueue *q);
void withdraw(int id, classStack *s, reserveQueue *q);


#endif