#ifndef STACK_ARRAY
#define STACK_ARRAY

#include <stdbool.h>

#define MAX 1

typedef struct{
	int data[MAX];
	int top;
}StackArrayList;

void initStack(StackArrayList *s){
	s->top = -1;
}
StackArrayList createStack(){
	StackArrayList *s;
	s->top = -1;
	
	return s;
	
}

bool stack_push(StackArrayList *s, int elem){
	
	if(s->top < MAX -1){
		s->top++;
		s->elem[s->top] = elem;
		
		return true;
	}
	return false;
}
bool stack_pop(StackArrayList *s){
	if(s->top > -1){
		s->top--;
		
		return true;
	}
	
	return false;
}
bool stack_peek(StackArraylist *s){
	
	return (s->top != -1) ? s->data[s->top] : -1;
}

void display(StackArrayList s){
 	if (s.top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.data[i]);
    }
    printf("\n");

}

void visualize(StackArrayList s){

	 printf("Stack Visualization:\n");
    for (int i = MAX - 1; i >= 0; i--) {
        if (i <= s.top) {
            printf("| %4d |", s.data[i]);
            if (i == s.top) {
                printf(" <- Top");
            }
            printf("\n");
        } else {
            printf("|      |\n");
        }
    }
    printf("-------\n");
}
}

bool isEmpty(StackArrayList s){
 	return (s.top == -1);
}

bool isFull(StackArrayList s){
	return (s.top == MAX - 1);
}

StackArrayList EvenNumbers(StackArrayList *s) {
    StackArrayList evenStack;
    initStack(&evenStack);
    
    for (int i = 0; i <= s->top; i++) {
        if (s->data[i] % 2 == 0) {
            stack_push(&evenStack, s->data[i]);
           
            for (int j = i; j < s->top; j++) {
                s->data[j] = s->data[j + 1];
            }
            s->top--;
            i--; 
        }
    }
    
    return evenStack;
}

#endif
