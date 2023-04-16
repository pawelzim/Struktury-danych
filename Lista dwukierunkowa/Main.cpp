#include <iostream>
#include "Header1.h"

using namespace std;

int main() {
	DoublyLinkedList d;
	for (int i = 1; i <= 10; i++) {
		d.newHead(i);
	}
	d.newTail(999);
	d.newTail(888);
	d.popHead();
	d.popTail();
	d.display();
	cout << d.size() << endl;
	return 0;
}