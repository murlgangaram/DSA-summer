#ifndef STACK_ARRAY
#define STACK_ARRAY

#include <stdbool.h>
#include <stdio.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int top;
} StackArrayList;

void initStack(StackArrayList *s);

bool stack_push(StackArrayList *s, int elem);   
bool stack_pop(StackArrayList *s);
int stack_peek(StackArrayList *s);
void display(StackArrayList s);
void visualize(StackArrayList s); 
bool isEmpty(StackArrayList s);
bool isFull(StackArrayList s); 
StackArrayList EvenNumbers(StackArrayList *s);
initStack(&evenStack);


#endif