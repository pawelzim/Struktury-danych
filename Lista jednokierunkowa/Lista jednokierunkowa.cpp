#include <iostream>
#include "header.h"

using namespace std;

int main() {
	Linkedlist l1;
	l1.newHead(10);
	l1.newHead(20);
	l1.newHead(30);
	l1.newHead(40);
	l1.newTail(111);
	//l1.deleteElement(30);
	l1.showList();
	l1.popHead();
	l1.popTail();
	l1.showList();

	Linkedlist l2;

	cout << l2.amount() << endl;


	return 0;
		
}