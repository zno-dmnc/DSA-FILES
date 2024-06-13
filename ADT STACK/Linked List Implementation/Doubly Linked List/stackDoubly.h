#ifndef stackDoubly
#define stackDoubly

#include<stdbool.h>

typedef struct node{
	int data;
    struct node *prev;
	struct node *next;
}Stack, *StackPtr;

typedef struct {
    StackPtr head;
    StackPtr tail;
} DoublyStack;

void initStack(DoublyStack *s);
bool stack_push(DoublyStack *s, int elem);
bool stack_pop(DoublyStack *s);
int stack_peek(DoublyStack s);
bool isEmpty(DoublyStack s);
void display(DoublyStack s);
void visualize(DoublyStack s);

// others
//create a function that would get all even numbers and return as a new stack removing from the old stack

DoublyStack removeEvenNumbers(DoublyStack *s);


#endif
