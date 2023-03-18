#include <iostream>
#include "header.h"

using namespace std;

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
		//tmp2->next = NULL;
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
	Node* tmp = new Node();
	tmp = head;
	while (tmp != NULL) {
		if (tmp->value == val) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

void Linkedlist::deleteElement(int val) {
	Node* tmp1, * tmp2;
	tmp1 = head;
	tmp2 = NULL;
	while (tmp1 != NULL && tmp1->value != val) {
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	//brak pasujacego elementu
	if (tmp2 == NULL) {
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