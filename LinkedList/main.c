#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    char name[20];
    int idNum;
    int age;
} info;

typedef struct node {
    info data;
    struct node* next;
} node, *nodePtr;

void initialize(nodePtr *L);
void insertFirst(nodePtr *L, info data);
void insertLast(nodePtr *L, info data);
void insertAtIndex(nodePtr *L, info data, int index);
void displayFirst(nodePtr L);

int main() {
    nodePtr L;
    initialize(&L);

    info data[4] = {
        {"Murliwani", 18103367, 25},
        {"Luke", 18103668, 23},
        {"CJ", 18103660, 25},
        {"Arden", 18103669, 22}
    };

    for(int i = 0; i < 4; i++){
        insertFirst(&L, data[i]);
    }

    displayFirst(L);
    
     printf("Inserting at the last position:\n");
    insertLast(&L, (info){"NewLast", 18103770, 24});
    displayFirst(L);

    printf("Inserting at index 2:\n");
    insertAtIndex(&L, (info){"Index2", 18103880, 26}, 2);
    displayFirst(L);

    return 0;
}

void initialize(nodePtr *L) {
    *L = NULL;
}

void insertFirst(nodePtr *L, info data) {
    nodePtr newnode = (nodePtr)malloc(sizeof(node));

    if (newnode != NULL) {
        newnode->data = data;
        newnode->next = *L;
        *L = newnode;
    } 
}
void insertLast(nodePtr *L, info data) {
    nodePtr newnode = (nodePtr)malloc(sizeof(node));

    if (newnode != NULL) {
        newnode->data = data;
        newnode->next = NULL;

        if (*L == NULL) {
            *L = newnode;
        } else {
            nodePtr current = *L;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newnode;
        }
    } 
}

void insertAtIndex(nodePtr *L, info data, int index) {

    nodePtr newnode = (nodePtr)malloc(sizeof(node));

    if (newnode != NULL) {
        newnode->data = data;
        newnode->next = NULL;

        if (index == 0) {
            newnode->next = *L;
            *L = newnode;
        } else {
            nodePtr current = *L;
            for (int i = 0; i < index - 1; i++) {
                if (current == NULL) {
                    free(newnode);
                    return;
                }
                current = current->next;
            }
            if (current == NULL) {
                free(newnode);
            } else {
                newnode->next = current->next;
                current->next = newnode;
            }
        }
    } 
}

void displayFirst(nodePtr L) {
    nodePtr current = L;
    while (current != NULL) {
        printf("Name: %s\n", current->data.name);
        printf("ID Number: %d\n", current->data.idNum);
        printf("Age: %d\n", current->data.age);
        printf("\n");
        current = current->next;
    }
}
