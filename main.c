#include <stdio.h>
#include "BST.h"

int main() {
    NodePtr node = NULL;

    Product productI = {"Apple", 2.5, 10, {12, 1, 2021}};
    Product productII = {"Samsung", 1.5, 12, {1, 12, 2020}};
    Product productIII = {"Lenovo", 1.1, 5, {12, 1, 2022}};
    Product productIV = {"ASUS", 3.5, 11, {2, 2, 2024}};
    Product productV = {"Dell", 2.8, 8, {15, 5, 2023}};
    Product productVI = {"HP", 2.2, 7, {10, 8, 2022}};
    Product productVII = {"Acer", 1.7, 6, {20, 3, 2023}};
    Product productVIII = {"MSI", 4.0, 9, {5, 10, 2021}};

    addBST(&node, productI);
    addBST(&node, productII);
    addBST(&node, productIII);
    addBST(&node, productIV);
    addBST(&node, productV);
    addBST(&node, productVI);
    addBST(&node, productVII);
    addBST(&node, productVIII);
    
    char productToDelete[] = "Lenovo";
    node = deleteBST(node, productToDelete);
    

    displayBST(node, 0);

    return 0;
}
