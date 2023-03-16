#include <iostream>
#include "header.h"

using namespace std;

Linkedlist::Linkedlist() {
	head = NULL;
	tail = NULL;
}

void Linkedlist::addNode(int val) {
	Node* tmp = new Node(val);
	tmp->next = NULL;
	tmp->value = val;

	if (head = NULL) {
		head = tmp;
		tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tail->next;
	}

}

void Linkedlist::display() {
	if (head == NULL) {
		cout << "Empty list" << endl;
	}
	else {
		Node* tmp = tail;
		while (tmp != NULL) {
			cout << tmp->value << " -> ";
			tmp = tmp->next;
		}
		cout << endl;
	}
}