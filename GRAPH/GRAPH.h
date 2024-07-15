#ifndef GRAPH_H
#define GRAPH_H

struct AdjListNode {
    char vertex; 
    struct AdjListNode* next; 
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph {
    int numVertices; 
    struct AdjList* array; 
};

struct AdjListNode* createNode(char vertex);

struct Graph* createGraph(int numVertices);

void addEdge(struct Graph* graph, char src, char dest);

void printGraph(struct Graph* graph);

void printAdjacencyMatrix(struct Graph* graph);

void printAdjacencyList(struct Graph* graph);

#endif
