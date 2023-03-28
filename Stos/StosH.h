#include <iostream>

using namespace std;

struct Node {
	Node* next;
	int value;
};

class Stack {
private:
	Node* top;
public:
	Stack() {
		top = NULL;
	}
	void push(int val);
	void pop();
	bool isEmpty();
	void value();
	void display();
	int count();
};