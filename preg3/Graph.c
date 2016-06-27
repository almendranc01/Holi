#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Graph.h"

void Graph_init(TGraph *G){
    G->initVertex = NULL;
    G->endVertex = NULL;
    G->numVertex = 0;
}

TVertex* searchVertex(TGraph *G, int e){
    TVertex* rec = G->initVertex;
    while(rec != NULL){
        if(rec->e == e)
            return rec;
        rec = rec->sig;
    }
    return NULL;
}

void Graph_insertVertex(TGraph *G, int e){
    TVertex *vertex = searchVertex(G, e);
    if(vertex == NULL){
        TVertex* new = malloc(sizeof(TVertex));
        new->e = e;
        new->adjInit = NULL;
        new->adjEnd = NULL;
        new->sig = NULL;
        
        if(G->initVertex == NULL)
            G->initVertex = new;
        else
            G->endVertex->sig = new;
        G->endVertex = new;
        (G->numVertex)++;
        
    }
}

int exitEdge(TGraph* G, int u, int v){
    TVertex *vertexU = searchVertex(G, u);
    TEdge* rec = vertexU->adjInit;
    while(rec != NULL){
        if(rec->e == v)
            return 1;
        rec = rec->next;   
    }
    return 0;
}

void Graph_insertEdge(TGraph *G, int u, int v, int weight){
    TVertex *vertexU = searchVertex(G, u);
    if(vertexU != NULL && searchVertex(G, v) && !exitEdge(G, u, v)){
        TEdge* new = malloc(sizeof(TEdge));
        new->e = v;
        new->weight = weight;
        new->next = NULL;
        
        if(vertexU->adjInit == NULL)
            vertexU->adjInit = new;
        else
            vertexU->adjEnd->next = new;
        vertexU->adjEnd = new;                 
        
    }
}

void Graph_print(TGraph *G){
    TVertex* vertex = G->initVertex;
    while(vertex != NULL){
        printf("%d ", vertex->e);
        TEdge* edge = vertex->adjInit;
        while(edge != NULL){
            printf("->(%d, %d)", edge->e, edge->weight);
            edge = edge->next;
        }
        printf("\n");
        vertex = vertex->sig;
    }
}

int G_obtainVertexMin(int *dist, int *list_visited, int V){
    int v, min_index;
    int min = INT_MAX;
    for(v=0; v<V; v++){
        if(!list_visited[v] && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void G_printWays(int origen, int *dist, int *father, int V){
    int v;
    for(v=0; v<V; v++){
        printf("De %d a %d es %d: %d",origen, v+1, dist[v], v+1);
        int aux = v;
        while(father[aux] != -1){
            printf("<-%d", father[aux]+1);
            aux = father[aux];
        }
        printf("\n");
    }
}

void dijktra(TGraph* G, int origen){
    int V = G->numVertex;
    int *list_visited = malloc(V * sizeof(int));
    int *dist = malloc(V * sizeof(int));
    int *father = malloc(V * sizeof(int));
    
    int v;
    //Inicialize
    for(v=0; v<V; v++){
        list_visited[v] = 0;
        dist[v] = INT_MAX;
        father[v] = -1;
    }
    dist[origen - 1] = 0;
    for(v=0; v<V; v++){
        int indVertMin = G_obtainVertexMin(dist, list_visited, V);
        list_visited[indVertMin] = 1;
        TVertex* vertex = searchVertex(G, indVertMin + 1);
        TEdge* edge = vertex->adjInit;
        while(edge){
            int indEdge = edge->e - 1;
            int weight = edge->weight;
            if(!list_visited[indEdge] && dist[indVertMin] + weight < dist[indEdge]){
                dist[indEdge] = dist[indVertMin] + weight;
                father[indEdge] = indVertMin;
            }
            edge = edge->next;
        }
    }
    G_printWays(origen, dist, father, V);
    
}
