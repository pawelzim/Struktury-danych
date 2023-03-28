#include <iostream>
#include "Header.h"

using namespace std;

bool Stack::isEmpty() {
	return top == NULL;
}

void Stack::push(int val) {
	Node* tmp = new Node();
	tmp->value = val;
	tmp->next = top;
	top = tmp;
}

void Stack::pop() {
	if (isEmpty()) {
		cout << "Stack is empty! Cannot pop" << endl;
		return;
	}
	Node* tmp = new Node();
	tmp = top;
	top = top->next;
	delete tmp;
}

void Stack::value() {
	if (isEmpty()) {
		cout << "Stack is empty! Cannot show value" << endl;
		return;
	}
	cout << "Value of top is: " << top->value << endl;
}

int Stack::count() {
	int ctr = 0;
	if (isEmpty()) {
		return 0;
	}
	Node* tmp = top;
	while (tmp->next != NULL) {
		ctr++;
		tmp = tmp->next;
	}
	return ctr;
}

void Stack::display() {
	if (isEmpty()) {
		cout << "Stack is empty! Nothing to display" << endl;
		return;
	}
	Node* tmp = top;
	cout << "--- STACK ---" << endl;
	while (tmp != NULL) {
		cout << "     " << tmp->value << endl;
		tmp = tmp->next;
	}
}