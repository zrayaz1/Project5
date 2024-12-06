#include "stack.h"


#include <iostream>
using namespace std;


pSTACK createStack(int capacity) {
    pSTACK pStack = (pSTACK)malloc(sizeof(STACK));

    if (!pStack) {
        cerr << "Allocation failed" << endl;
        return NULL;
    }

    pStack->capacity = capacity;
    pStack->top = -1;

    pStack->elements = (pVERTEX*)malloc(capacity*sizeof(pVERTEX));
    if (!pStack->elements) {
        cerr << "Allocaiton failed" << endl;
        return NULL;
    }
    return pStack;

}

void push(pSTACK pStack, pVERTEX pVertex) {
    if (pStack->top == pStack->capacity -1) {
        return;
    }
    pStack->elements[++pStack->top] = pVertex;
}

pVERTEX pop(pSTACK pStack) {
    if (pStack->top == -1) {
        return NULL;
    }
    return pStack->elements[pStack->top--];
}

pVERTEX peek(pSTACK pStack) {
    if (pStack->top == -1) {
        return NULL;
    }
    return pStack->elements[pStack->top];
}


void deleteStack(pSTACK pStack) {
    if (pStack) {
        free(pStack->elements);
        free(pStack);

    }
}
