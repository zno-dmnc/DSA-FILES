#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "STACK_ARRAY.h"

void initStack(StackArrayList *s){
	s->top = -1;
}
StackArrayList createStack(){
	StackArrayList list;
	list.top = -1;
	
	return list;
}

bool stack_push(StackArrayList *s, int elem){
	bool ret = false;
	if(isFull(*s)==false){
		s->data[++s->top] = elem;
		ret = true;
	}
	return ret;
}
bool stack_pop(StackArrayList *s){
	bool ret = false;
	if(isEmpty(*s)==false){
		s->top--;
		ret = true;
	}
	
	return ret;
}
int stack_peek(StackArrayList s){
	return s.data[s.top];
}

void display(StackArrayList s){
	StackArrayList temp = createStack();
	int val;
	
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
void visualize(StackArrayList s){
	
	int i;
	if(isEmpty(s)!=true){
		printf("INDEX\tDATA\n");
		for(i=0;i<=s.top;i++){
			if(i==s.top){
				printf("%d\t%d -> TOP\n", i, s.data[i]);
			}else{
				printf("%d\t%d\n", i, s.data[i]);
			}
		}
	}
	
}

bool isEmpty(StackArrayList s){
	return s.top == -1? true: false;
}
bool isFull(StackArrayList s){
	return s.top==MAX? true: false;
}

// others
//create a function that would get all even numbers and return as a new stack removing from the old stack

StackArrayList removeEvenNumbers(StackArrayList *s){
	
	StackArrayList temp = createStack(), even = createStack();
	int val;
	
	while(!isEmpty(*s)){
		val = stack_peek(*s);
		stack_pop(s);
		val%2==0? stack_push(&even, val): stack_push(&temp, val);
	}
	
	while(!isEmpty(temp)){
		val = stack_peek(temp);
		stack_pop(&temp);
		stack_push(s, val);
	}
	
	return even;

}
