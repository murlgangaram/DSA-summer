#include "BST.h"

NodePtr initialize(Product item) {
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->item = item;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

NodePtr addBST(NodePtr *node, Product item) {
    if (*node == NULL) {
        *node = initialize(item);
    } else {
        if (strcmp(item.prodName, (*node)->item.prodName) < 0) {
            addBST(&(*node)->left, item);
        } else {
            addBST(&(*node)->right, item);
        }
    }
    return *node;
}
NodePtr deleteBST(NodePtr node, char *prodName) {
    if (node == NULL) {
        return node;
    }

  
    if (strcmp(prodName, node->item.prodName) < 0) {
        deleteBST(node->left, prodName); 
    } else if (strcmp(prodName, node->item.prodName) > 0) {
        deleteBST(node->right, prodName);
    } 
        
    return node;
}


void displayBST(NodePtr node, int level) {
    if (node != NULL) {
        displayBST(node->right, level + 1);
        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("%s\n", node->item.prodName);
        displayBST(node->left, level + 1);
    }
}
