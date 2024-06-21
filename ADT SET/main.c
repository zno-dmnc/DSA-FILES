#include <stdio.h>
#include "setOperation.h"
#include "setOperation.c"

int main(){

    Set s;
    initSet(&s);
    int input;
    char v;
    do{
        display(s);
        printf("1. Add Elements\n");
        printf("2. Delete Elements\n");
        printf("3. Display Union and Intersection\n");
        printf("Input: ");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            addElem(&s);
            break;
        case 2:
            printf("From which set will you delete values? (A/B)");
            scanf("%c", &v);
            (v == 'A'||v == 'a') ? deleteElem(s.setA) : deleteElem(s.setB);
            break;
        case 3:
            unionIntersection(&s);
            break;
        
        default:
            break;
        }

    }while(input!=0);
    return 0;
}