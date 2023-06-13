#include <iostream>
#include "DoublyLinkedList.h"
#include "Graph.h"
#include <ctime>
#include <cmath>

using namespace std;

void Graph::fillGraph(float density) {
	srand(time(NULL));
	if (density > 1) {
		cout << "fillGraph error" << endl;
		return;
	}

	int rnd;
	int size = getNumberOfVertices();
	// wzor na ilosc krawedzi dla danego wypelnienia
	int edg = floor((density * size * (size - 1)) / 2);

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (edg == 0) {
				break;
			}
			rnd = rand() % 25 + 1;
			if (j == i) {
				continue;
			}
			addEdge(i, j, rnd);
			edg--;
		}
		if (edg == 0) {
			break;
		}
	}
}

double testMST(Graph& graf) {
	clock_t start = clock();
	kruskal(graf);
	clock_t stop = clock();

	double measured_time = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
	return measured_time;
}

double testAdjacencyMatrix(Graph& graf) {
	clock_t start = clock();
	graf.createAdjacencyMatrix();
	clock_t stop = clock();

	double measured_time = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
	return measured_time;
}

double neighbourhoodList(Graph& graf) {
	clock_t start = clock();
	graf.createNeighbourHoodList();
	clock_t stop = clock();

	double measured_time = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
	return measured_time;
}