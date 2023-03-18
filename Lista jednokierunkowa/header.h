#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* next;
};

class Linkedlist {
private:
	Node* head;
public:
	Linkedlist();
	void newHead(int val);
	void popHead();
	void newTail(int val);
	void popTail();
	void showList();
	bool isEmpty();
	int amount();
	Node* findElement(int val);
	void deleteElement(int val);
	void addElement(int pos, int val);
};