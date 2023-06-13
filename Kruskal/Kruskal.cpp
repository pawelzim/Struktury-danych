#include <iostream>
#include "DoublyLinkedList.h"
#include "Graph.h"
#include <ctime>
#include <cmath>

using namespace std;

int main() {
	srand(time(NULL));

	Graph graf(5);
	graf.fillGraph(1);
	graf.createAdjacencyMatrix();
	graf.createNeighbourHoodList();

	graf.printGraph(1);

	cout << "\n\n\n";

	graf.printGraph(2);





	//graf.printMSTGraph(0);

	return 0;
}