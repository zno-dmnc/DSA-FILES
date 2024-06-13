#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackLinkedList.h"

void initStack(StackPtr *s){
    *s = NULL;
}
bool stack_push(StackPtr *s, int elem){
    StackPtr temp = malloc(sizeof(Stack));
    bool ret = false;

    if(temp!=NULL){
        temp->data = elem;
        temp->next = *s;
        *s = temp;
        ret = true;
    }

    return ret;
}
bool stack_pop(StackPtr *s){
    StackPtr temp = *s;
    bool ret = false;

    if(!isEmpty(*s)){
        *s = (*s)->next;
        free(temp);
        ret = true;
    }

    return ret;
}
int stack_peek(StackPtr s){
    return s->data;
}
bool isEmpty(StackPtr s){
    return s==NULL ? true : false;
}
void display(StackPtr s){
    StackPtr temp;
    int val;
    initStack(&temp);

    while(!isEmpty(s)){
        val = stack_peek(s);
        printf("%d - ", val);
        stack_pop(&s);
        stack_push(&temp, val);
    }

    while(!isEmpty(temp)){
        val = stack_peek(temp);
        stack_pop(&temp);
        stack_push(&s, val);
    }
}
void visualize(StackPtr s){
    printf("HEAD\n");
    printf("%d -> TOP\n", s->data);
    s = s->next;
    while(s!=NULL){
        printf("%d\n", s->data);
        s = s->next;
    }
}

// others
//create a function that would get all even numbers and return as a new stack removing from the old stack

StackPtr removeEvenNumbers(StackPtr *s){
    StackPtr temp, even;
    initStack(&temp);
    initStack(&even);
    int val;

    while(!isEmpty(*s)){
        val = stack_peek(*s);
        stack_pop(s);
        val%2==0 ? stack_push(&even, val): stack_push(&temp, val);
    }

    while(!isEmpty(temp)){
        val = stack_peek(temp);
        stack_pop(&temp);
        stack_push(s, val);
    }

    return even;
}