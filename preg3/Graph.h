#ifndef GRAPH_H
#define	GRAPH_H

typedef struct Edge{
    char e;
    int weight;
    struct Edge* next;
}TEdge;

typedef struct Vertex{
    int e;
    TEdge *adjInit;
    TEdge *adjEnd;
    struct Vertex* sig;
}TVertex;

typedef struct Graph{
    TVertex *initVertex;
    TVertex *endVertex;
    int numVertex;
}TGraph;

void Graph_init(TGraph *);
void Graph_insertVertex(TGraph *, int);
void Graph_insertEdge(TGraph *, int , int , int);
void Graph_print(TGraph *);

#endif	/* GRAPH_H */

