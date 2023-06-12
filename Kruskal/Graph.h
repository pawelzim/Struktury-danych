#include <iostream>

using namespace std;

// max rozmiar grafu
#define MAX_SIZE 300

struct Edge {
	int startVertex;
	int endVertex;
	int weight;

	Edge(int start, int end, int weig) {
		startVertex = start;
		endVertex = end;
		weight = weig;
	}
	Edge() {
		startVertex = 0;
		endVertex = 0;
		weight = 0;
	}
};

struct Vertex {
	int index;
	DoublyLinkedList <int> neighbours;
};

class Graph {
private:
	int numberOfVertices;
	int adjacencyMatrix[MAX_SIZE][MAX_SIZE];
	int adjacencyMatrixMST[MAX_SIZE][MAX_SIZE];
	DoublyLinkedList <Vertex> vertices;
public:
	DoublyLinkedList <Edge> edges;
	DoublyLinkedList <Edge> MSTEdges;
	Graph(int nr);
	void addEdge(int start, int end, int weig);
	int getNumberOfVertices();
	int getNumberOfEdges();
	void createAdjacencyMatrix();
	void createNeighbourHoodList();
	void quicksortEdges();
	// 0 - graf zwykly, 1 - macierz sasiedztwa, 2 - lista sasiedztwa
	void printGraph(int whichOne);
	void printMSTGraph(int whichOne);
	// testy
	void fillGraph(float density);
};

// ---------- quicksort ----------
template <typename T>
void quicksort(Node<T>* low, Node<T>* high);

template <typename T>
Node<T>* partition(Node<T>* low, Node<T>* high);


void kruskal(Graph& graf);

int FindParent(int* parent[], int vertex);
void Union(int* parent[], int x, int y);

double testMST(Graph& graf);
double testAdjacencyMatrix(Graph& graf);
double neighbourhoodList(Graph& graf);