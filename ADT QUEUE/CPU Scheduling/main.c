#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "cpuScheduling.h"
#include "cpuScheduling.c"


int main(){
    NodePtr head = NULL;
    Queue q;
    Process p;
    int input, j;
    initQueue(&q);

    printf("How many processes to input?\n");
    scanf("%d", &input);

    for(int i=0, j = 65;i<input;i++, j++){
        printf("AT: ");
        scanf("%d", &p.arrivalTime);
        printf("BT: ");
        scanf("%d", &p.burstTime);
        p.name = j;
        insertSorted(&head, p);
        system("pause");
        system("cls");
    }
    populateQueue(&q, head);
    fcfs(&q);
    displayProcess(q);
    // ganttChart(q);

}