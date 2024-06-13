#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node, *nodePtr;

void insertFront (nodePtr *list, int newData);
void deleteStud (nodePtr *list, int id);
void deleteAt (nodePtr *list, int pos);
void displayList (nodePtr list);

int main(){
    
    nodePtr head = NULL;
    
    insertFront(&head, 5);
    insertFront(&head, 4);
    insertFront(&head, 3);
    insertFront(&head, 2);
    insertFront(&head, 1);

    displayList(head);
    deleteStud(&head, 3);
    printf("\n\n");
    displayList(head);
    deleteAt(&head, 2);
    printf("\n\n");
    displayList(head);

    return 0;
}

void insertFront(nodePtr *list, int id){
    nodePtr newD = malloc(sizeof(Node));
    
    if(newD!=NULL){
        newD->data = id;
        newD->next = *list;
        *list = newD;
    }
}

void deleteStud (nodePtr *list, int id){
	nodePtr temp;
	
	while((*list)->next!=NULL && (*list)->data != id){
		list = &(*list)->next;
	}
	if((*list)->next!=NULL){
		temp = *list;
		*list = temp->next;
		free(temp);
	}
}
void deleteAt (nodePtr *list, int pos){

    
	nodePtr *trav = list, temp;
	int i=0;
	
	while((*trav)->next!=NULL && i!=pos){
		trav = &(*trav)->next;
        i++;
	}
	temp = *trav;
	*trav = temp->next;
	free(temp);
}
void displayList (nodePtr list){
	
	
	while(list!=NULL){
		printf("%d\t", list->data);
		list = list->next;
	}
	
}