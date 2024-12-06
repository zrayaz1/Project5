#include "util.h"
#include <iostream>
#include <iomanip>
#include "stack.h"
#include <string>
using namespace std;



void printAdjList(pGRAPH pGraph) {
    for (int i = 1; i<= pGraph->vertices; i++) {
        cout << "ADJ[" <<i << "]:";
        pNODE current = pGraph->adjList[i];
        while (current) {
            cout << "-->[" << current->u << " " <<current->v<< ": "
                <<fixed<<setprecision(2)<<current->w<<"]";
            current = current->next;
        }
        cout << endl;

    }
}



void printLength(pVERTEX* vertices, int start, int destination) {
    if (vertices[destination]->key == DBL_MAX) {
        cout << "There is no path from "<<start<<" to "<<destination<<"." << endl;
        return;

    }

    cout << "The length of the shortest path from "<<start
        <<" to "<<destination<<" is:     " << fixed<< setprecision(2)<< vertices[destination]->key <<endl;
}


void printPath(pVERTEX* vertices, pSTACK pStack, int start, int destination, bool sorted, int sourceFrom, int sourceEnd) {
    if (!sorted) {
        return;
    }
    if (start < 0 || destination < 0) {
        return;
    }
    if (sourceFrom!= start) {
        if (sourceFrom != -1) {
            return;
        }
    }
    if (sourceEnd!= destination) {
        if (sourceEnd != -1) {
            return;
        }
    }
    if (vertices[destination]->pi == -1) {
        cout << "There is no path from " 
            << start << " to " << destination << "." << endl;
        return;
    }


    int idx = destination;

    while (idx != -1) {
        push(pStack, vertices[idx]);
        idx = vertices[idx]->pi;
    }
    
    if (peek(pStack)->index != start) {
        return;
    }
    
    bool isFirst = true;

    cout << "The shortest path from " << start << " to " << destination << " is:" <<endl;
    while(pStack->top != -1) {
        int vIdx = pop(pStack)->index;
        if (!isFirst) {
            cout <<"-->";
        }
        int pad = 5 - to_string((int)vertices[vIdx]->key).length();
        if (pad < 0) {
            pad = 0;
        }
        cout << "[" << vIdx << ":"<< string(pad, ' ')<<fixed<<setprecision(2)<<vertices[vIdx]->key<<"]";
        isFirst = false;
        

    }
    cout << "." << endl;

}
    



