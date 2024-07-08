#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char prodName[20];
    float prodPrice;
    int prodQty;
    Date expDate;
} Product;

typedef struct node {
    Product item;
    struct node *left, *right;
} NodeType, *NodePtr;

NodePtr initialize(Product item);
NodePtr addBST(NodePtr *node, Product item);
NodePtr deleteBST(NodePtr node, char *prodName);
NodePtr traversalBST(NodePtr node);
void displayBST(NodePtr node, int level);
void inorderDFS(NodePtr node);
void postorderDFS(NodePtr node);
void preorderDFS(NodePtr node);

#endif
