#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
	int day, month, year;
}Date;

typedef struct{
	char prodName[20];
	float prodPrice;
	int prodQty;
	Date expDate;
}Product;
typedef struct node{
    Product data;
    struct node* left;
    struct node* right;
} *BST, Tree;

typedef struct nodeQ{
	BST n;
	struct nodeQ *next;
}*NodePtr;

typedef struct{
	NodePtr front;
	NodePtr rear;
}Queue;

void initialize(BST *t){
    *t = NULL;
}

void insert(BST *t, Product data){
    if(*t == NULL){
        *t = (BST)malloc(sizeof(Tree));
        (*t)->data = data;
        (*t)->left = NULL;
        (*t)->right = NULL;
    } else if((strcmp((*t)->data.prodName, data.prodName)>0)) 
        insert(&(*t)->left, data);
            else if((strcmp((*t)->data.prodName, data.prodName)<0)) 
                insert(&(*t)->right, data);
}

bool isMember(BST *t, Product data){
	bool ret = false;

	if(*t!=NULL){
		if(strcmp((*t)->data.prodName, data.prodName)==0){
			ret = true;
		}else if(strcmp((*t)->data.prodName, data.prodName)>0){
			ret = isMember(&(*t)->left, data);
		}else if(strcmp((*t)->data.prodName, data.prodName)<0){
			ret = isMember(&(*t)->right, data);
		}

	}

	return ret;
}

void deleteTree(BST *t, Product data){
	Tree *temp, **trav, *temp1;
	if(*t!=NULL){
		if((strcmp((*t)->data.prodName, data.prodName)==0)){
			temp = *t;
			if((*t)->left!=NULL){
				trav = &(*t)->left;
				while(((*trav)->right!=NULL)){
					trav = &(*trav)->right;				
				}
				temp1 = *trav;
				*trav = temp1->left;
				temp1->left = (*t)->left;
				temp1->right = (*t)->right;
				*t = temp1;
				free(temp);
			}else if ((*t)->right!=NULL){
				trav = &(*t)->right;
				while(((*trav)->left!=NULL)){
					trav = &(*trav)->left;					
				}
				temp1 = *trav;
				*trav = temp1->right;
				temp1->left = (*t)->left;
				temp1->right = (*t)->right;
				*t = temp1;
				free(temp);
			}else{
				*t = NULL;
				free(temp);
			}
		}else if((strcmp((*t)->data.prodName, data.prodName)>0)){
			deleteTree(&(*t)->left, data);
		}
		else if((strcmp((*t)->data.prodName, data.prodName)<0)){
			deleteTree(&(*t)->right, data);
		}
	}
}


void initQueue(Queue *q){
	q->front = NULL;
	q->rear = NULL;

}
bool isEmpty(Queue q){
	return (q.front==NULL) ? true : false;
}
void enqueue(Queue *q, BST Data){
	NodePtr newP = malloc(sizeof(struct nodeQ));
	if(newP!=NULL){
		newP->n = Data;
		newP->next = NULL;
		if(isEmpty(*q)){
			q->front = newP;
		}else{
			q->rear->next = newP;
		}
		q->rear = newP;
	}

}
void dequeue(Queue*q){
	if(!isEmpty(*q)){
		NodePtr temp;
		temp = q->front;
		if(q->front->next == NULL){
			q->rear = NULL;
		}
		q->front = temp->next;
		free(temp);
	}

}
BST front(Queue q){
	return q.front->n;
}

void bfs(BST t){
	if(t!=NULL){
		Queue q;
		initQueue(&q);
		BST s;
		enqueue(&q, t);
		while(!isEmpty(q)){
			s = front(q);
			printf("Name: %s\n", s->data.prodName);
			printf("Price: %.2f\n", s->data.prodPrice);
			printf("Quantity: %d\n", s->data.prodQty);
			printf("Expiry Date: %d - %d - %d\n\n", s->data.expDate.month, s->data.expDate.day, s->data.expDate.year);
			dequeue(&q);

			if(s->left!=NULL){
				enqueue(&q, s->left);
			}
			if(s->right!=NULL){
				enqueue(&q, s->right);
			}
		}
	}
	
}


void traverse(BST t){
    if(t != NULL){
        
        
        traverse(t->left);
        printf("Name: %s\n", t->data.prodName);
        printf("Price: %.2f\n", t->data.prodPrice);
        printf("Quantity: %d\n", t->data.prodQty);
        printf("Expiry Date: %d - %d - %d\n\n", t->data.expDate.month, t->data.expDate.day, t->data.expDate.year);
        traverse(t->right);
        //inorder traversal

        // printf("%d\n", t->data);
        // traverse(t->left);
        // traverse(t->right);
        //preorder traversal
        
        // traverse(t->left);
        // traverse(t->right);
        // printf("%d\n", t->data);
        //postorder traversal
    }
}

int main(){
    BST tree;

    printf("Recursive Functions - Insertion, Traversal, isMember\n");

    initialize(&tree);
	Product p1;
	strcpy(p1.prodName, "CreamStick");
	p1.prodPrice = 27.5;
	p1.prodQty = 2;
	p1.expDate.month = 3;
	p1.expDate.day = 21;
	p1.expDate.year = 2024;
	
	Product p2;
	strcpy(p2.prodName, "Skyflakes");
	p2.prodPrice = 27.5;
	p2.prodQty = 2;
	p2.expDate.month = 3;
	p2.expDate.day = 21;
	p2.expDate.year = 2024;
	
	Product p3;
	strcpy(p3.prodName, "Banana");
	p3.prodPrice = 27.5;
	p3.prodQty = 2;
	p3.expDate.month = 3;
	p3.expDate.day = 21;
	p3.expDate.year = 2024;
	
	Product p4;
	strcpy(p4.prodName, "Butong");
	p4.prodPrice = 27.5;
	p4.prodQty = 2;
	p4.expDate.month = 3;
	p4.expDate.day = 21;
	p4.expDate.year = 2024;

    insert(&tree, p1);
    insert(&tree, p2);
    insert(&tree, p3);
    insert(&tree, p4); 

    printf("Traversing:\n");
	bfs(tree);
    printf("Checking if CreamStick is a member:\n");
    if(isMember(&tree, p1)){
		printf("True\n");
	}else{
		printf("False\n");
	}
    
	if(isMember(&tree, p2)){
		deleteTree(&tree, p2);
	}else{
		printf("Person not found!\n");
	}
	bfs(tree);
    // traverse(tree);
    
    

    return 0;
}
