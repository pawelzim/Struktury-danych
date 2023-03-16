#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* next;

	Node(int val) {
		value = val;
		next = NULL;
	}
};

class Linkedlist {
private:
	Node* head;
	Node* tail;
public:
	Linkedlist();
	void addNode(int val);
	void display();
};