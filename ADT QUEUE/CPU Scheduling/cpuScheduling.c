#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cpuScheduling.h"

void initQueue(Queue* q){
    q->front = NULL;
    q->rear = NULL;
}
void enqueue(Queue* q, Process p){
    NodePtr new = malloc(sizeof(struct node));
    if(new!=NULL){
        new->p = p;
        new->next = NULL;

        if(isEmpty(*q)){
            q->front = new;
        }else{
            q->rear->next = new;
        }
        q->rear = new;
    }
}
void dequeue(Queue* q){
    NodePtr temp;
    if(!isEmpty(*q)){
        temp = q->front;
        if(q->front->next==NULL){
            q->rear = NULL;
        }
        q->front = q->front->next;
        free(temp);
    }

}
bool isEmpty(Queue q){
    return (q.front==NULL) ? true : false;
}
Process front(Queue q){
    return q.front->p;
}
void displayProcess(Queue q){
    Queue temp;
    Process val;

    initQueue(&temp);
    printf("===FIRST COME FIRST SERVE CPU SCHEDULING===\n\n");
    printf("PROCESS\tAT\tBT\tET\tCT\tWT\tTT\n");
    
    while(!isEmpty(q)){
        val = front(q);
        printf("%c\t%d\t%d\t%d\t%d\t%d\t%d\n", val.name, val.arrivalTime, val.burstTime, val.executionTime, val.completionTime, val.waitingTime, val.turnaroundTime);
        dequeue(&q);
        enqueue(&temp, val);
    }

    while (!isEmpty(temp))
    {
        val = front(temp);
        dequeue(&temp);
        enqueue(&q, val);
    }

}
void insertSorted(NodePtr *h, Process p){
    while(*h!=NULL && (*h)->p.arrivalTime<=p.arrivalTime){
        h = &(*h)->next;
    }

    NodePtr new = malloc(sizeof(struct node));
    if(new!=NULL){
        new->p = p;
        new->next = *h;
        *h = new;
    }

}
void populateQueue(Queue* q, NodePtr h){
    while(h!=NULL){
        enqueue(q, h->p);
        h = h->next;
    }
}
void fcfs(Queue* q){
    Queue temp;

    initQueue(&temp);

    Process val = front(*q);
    int ct = val.arrivalTime+val.burstTime;
    val.completionTime = ct;
    val.executionTime = val.arrivalTime;
    val.turnaroundTime = ct-val.arrivalTime;
    val.waitingTime = val.turnaroundTime - val.burstTime;
    dequeue(q);
    enqueue(&temp, val);
    while(!isEmpty(*q)){
        val = front(*q);
        if(val.arrivalTime>ct){
            val.executionTime = val.arrivalTime;
            ct = val.arrivalTime+val.burstTime;
        }
        else{
            val.executionTime = ct;
            ct = ct+val.burstTime;
        }
        val.completionTime = ct;
        val.turnaroundTime = ct-val.arrivalTime;
        val.waitingTime = val.turnaroundTime - val.burstTime;
        dequeue(q);
        enqueue(&temp, val);
    }

    while(!isEmpty(temp)){
        val = front(temp);
        dequeue(&temp);
        enqueue(q, val);
    }
}
void ganttChart(Queue q){
    Queue temp;
    initQueue(&temp);

    Process val = front(q), tempv;
    printf("\n====GANTT CHART====\n");
    printf("%d\t", val.arrivalTime);
    dequeue(&q);
    enqueue(&temp, val);
    printf(" \t%d\t", val.completionTime);
    while(!isEmpty(q)){
        tempv = front(q);
        if(val.completionTime==tempv.executionTime){
            printf(" \t%d\t", tempv.completionTime);
        } else{
            printf("\t%d\t \t%d\t", tempv.executionTime, tempv.completionTime);
        }
        dequeue(&q);
        enqueue(&temp, tempv);
        val = tempv;
    }

    while(!isEmpty(temp)){
        tempv = front(temp);
        dequeue(&temp);
        enqueue(&q, tempv);
    }

    gui(q);
}

void gui(Queue q){
    Queue temp;
    initQueue(&temp);

    Process val = front(q), tempv;
    printf("\n|\t");
    dequeue(&q);
    enqueue(&temp, val);
    printf("%c\t|\t", val.name);
    while(!isEmpty(q)){
        tempv = front(q);
        if(val.completionTime==tempv.executionTime){
            printf("%c\t|\t", tempv.name);
        } else{
            printf("(idle)\t|\t%c\t|\t", tempv.name);
        }
        dequeue(&q);
        enqueue(&temp, tempv);
        val = tempv;
    }

    while(!isEmpty(temp)){
        tempv = front(temp);
        dequeue(&temp);
        enqueue(&q, tempv);
    }
}