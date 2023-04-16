#include <iostream>
#include "Header1.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;
	counter = 0;
}

void DoublyLinkedList::newHead(int val) {
	Node* tmp = new Node();
	tmp->value = val;
	if (head == nullptr && tail == nullptr) {
		tmp->next = nullptr;
		tmp->previous = nullptr;
		head = tmp;
		tail = tmp;
		counter++;
		return;
	}
	tmp->next = nullptr;
	tmp->previous = head;
	head->next = tmp;
	head = tmp;
	counter++;
}

void DoublyLinkedList::popHead() {
	if (head == nullptr) {
		cout << "List is empty, cannot popHead" << endl;
		return;
	}
	Node* tmp = head;
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
		delete tmp;
		counter--;
		return;
	}
	head = head->previous;
	delete tmp;
	head->next = nullptr;
	counter--;
}

void DoublyLinkedList::newTail(int val) {
	Node* tmp = new Node();
	tmp->value = val;
	if (head == nullptr && tail == nullptr) {
		tmp->next = nullptr;
		tmp->previous = nullptr;
		head = tmp;
		tail = tmp;
		counter++;
		return;
	}
	tmp->previous = nullptr;
	tmp->next = tail;
	tail->previous = tmp;
	tail = tmp;
	counter++;
}

void DoublyLinkedList::popTail() {
	if (tail == nullptr) {
		cout << "List is empty, cannot popTail" << endl;
		return;
	}
	Node* tmp = tail;
	if (tail == head) {
		tail = nullptr;
		head = nullptr;
		delete tmp;
		counter--;
		return;
	}
	tail = tail->next;
	delete tmp;
	tail->previous = nullptr;
	counter--;
}

void DoublyLinkedList::display() {
	if (head == nullptr) {
		cout << "List is empty" << endl;
		return;
	}
	Node* tmp2 = tail;
	cout << "(TAIL) ";
	while (tmp2 != nullptr) {
		cout << tmp2->value << " -> ";
		tmp2 = tmp2->next;
	}
	cout << " (HEAD)" << endl;
}

int DoublyLinkedList::size() {
	return counter;
}