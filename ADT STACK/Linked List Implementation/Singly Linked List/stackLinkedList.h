#ifndef stackLinkedList
#define stackLinkedList

#include<stdbool.h>

typedef struct node{
	int data;
	struct node *next;
}Stack, *StackPtr;

void initStack(StackPtr *s);
bool stack_push(StackPtr *s, int elem);
bool stack_pop(StackPtr *s);
int stack_peek(StackPtr s);
bool isEmpty(StackPtr s);
void display(StackPtr s);
void visualize(StackPtr s);

// others
//create a function that would get all even numbers and return as a new stack removing from the old stack

StackPtr removeEvenNumbers(StackPtr *s);


#endif
