#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H



#include <cfloat>


enum COLOR {
    WHITE,
    GRAY,
    BLACK
};

typedef struct TAG_NODE {
    int index;
    int u;
    int v;
    double w;
    struct TAG_NODE* next;
} NODE;

typedef NODE* pNODE;


typedef struct TAG_VERTEX {
    int index;
    COLOR color;
    double key;
    int pi;
    int pos;
} VERTEX;

typedef VERTEX* pVERTEX;

typedef VERTEX ELEMENT;

typedef ELEMENT* pELEMENT;

typedef struct TAG_HEAP {
    int capacity;
    int size;
    pELEMENT *H;
} HEAP;

typedef HEAP* pHEAP;

typedef struct TAG_STACK {
    int capacity;
    int top;
    pVERTEX* elements;

}STACK;

typedef STACK* pSTACK;

typedef struct TAG_GRAPH {
    int vertices;
    int edges;
    pNODE* adjList;
} GRAPH;

typedef GRAPH* pGRAPH;

#endif

