#include <iostream>
#include "header.h"

using namespace std;

void measure_time(clock_t strt, clock_t stp) {
	cout << static_cast<double>(stp - strt) / CLOCKS_PER_SEC << endl;
}

Linkedlist::Linkedlist() {
	head = NULL;
}

void Linkedlist::newHead(int val) {
	Node* tmp = new Node();
	tmp->value = val;
	tmp->next = head;
	head = tmp;
}

void Linkedlist::popHead() {
	if (head == NULL) {
		cout << "Empty list, can't popHead" << endl;
	}
	else {
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

void Linkedlist::newTail(int val) {
	Node* good = new Node();
	good->value = val;
	good->next = NULL;
	if (head == NULL) {
		head = good;
	}
	else {
		Node* tmp = new Node();
		tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = good;
	}
}

void Linkedlist::popTail() {
	if (head == NULL) {
		cout << "Empty list, can't popTail" << endl;
		return;
	}
	else {
		Node* tmp = new Node();
		Node* tmp2 = new Node();
		tmp2 = head;
		while (tmp2->next->next != NULL) {
			tmp2 = tmp2->next;
		}
		tmp = tmp2->next;
		tmp2->next = NULL;
		delete tmp;
	}
}

void Linkedlist::showList() {
	Node* tmp = new Node();
	if (head == NULL) {
		cout << "Empty list" << endl;
		return;
	}
	tmp = head;
	while (tmp != NULL) {
		if (tmp == head) {
			cout << "(HEAD) ";
		}
		cout << tmp->value;
		tmp = tmp->next;
		if (tmp != NULL) {
			cout << " -> ";
		}
		else {
			cout << " (TAIL)";
		}
	}
	cout << endl;
}

bool Linkedlist::isEmpty() {
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

int Linkedlist::amount() {
	Node* tmp = new Node();
	tmp = head;
	int ctr = 0;
	//petla jest tez if-em; 0 elementow = brak iteracji petli
	while (tmp != NULL) {
		ctr++;
		tmp = tmp->next;
	}
	return ctr;
}

Node* Linkedlist::findElement(int val) {
	if (head == NULL) {
		cout << "Empty list, can't findElement" << endl;
		return NULL;
	}
	Node* tmp = new Node();
	tmp = head;
	while (tmp != NULL) {
		if (tmp->value == val) {
			return tmp;
		}
		tmp = tmp->next;
	}
	cout << "No such element on list" << endl;
	return NULL;
}

void Linkedlist::deleteElement(int val) {
	if (head == NULL) {
		cout << "List is empty, can't deleteElement" << endl;
		return;
	}
	Node* tmp1, * tmp2;
	tmp1 = head;
	tmp2 = NULL;
	while (tmp1 != NULL && tmp1->value != val) {
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	//brak pasujacego elementu
	if (tmp1 == NULL) {
		cout << "No matching element" << endl;
		return;
	}
	//usuwanie head-a (pasujacego)
	if (tmp2 == NULL) {
		head = tmp1->next;
	}
	//usuwanie pasujacego elementu
	else {
		tmp2->next = tmp1->next;
	}
	delete tmp1;
}

void Linkedlist::addElement(int pos, int val) {
	if (pos > amount()) {
		cout << "Too far, can't addElement" << endl;
		return;
	}
	if (pos == 1 || head == NULL) {
		newHead(val);
		return;
	}
	if (pos == amount()) {
		newTail(val);
		return;
	}

	int ctr = 0;
	Node* tmp1 = head;
	Node* tmp2 = NULL;
	Node* addNew = new Node();
	addNew->value = val;
	for (int i = 0; i < pos-1; i++) {
		ctr++;
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp2->next = addNew;
	addNew->next = tmp1;
	cout << ctr << endl;
}