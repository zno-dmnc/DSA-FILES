#include <stdio.h>
#include <stdlib.h>

#include "stackDoubly.h"
#include "stackDoubly.c"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	DoublyStack list, even;
	
	initStack(&list);
	
	stack_push(&list, 1);
	stack_push(&list, 2);
	stack_push(&list, 3);
	stack_push(&list, 4);
	stack_push(&list, 5);
	display(list);
	printf("\n\n");
	visualize(list);
	even = removeEvenNumbers(&list);
	printf("\nEVEN: ");
	display(even);
	printf("\nNEW LIST: ");
	display(list);
	return 0;
}
