#include <stdio.h>
#include "setArr.h"

void initialize(setArr *C) {
    C->count = 0;
}

void displaySet(setArr A) {
    for (int i = 0; i < A.count; i++) {
        printf("%c ", A.data[i]);
    }
    printf("\n");
}

int isInSet(setArr A, char data) {
    for (int i = 0; i < A.count; i++) {
        if (A.data[i] == data) {
            return 1;
        }
    }
    return 0;
}

void addElement(setArr *A, char data) {
    if (A->count < SIZE && !isInSet(*A, data)) {
        A->data[A->count++] = data;
    }
}

void deleteElement(setArr *A, char data) {
    int found = 0;
    for (int i = 0; i < A->count; i++) {
        if (A->data[i] == data) {
            found = 1;
        }
        if (found && i < A->count - 1) {
            A->data[i] = A->data[i + 1];
        }
    }
    if (found) {
        A->count--;
    }
}

setArr unionSet(setArr A, setArr B) {
    setArr C;
    initialize(&C);

    int a = 0, b = 0;
    while (a < A.count && b < B.count) {
        if (A.data[a] < B.data[b]) {
            addElement(&C, A.data[a++]);
        } else if (A.data[a] > B.data[b]) {
            addElement(&C, B.data[b++]);
        } else {
            addElement(&C, A.data[a++]);
            b++;
        }
    }

    while (a < A.count) {
        addElement(&C, A.data[a++]);
    }

    while (b < B.count) {
        addElement(&C, B.data[b++]);
    }

    return C;
}

setArr intersectionSet(setArr A, setArr B) {
    setArr C;
    initialize(&C);

    for (int a = 0; a < A.count; a++) {
        if (isInSet(B, A.data[a])) {
            addElement(&C, A.data[a]);
        }
    }

    return C;
}

