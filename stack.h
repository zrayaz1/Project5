#ifndef STACK_H
#define STACK_H






#include "data_structures.h"


pSTACK createStack(int capacity);
void push(pSTACK pStack, pVERTEX pVertex);
pVERTEX pop(pSTACK pStack);
pVERTEX peek(pSTACK pStack);
void deleteStack(pSTACK pStack);


#endif


