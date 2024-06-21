#ifndef SETARR_H
#define SETARR_H

#include <stdio.h>

#define SIZE 10

typedef struct {
    char data[SIZE];
    int count;
} setArr;

void initialize(setArr *C);
void displaySet(setArr A);
int isInSet(setArr A, char data);
void addElement(setArr *A, char data);
void deleteElement(setArr *A, char data);
setArr unionSet(setArr A, setArr B);
setArr intersectionSet(setArr A, setArr B);

#endif
