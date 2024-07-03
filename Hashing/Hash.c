#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Hash.h"

#define MAX 10

void initDictionary(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        D[i] = NULL;
    }
}

int hash(studentName name) {
    return name.MI % MAX;
}

void insertSortedByName(Dictionary D, studentInfo info) {
    int hashVal = hash(info.name);
    student *trav = &D[hashVal];

    while (*trav != NULL && 
           (strcmp((*trav)->info.name.LN, info.name.LN) < 0 || 
           (strcmp((*trav)->info.name.LN, info.name.LN) == 0 && strcmp((*trav)->info.name.FN, info.name.FN) < 0) || 
           (strcmp((*trav)->info.name.LN, info.name.LN) == 0 && strcmp((*trav)->info.name.FN, info.name.FN) == 0 && (*trav)->info.name.MI < info.name.MI))) {
        trav = &(*trav)->next;
    }

    if (*trav == NULL || 
        strcmp((*trav)->info.name.LN, info.name.LN) != 0 || 
        strcmp((*trav)->info.name.FN, info.name.FN) != 0 || 
        (*trav)->info.name.MI != info.name.MI) {
        student temp = (student)malloc(sizeof(struct node));
        if (temp != NULL) {
            temp->info = info;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

void deleteStudentInfo(Dictionary D, studentInfo info) {
    int hashVal = hash(info.name);
    student *trav = &D[hashVal];
    for (; *trav != NULL && (strcmp((*trav)->info.name.LN, info.name.LN) != 0 ||
                             strcmp((*trav)->info.name.FN, info.name.FN) != 0 ||
                             (*trav)->info.name.MI != info.name.MI);
         trav = &(*trav)->next) {}
    if (*trav != NULL) {
        student temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

void visualize(Dictionary D) {
    printf("%-10s %-10s\n", "INDEX", "INFO");
    for (int i = 0; i < MAX; i++) {
        printf("%-10d", i);
        if (D[i] == NULL) {
            printf("%-10s");
        } else {
            for (student trav = D[i]; trav != NULL; trav = trav->next) {
                printf("%s, %s %c | %s | %s", trav->info.name.LN, trav->info.name.FN, trav->info.name.MI, trav->info.year, trav->info.course);
                if (trav->next != NULL) {
                    printf(" --> ");
                }
            }
        }
        printf("\n");
    }
}
