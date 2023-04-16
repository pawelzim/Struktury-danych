#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* next;
	Node* previous;
};

class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
	int counter;
public:
	DoublyLinkedList();
	void newHead(int val);
	void popHead();
	void newTail(int val);
	void popTail();
	void display();
	int size();
};