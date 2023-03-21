#include <iostream>
#include <ctime>
#include "header.h"

using namespace std;

int main() {
	Linkedlist l1, l2;
	
	for (int i = 0; i < 500000; i++) {
		l1.newHead(i);
	}

	clock_t start1 = clock();
	l1.popTail();
	clock_t stop1 = clock();
	cout << l1.amount() << endl;
	clock_t start2 = clock();
	l1.deleteElement(499999);
	clock_t stop2 = clock();
	cout << l1.amount() << endl;


	cout << "Time 1: " << measure_time(start1, stop1) << endl;
	cout << "Time 2: " << measure_time(start2, stop2) << endl;

	return 0;
		
}