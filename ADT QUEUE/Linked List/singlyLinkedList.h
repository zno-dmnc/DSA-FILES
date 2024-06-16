#ifndef singlyLinkedList
#define singlyLinkedList

#include<stdbool.h>

typedef struct {
	char fName[20];
	char lName[20];
}studName;

typedef struct{
	int month;
	int year;
}bDay;

typedef struct{
	studName name;
	bDay birthday;
    char gender;
	int age;
	int idNum;
}studentInfo;

typedef struct node{
	studentInfo student;
	struct node *next;
}classRecord, *classRecordPtr;

typedef struct{
    classRecordPtr head;
    classRecordPtr tail;
}Queue;

void initQueue(Queue *q);
bool enqueue(Queue *q, studentInfo newStud);
bool dequeue(Queue *q);
studentInfo front(Queue q);
studentInfo rear(Queue q);
bool isEmpty(Queue q);
Queue allMale(Queue *q);
Queue get21(Queue *q);
void display(Queue q);

#endif