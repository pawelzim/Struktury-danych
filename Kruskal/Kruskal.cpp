#include <iostream>
#include "DoublyLinkedList.h"
#include "Graph.h"
#include <ctime>
#include <cmath>

using namespace std;

int main() {
	srand(time(NULL));

	Graph graf(250);
	graf.fillGraph(0.75);

	cout << neighbourhoodList(graf) << endl;





	//graf.printMSTGraph(0);

	return 0;
}