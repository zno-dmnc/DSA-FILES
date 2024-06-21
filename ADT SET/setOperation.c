#include <stdio.h>
#include "setOperation.h"

void initSet(Set *s){
    int i;
    for(i=0;i<SIZE;i++){
        s->setA[i] = s->setB[i] = 0;
    }
}
void addElem(Set *s){
    int v, val;

    do{
        printf("How many values to be added for Set A? ");
        scanf("%d", &v);

        for(int i=0; i<v;i++){
            do{
                printf("Enter Value 0-7: ");
                scanf("%d", &val);
            }while(val>=8);

            s->setA[val] = 1;
        }
    }while(v<0&&v>8);


    do{
        printf("How many values to be added for Set B? ");
        scanf("%d", &v);

        for(int i=0; i<v;i++){
            do{
                printf("Enter Value 0-7: ");
                scanf("%d", &val);
            }while(val>=8);

            s->setB[val] = 1;
        }
    }while(v<0&&v>8);

}
void deleteElem(int s[]){
    int v, val;
    do{
        printf("How many values to be deleted for Set B? ");
        scanf("%d", &v);

        for(int i=0; i<v;i++){
            do{
                printf("Enter Value 0-7: ");
                scanf("%d", &val);
            }while(val>=8);

            s[val] = 0;
        }
    }while(v<0&&v>8);
}
void unionIntersection(Set *s){
    Set temp;
    int i;
    initSet(&temp);

    for(i=0;i<SIZE;i++){
        if(s->setA[i] == 1 || s->setB[i] == 1){
            temp.setA[i] = 1;
         }else{ 
            temp.setA[i] = 0;
         }
    }

    for(i=0;i<SIZE;i++){
        if(s->setA[i] == 1 && s->setB[i] == 1){
            temp.setB[i] = 1;
         }else{ 
            temp.setB[i] = 0;
         }
    }

    displayUI(temp);

}
void display(Set s){
    int i;
    printf("SET A - { ");
    for(i=0;i<SIZE;i++){
        if(s.setA[i] == 1){
            printf("%d, ", i);
        }
    }
    printf("}\n");
    
    printf("SET B - { ");
    for(i=0;i<SIZE;i++){
        if(s.setB[i] == 1){
            printf("%d, ", i);
        }
    }
    printf("}\n");
}

void displayUI(Set s){

    int i;
    printf("Union - { ");
    for(i=0;i<SIZE;i++){
        if(s.setA[i] == 1){
            printf("%d, ", i);
        }
    }
    printf("}\n");
    
    printf("Intersection - { ");
    for(i=0;i<SIZE;i++){
        if(s.setB[i] == 1){
            printf("%d, ", i);
        }
    }
    printf("}\n");

}