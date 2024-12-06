#include "graph.h"
#include <iostream>
#include "heap.h"


using namespace std;




pGRAPH createGraph(int vertices, int edges) {
    pGRAPH pGraph = new GRAPH;
    pGraph->vertices = vertices;
    pGraph->edges = edges;

    pGraph->adjList = new pNODE[vertices+1];
    for (int i = 0; i <= vertices; ++i) {
        pGraph->adjList[i] = nullptr;
    }

    return pGraph;

}


void addEdge(pGRAPH pGraph, int edgeIndex, 
        int u, int v, double w, bool isDirected, bool insertRear)  {

    if (u < 0 || u> pGraph->vertices || v <= 0 || v > pGraph->vertices) {
        cerr << u << endl;
        cerr << v << endl;
        cerr << "Invalid vertex index" << endl; 
        return;
    }
    pNODE node = new NODE;
    node->index = edgeIndex;
    node->u = u;
    node->v = v;
    node->w = w;
    node->next = nullptr;
    if (insertRear) {
        if (!pGraph->adjList[u]) {
            pGraph->adjList[u] = node;
        }
        else {
            pNODE temp = pGraph->adjList[u];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = node;
        }
    }
    else {
        node->next = pGraph->adjList[u];
        pGraph->adjList[u] = node;
    }

    if (!isDirected) {
        pNODE otherNode = (pNODE)malloc(sizeof(NODE));
        otherNode->index = edgeIndex;
        otherNode->u = v;
        otherNode->v = u;
        otherNode->w = w;
        otherNode->next = nullptr;
        if (insertRear) {
            if (!pGraph->adjList[v]) {
                pGraph->adjList[v] = otherNode;
            }
            else {
                pNODE temp = pGraph->adjList[v];
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = otherNode;
            }
        }
        else {
            otherNode->next = pGraph->adjList[v];
            pGraph->adjList[v] = otherNode;
        }

    }

}


void deleteGraph(pGRAPH pGraph) {
    
    for (int i = 0; i< pGraph->vertices; i++) {
        pNODE node = pGraph->adjList[i];
        while (node != NULL) {
            pNODE temp = node;
            node = node->next;
            free(temp);
        }
    }

    delete[] pGraph->adjList;
    free(pGraph);
}


void singlePairShortestPath(pGRAPH pGraph, int s, int d, 
        pVERTEX *vertices, pHEAP pHeap) {
    
    resetV(pGraph->vertices,vertices);
    resetH(pHeap);
    vertices[s]->key = 0.0;
    insertHeap(pHeap,vertices[s]);
    while (pHeap->size > 0) {
        pVERTEX u = extractMin(pHeap);
        if (u->index == d) {
            break;
        }
        pNODE current = pGraph->adjList[u->index];
        while (current) {
            pVERTEX v = vertices[current->v];
            double newKey = u->key + current->w;
            if (v->key > newKey) {
                v->key = newKey;
                v->pi = u->index;
                if (v->pos == -1) {
                    insertHeap(pHeap, v);
                }
                else {
                    decreaseKey(v->pos,newKey,pHeap);
                }
            }
            current = current->next;

        }
    }
    

}

void singleSourceShortestPath(pGRAPH pGraph, int source, pVERTEX *vertices, pHEAP pHeap) {
   resetV(pGraph->vertices,vertices);
   resetH(pHeap);
   vertices[source]->key = 0.0;
   insertHeap(pHeap,vertices[source]);

   while (pHeap->size > 0) {
        pVERTEX u = extractMin(pHeap);
        pNODE current = pGraph->adjList[u->index];
        while (current) {
            pVERTEX v = vertices[current->v];
            if (v->key > u->key + current->w) {
                v->key = u->key + current->w;
                v->pi = u->index;
                if (v->pos == -1) {
                    insertHeap(pHeap, v);
                }
                else {
                    decreaseKey(v->pos, u->key + current->w, pHeap);
                }
            }
            current = current->next;
        }
   }
}


void resetV(int countVertices, pVERTEX* vertices) {

    for (int i = 1; i <= countVertices; i++) {
        if (vertices[i] != nullptr) {
            vertices[i]->key = DBL_MAX;
            vertices[i]->pi = -1;
            vertices[i]->color = WHITE;
            vertices[i]->pos = -1;
        }
    }
}

void resetH(pHEAP pHeap) {
    pHeap->size = 0;
    for (int i = 0; i < pHeap->capacity; i++) {
        pHeap->H[i] = nullptr;
    }
}


