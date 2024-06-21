#include <stdio.h>
#include "setArr.h"

int main() {
    setArr A = {{'a', 'b', 'c'}, 3};
    setArr B = {{'b', 'c', 'd', 'e', 'f'}, 5};

    printf("Set A:\n");
    displaySet(A);
    
    printf("\nSet B:\n");
    displaySet(B);


    setArr U = unionSet(A, B);
    printf("\nUnion Set:\n");
    displaySet(U);

    setArr I = intersectionSet(A, B);
    printf("\nIntersection Set:\n");
    displaySet(I);

    return 0;
}
