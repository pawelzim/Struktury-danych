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
	void deleteElement(int pos);
	void addElement(int pos, int val);
};

double measure_time(clock_t strt, clock_t stp);