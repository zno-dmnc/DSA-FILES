#ifndef SET_OPERATION
#define SET_OPERATION

#define SIZE 8
typedef struct{
    int setA[SIZE];
    int setB[SIZE];
}Set;

void initSet(Set *s);
void addElem(Set *s);
void deleteElem(int s[]);
void unionIntersection(Set *s);
void display(Set s);
void displayUI(Set s);

#endif