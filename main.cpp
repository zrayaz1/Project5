#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "heap.h"
#include "graph.h"
#include "stack.h"
#include "main.h"
#include "util.h"

using namespace std;




int main(int argc, char** argv) {
    if (argc != 4) {
        cerr << "Usage: ./PJ5 <InputFile> <GraphType> <Flag>" << endl;
        return 1;
    }

    char* fileName = argv[1];
    string type = argv[2];
    int flag = atoi(argv[3]);
    
    if (type != "DirectedGraph" && type != "UndirectedGraph") {
        cerr << "Usage: ./PJ5 <InputFile> <GraphType> <Flag>" << endl;
        return 1;
    }
    
    if (flag > 1 || flag < 0) {
        cerr << "Usage: ./PJ5 <InputFile> <GraphType> <Flag>" << endl;
        return 1;
    }
    bool isDirected = (type == "DirectedGraph");

    ifstream file(fileName);

    if (!file) {
        cerr << "file error" << endl;
        return 1;
    }

    int countVertices;
    int countEdges;
    file >> countVertices;
    file >> countEdges;
    pGRAPH pGraph = createGraph(countVertices, countEdges);

    for (int i = 0; i < countEdges; i++) {
        int edgeIndex;
        int u;
        int v;
        double w;
        file >> edgeIndex >> u >> v >> w;
        addEdge(pGraph,edgeIndex,u,v,w,isDirected,flag==1);
    }
    file.close();

    pVERTEX* vertices = new pVERTEX[countVertices +1];
    for (int i = 1; i<=countVertices; i++) {
        vertices[i] = new VERTEX;
        vertices[i]->index = i;
        vertices[i]->color = WHITE;
        vertices[i]->key = DBL_MAX;
        vertices[i]->pi = -1;
        vertices[i]->pos = -1;
    }

    pHEAP pHeap = createHeap(countVertices);
    if (!pHeap) {
        return 1;
    }

    pSTACK pStack = createStack(countVertices);
    bool sorted = false;
    int sourceFrom = -1;
    int sourceEnd = -1;

    string input;
    while(getline(cin, input)) {
        istringstream iss(input);
        string command;
        iss >> command;

        if (command == "Stop") {
            break;
        }
        else if (command == "PrintADJ") {
           printAdjList(pGraph); 

        }
        else if (command == "SingleSource") {
            int start;
            iss >> start;
            singleSourceShortestPath(pGraph, start, vertices, pHeap);
            sourceFrom = start;
            sorted = true;

        }
        else if (command == "SinglePair") {
            int start, destination;
            iss >> start;
            iss >> destination;
            singlePairShortestPath(pGraph,start,destination,vertices,pHeap);
            sourceFrom = start;
            sourceEnd = destination;
            sorted = true;
        }
        else if (command == "PrintLength") {
            int start, destination;
            iss >> start >> destination;
            printLength(vertices,start,destination);

        }
        else if (command == "PrintPath") {
            int start, destination;
            iss >> start >> destination;
            printPath(vertices,pStack,start,destination,sorted,sourceFrom,sourceEnd);
            
    
        }
    }

    return 0;

}
