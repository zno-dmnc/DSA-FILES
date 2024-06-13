#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stackDoubly.h"

void initStack(DoublyStack *s){
    s->head = NULL;
    s->tail = NULL;
}
bool stack_push(DoublyStack *s, int elem){
    StackPtr newNode = malloc(sizeof(Stack));
    bool ret = false;
    if(newNode!=NULL){
        newNode->data = elem;
        if(isEmpty(*s)){
            newNode->prev = s->head;
            s->head = newNode;
            newNode->next = s->tail;
        }else{
            newNode->next = s->tail->next;
            s->tail->next = newNode;
            newNode->prev = s->tail;
        }
        s->tail = newNode;
        ret = true;
    }

    return ret;
}
bool stack_pop(DoublyStack *s){

    bool ret = false;

    if(!isEmpty(*s)){
        StackPtr temp = s->tail;
        if(s->head == s->tail){
            s->head = NULL;
            s->tail = NULL;
        }else{
            s->tail->prev->next = s->tail->next;
            s->tail = s->tail->prev;
        }
        free(temp);
        ret = true;
    }

    return ret;

}
int stack_peek(DoublyStack s){
    return s.tail->data;
}
bool isEmpty(DoublyStack s){
    return (s.head == NULL && s.tail == NULL) ? true : false;
}
void display(DoublyStack s){
    DoublyStack temp;
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
void visualize(DoublyStack s){
    printf("HEAD\n");
    printf("%d -> TOP\n", s.tail->data);
    s.tail = s.tail->prev;
    while(s.tail!=NULL){
        printf("%d\n", s.tail->data);
        s.tail = s.tail->prev;
    }
}
//create a function that would get all even numbers and return as a new stack removing from the old stack

DoublyStack removeEvenNumbers(DoublyStack *s){
    DoublyStack temp, even;
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