#include <iostream>
#include "DoublyLinkedList.h"
#include "Graph.h"

using namespace std;

template <typename T>
Node<T>* partition(Node<T>* low, Node<T>* high) {
    T pivot = high->value;
    Node<T>* i = low->previous;

    for (Node<T>* j = low; j != high; j = j->next) {
        if (j->value.weight <= pivot.weight) {
            i = (i == nullptr) ? low : i->next;
            swap(i->value, j->value);
        }
    }

    i = (i == nullptr) ? low : i->next;
    swap(i->value, high->value);
    return i;
}

template <typename T>
void quicksort(Node<T>* low, Node<T>* high) {
    if (high != nullptr && low != high && low != high->next) {
        Node<T>* pivot = partition(low, high);
        quicksort(low, pivot->previous);
        quicksort(pivot->next, high);
    }
}

void Graph::quicksortEdges() {
    quicksort(edges.getFromTail(0), edges.getFromHead(edges.size() - 1));
}