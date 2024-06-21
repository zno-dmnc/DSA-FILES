#ifndef CPU_SCHEDULING_H
#define CPU_SCHEDULING_H

#include <stdbool.h>

typedef struct {
    char name;
    int arrivalTime;
    int burstTime;
    int executionTime;
    int turnaroundTime;
    int waitingTime;
    int completionTime;
}Process;

typedef struct node{
    Process p;
    struct node* next;
}*NodePtr;

typedef struct {
    NodePtr front;
    NodePtr rear;
}Queue;

void initQueue(Queue* q);
void enqueue(Queue* q, Process p);
void dequeue(Queue* q);
bool isEmpty(Queue q);
Process front(Queue q);
void displayProcess(Queue q);
void insertSorted(NodePtr *h, Process p);
void populateQueue(Queue* q, NodePtr h);
void fcfs(Queue* q);
void display(NodePtr p);
void ganttChart(Queue q);
void gui(Queue q);


#endif