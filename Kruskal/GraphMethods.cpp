#include <iostream>
#include "DoublyLinkedList.h"
#include "Graph.h"

using namespace std;

// value -> krawedz !!!!

Graph::Graph(int nr) {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			adjacencyMatrix[i][j] = 0;
			adjacencyMatrixMST[i][j] = 0;
		}
	}
	numberOfVertices = nr;
}

void Graph::addEdge(int start, int end, int weig) {
	Edge val(start, end, weig);
	edges.newHead(val);
}

int Graph::getNumberOfVertices() {
	return numberOfVertices;
}

int Graph::getNumberOfEdges() {
	return edges.size();
}

void Graph::createAdjacencyMatrix() {
	int a, b, c;
	Edge tmp = edges.getFromTail(0)->value;
	for (int i = 0; i < edges.size(); i++) {
		tmp = edges.getFromTail(i)->value;
		a = tmp.startVertex;
		b = tmp.endVertex;
		c = tmp.weight;
		adjacencyMatrix[a][b] = c;
		adjacencyMatrix[b][a] = c;
	}
}

void Graph::createNeighbourHoodList() {
	Edge tmp(NULL, NULL, NULL);
	Vertex ver;
	for (int i = 0; i < numberOfVertices; i++) {
		ver.index = i;
		vertices.newHead(ver);
		for (int j = 0; j < edges.size(); j++) {
			tmp = edges.getFromTail(j)->value;
			if (tmp.startVertex == i) {
				vertices.getFromTail(i)->value.neighbours.newHead(tmp.endVertex);
			}
			else if (tmp.endVertex == i) {
				vertices.getFromTail(i)->value.neighbours.newHead(tmp.startVertex);
			}
		}
	}
}

// 0|1|2 - graf|macierz|lista
void Graph::printGraph(int whichOne) {
	Edge tmp(NULL, NULL, NULL);
	if (whichOne == 0) {
		for (int i = 0; i < edges.size(); i++) {
			tmp = edges.getFromTail(i)->value;
			cout << tmp.startVertex << " - " << tmp.endVertex << " : " << tmp.weight << endl;
		}
	}
	else if (whichOne == 1) {
		for (int i = 0; i < numberOfVertices; i++) {
			for (int j = 0; j < numberOfVertices; j++) {
				cout << adjacencyMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	else if (whichOne == 2) {
		Vertex ver;
		for (int i = 0; i < vertices.size(); i++) {
			ver = vertices.getFromTail(i)->value;
			cout << ver.index << ": ";
			for (int j = 0; j < ver.neighbours.size(); j++) {
				cout << ver.neighbours.getFromTail(j)->value;
				cout << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "printGraph error" << endl;
		return;
	}
}

void Graph::printMSTGraph(int whichOne) {
	Edge tmp(NULL, NULL, NULL);
	if (whichOne == 0) {
		for (int i = 0; i < MSTEdges.size(); i++) {
			tmp = MSTEdges.getFromTail(i)->value;
			cout << tmp.startVertex << " - " << tmp.endVertex << " : " << tmp.weight << endl;
		}
	}
	else if (whichOne == 1) {
		for (int i = 0; i < numberOfVertices; i++) {
			for (int j = 0; j < numberOfVertices; j++) {
				cout << adjacencyMatrixMST[i][j] << " ";
			}
			cout << endl;
		}
	}
}

// ---------- kruskal ----------

int FindParent(int* parent[], int vertex) {
	if ((*parent)[vertex] != vertex) {
		int* tmp = (*parent) + vertex;
		(*parent)[vertex] = FindParent(parent, *tmp);
	}
	return (*parent)[vertex];
}

void Union(int* parent[], int x, int y) {
	int xRoot = FindParent(parent, x);
	int yRoot = FindParent(parent, y);
	(*parent)[yRoot] = xRoot;
}

void kruskal(Graph& graf) {
	graf.quicksortEdges();
	DoublyLinkedList<Edge> result;
	int* parentArray = new int[graf.getNumberOfVertices()];

	for (int i = 0; i < graf.getNumberOfVertices(); i++) {
		parentArray[i] = i;
	}

	int edgeCount = 0;
	int index = 0;
	Edge currentEdge;
	while (index < graf.edges.size() - 1) {
		Node<Edge>* tailNode = graf.edges.getFromTail(index);
		if (tailNode != nullptr) {
			currentEdge = graf.edges.getFromTail(index++)->value;
			int srcParent = FindParent(&parentArray, currentEdge.startVertex);
			int destParent = FindParent(&parentArray, currentEdge.endVertex);

			if (srcParent != destParent) {
				result.newHead(currentEdge);
				Union(&parentArray, srcParent, destParent);
				edgeCount++;
			}
		}
		else {
			break;
		}
	}
	delete[]parentArray;

	graf.MSTEdges = result;
}
