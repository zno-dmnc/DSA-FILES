#ifndef OPEN_DICT
#define OPEN_DICT
#include <stdbool.h>

#define THRESHOLD 0.65

typedef struct {
    char fName[20];
    char lName[20];
}Name;

typedef struct {
    char street[30];
    char barangay[20];
    char city[20];
    char province[20];
    int zipCode;
}Address;

typedef struct {
    Name name;
    Address address;
}Person;

typedef struct node{
    Person p;
    struct node *next;
}Node, *NodePtr;

typedef struct {
    NodePtr *List;
    int size;
    int count;
}Dictionary;

typedef struct{
    NodePtr front;
    NodePtr rear;
}Queue;

Dictionary createOpenDict();
int hashFunction(char *key, int size);
void insertOpenDict(Dictionary *d, Queue *acl, Person p);
bool searchOpenDict(Dictionary d, Name n);
void updateOpenDict(Dictionary *d, Name n, Person p);
void updateName(Dictionary *d, Queue *acl, Name n, Person p);
void deleteOpenDict(Dictionary *d, Queue *acl, Name n);
void visualize(Dictionary d);
void resizeDictionary(Dictionary *d, Queue *acl);
void initQueue(Queue *q);
void enqueue(Queue *q, Person p);
void dequeue(Queue *q);
Person front(Queue q);
bool isEmpty(Queue q);

#endif