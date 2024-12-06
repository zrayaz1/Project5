
#include <iostream>

#include "heap.h"

using namespace std;



pHEAP createHeap(int capacity) {
    pHEAP pHeap = new HEAP;

    pHeap->capacity = capacity;
    pHeap->size = 0;
    pHeap->H = new pELEMENT[capacity];
    return pHeap;

}

void heapify(pHEAP pHeap, int i) {
    int smallest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left <= pHeap->size) {
        if (pHeap->H[left]->key < pHeap->H[smallest]->key) {
            smallest = left;
        }
    }
    if (right <= pHeap->size) {
        if (pHeap->H[right]->key < pHeap->H[smallest]->key) {
            smallest = right;
        }
    }

    if (smallest != i) {
        pELEMENT temp = pHeap->H[smallest];
        pHeap->H[smallest] = pHeap->H[i];
        pHeap->H[i] = temp;
        pHeap->H[i]->pos = i;
        pHeap->H[smallest]->pos = smallest;
        heapify(pHeap,smallest);

    }


}

void deleteHeap(pHEAP pHeap) {
    delete pHeap->H;
    delete pHeap;
}



void insertHeap(pHEAP pHeap, pELEMENT pElement) {


    pHeap->size++;
    int idx = pHeap->size;
    pHeap->H[idx] = pElement;
    pElement->pos = idx;
    
    while (idx > 1 && pHeap->H[idx]->key < pHeap->H[idx/2]->key) {
        pELEMENT temp = pHeap->H[idx];
        pHeap->H[idx] = pHeap->H[idx/2];
        pHeap->H[idx]->pos = idx;
        pHeap->H[idx/2] = temp;
        pHeap->H[idx/2]->pos = idx/2;
        idx = idx/2;
    }

}

pELEMENT extractMin(pHEAP pHeap) {
    if (pHeap == nullptr) {
        cerr << "Error heap is NULL" << endl;
        return nullptr;
    }
    if (pHeap->size == 0) {
        cerr << "Error: heap is empty" <<endl;
        return nullptr;
    }
    pELEMENT smallest = pHeap->H[1];
    pHeap->H[1] = pHeap->H[pHeap->size];
    pHeap->H[1]->pos = 1;
    pHeap->size = pHeap->size-1;
    heapify(pHeap,1);

    smallest->pos = 0;

    return smallest;

}

void decreaseKey(int idx, double key, pHEAP pHeap) {

    if (idx < 1 || idx > pHeap->size) {
        cerr << "Error: invalid call to DecreaseKey" << endl;
        return;
    }
    
    pHeap->H[idx]->key = key;
    
   int i = idx; 

    while (i > 1 && pHeap->H[i/2]->key > pHeap->H[i]->key) {
        pELEMENT temp = pHeap->H[i];
        pHeap->H[i] = pHeap->H[i/2];
        pHeap->H[i/2] = temp;
        pHeap->H[i]->pos = i;
        pHeap->H[i/2]->pos = i/2;
        i = i/2;
    }


}




