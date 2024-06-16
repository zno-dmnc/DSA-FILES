#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "singlyLinkedList.h"
#include "singlyLinkedList.c"

int main(){

    Queue q, male, all21;
    studentInfo stud = {{"Zenno", "Abellana"}, {5, 2001}, 'M', 23, 21104304};
    studentInfo stud1 = {{"Leighanne", "Abellana"}, {8, 2001}, 'F', 23, 20102624};
    studentInfo stud2 = {{"Jethro", "Engutan"}, {9, 2003}, 'M', 21, 21231421};
    studentInfo stud3 = {{"Kaelle", "Gravador"}, {4, 2003}, 'F', 19, 21321341};
    studentInfo stud4 = {{"Mallen", "Jugalbot"}, {9, 2004}, 'M', 20, 21231421};
    studentInfo stud5 = {{"Stella", "TheGreat"}, {9, 2003}, 'F', 24, 21231421};
    initQueue(&q);
    initQueue(&male);
    initQueue(&all21);

    enqueue(&q, stud);
    enqueue(&q, stud1);
    enqueue(&q, stud2);
    enqueue(&q, stud3);
    enqueue(&q, stud4);
    enqueue(&q, stud5);
    display(q);

    all21 = get21(&q);
    printf("All students who are 21 and above:\n");
    display(all21);

    // male = allMale(&q);
    // printf("All Male:\n");
    // display(male);

    
    return 0;
}
