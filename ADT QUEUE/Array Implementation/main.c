#include <stdio.h>
#include <stdbool.h>

#include "circularArray.h"
#include "circularArray.c"

int main(){

    CircularQ q;
    studentInfo stud = {{"Zenno", "Abellana"}, {5, 2001}, 'M', 23, 21104304};
    studentInfo stud1 = {{"Leighanne", "Abellana"}, {8, 2001}, 'F', 23, 20102624};
    studentInfo stud2 = {{"Jethro", "Engutan"}, {9, 2003}, 'M', 21, 21231421};
    studentInfo stud3 = {{"Kaelle", "Gravador"}, {4, 2003}, 'F', 19, 21321341};
    studentInfo stud4 = {{"Mallen", "Jugalbot"}, {9, 2004}, 'M', 20, 21231421};
    studentInfo stud5 = {{"Stella", "TheGreat"}, {9, 2003}, 'F', 24, 21231421};
    initCircular(&q);

    enqueue(&q, stud);
    enqueue(&q, stud1);
    enqueue(&q, stud2);
    enqueue(&q, stud3);
    enqueue(&q, stud4);
    enqueue(&q, stud5);
    display(q);

    // printf("DEQUEUED\n");
    // dequeue(&q);
    // display(q);
}