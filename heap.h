#ifndef HEAP_H
#define HEAP_H


#include "data_structures.h"

pHEAP createHeap(int capacity);
void deleteHeap(pHEAP pHeap);
void insertHeap(pHEAP pHeap, pELEMENT pElement);
pELEMENT extractMin(pHEAP pHeap);
void decreaseKey(int idx, double key, pHEAP pHeap);

#endif
