#ifndef circularArray
#define circularArray

#define MAX 4
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

typedef struct{
    studentInfo stud[MAX];
    int front;
    int rear;
}CircularQ;

void initCircular(CircularQ *q);
bool enqueue (CircularQ *q, studentInfo newStud);
bool dequeue (CircularQ *q);
studentInfo front(CircularQ q);
studentInfo rear(CircularQ q);
bool isEmpty (CircularQ q);
bool isFull(CircularQ q);
void display(CircularQ q);





#endif