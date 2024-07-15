#include <stdio.h>
#include <stdlib.h>
#include "GRAPH.h"

int main() {
    struct Graph* graph = createGraph(5);

    addEdge(graph, 'A', 'B');
    addEdge(graph, 'A', 'C');
    addEdge(graph, 'A', 'D');
    addEdge(graph, 'A', 'E');
    addEdge(graph, 'B', 'C');
    addEdge(graph, 'B', 'D');
    addEdge(graph, 'B', 'E');
    addEdge(graph, 'C', 'D');
    addEdge(graph, 'C', 'E');
    addEdge(graph, 'D', 'E');

    printAdjacencyMatrix(graph);
    printf("\n");
    printAdjacencyList(graph);

  
    for (int i = 0; i < graph->numVertices; i++) {
        struct AdjListNode* trav = graph->array[i].head;
        while (trav) {
            struct AdjListNode* temp = trav;
            trav = trav->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);

    return 0;
}
