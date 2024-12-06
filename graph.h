#ifndef GRAPH_H
#define GRAPH_H


#include "data_structures.h"

pGRAPH createGraph(int vertices, int edges);
void addEdge(pGRAPH pGraph, int edgeIndex, 
        int u, int v, double w, bool isDirected, bool insertRear);

void deleteGraph(pGRAPH pGraph);
void singlePairShortestPath(
        pGRAPH pGraph, int s, int d, pVERTEX* vertices, pHEAP pHeap);

void singleSourceShortestPath(pGRAPH pGraph, int source, pVERTEX* vertices, pHEAP pHEap);

void resetV(int countVertices, pVERTEX* vertices);
void resetH(pHEAP pHeap);

#endif
