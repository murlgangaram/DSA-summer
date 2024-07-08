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
            (*node)->left = addBST(&((*node)->left), item);
        } else {
            (*node)->right = addBST(&((*node)->right), item);
        }
    }
    return *node;
}

NodePtr findMin(NodePtr node) {
    if (node == NULL)
        return NULL;
    else if (node->left == NULL)
        return node;
    else
        return findMin(node->left);
}

NodePtr deleteBST(NodePtr node, char *prodName) {
    if (node == NULL) {
        fprintf(stderr, "Product '%s' not found in the BST.\n", prodName);
        return node;
    }

    if (strcmp(prodName, node->item.prodName) < 0) {
        node->left = deleteBST(node->left, prodName); 
    } else if (strcmp(prodName, node->item.prodName) > 0) {
        node->right = deleteBST(node->right, prodName);
    } else { 
        if (node->left == NULL && node->right == NULL) { 
            free(node);
            node = NULL;
        } else if (node->left == NULL) { 
            NodePtr temp = node;
            node = node->right;
            free(temp);
        } else if (node->right == NULL) { 
            NodePtr temp = node;
            node = node->left;
            free(temp);
        } else { 
            NodePtr temp = findMin(node->right);
            node->item = temp->item;
            node->right = deleteBST(node->right, temp->item.prodName);
        }
    }
    return node;
}

NodePtr traversalBST(NodePtr node) {
    if (node != NULL) {
        printf("\nInorder Traversal:\n");
        inorderDFS(node);
        printf("\n\nPostorder Traversal:\n");
        postorderDFS(node);
        printf("\n\nPreorder Traversal:\n");
        preorderDFS(node);
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

void inorderDFS(NodePtr node) {
    if (node != NULL) {
        inorderDFS(node->left);
        printf("%s ", node->item.prodName);
        inorderDFS(node->right);
    }
}

void postorderDFS(NodePtr node) {
    if (node != NULL) {
        postorderDFS(node->left);
        postorderDFS(node->right);
        printf("%s ", node->item.prodName);
    }
}

void preorderDFS(NodePtr node) {
    if (node != NULL) {
        printf("%s ", node->item.prodName);
        preorderDFS(node->left);
        preorderDFS(node->right);
    }
}

