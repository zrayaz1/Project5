#ifndef UTIL_H
#define UTIL_H



#include "graph.h"
#include "stack.h"
#include "heap.h"
#include "data_structures.h"


void printAdjList(pGRAPH pGraph);
void printLength(pVERTEX* vertices, int start, int destination);
void printPath(pVERTEX* vertices, 
        pSTACK pStack, int start, 
        int destination, bool sorted, 
        int sourceFrom, int sourceEnd);

#endif
