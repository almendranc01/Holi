#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main(int argc, char** argv) {
        
    TGraph G;
    
    Graph_init(&G);
    
    Graph_insertVertex(&G, 1);
    Graph_insertVertex(&G, 2);
    Graph_insertVertex(&G, 3);
    Graph_insertVertex(&G, 4);
    Graph_insertVertex(&G, 5);
    Graph_insertVertex(&G, 6);
    Graph_insertVertex(&G, 7);
    Graph_insertVertex(&G, 8);
    
    Graph_insertEdge(&G, 1, 2, 1);
    Graph_insertEdge(&G, 4, 1, 2);
    Graph_insertEdge(&G, 2, 3, 2);
    Graph_insertEdge(&G, 3, 4, 3);
    Graph_insertEdge(&G, 2, 5, -3);
    Graph_insertEdge(&G, 3, 8, -5);
    Graph_insertEdge(&G, 4, 7, 2);
    Graph_insertEdge(&G, 8, 5, 1);
    Graph_insertEdge(&G, 7, 8, 2);
    Graph_insertEdge(&G, 7, 5, 1);
    Graph_insertEdge(&G, 5, 6, 2);
    Graph_insertEdge(&G, 6, 7, 3);

    Graph_print(&G);
    
    dijktra(&G, 1);
    
    return (EXIT_SUCCESS);
}

