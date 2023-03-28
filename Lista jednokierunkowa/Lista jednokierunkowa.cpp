#include <iostream>
#include <ctime>
#include "header.h"

using namespace std;

int main() {
	Linkedlist l1, l2;
	
	clock_t start4 = clock();
	for (int i = 0; i < 500000; i++) {
		l1.newHead(i);
	}
	clock_t stop4 = clock();

	clock_t start5 = clock();
	for (int i = 0; i < 10000; i++) {
		l2.newTail(i);
	}
	clock_t stop5 = clock();

	clock_t start1 = clock();
	l1.addElement(100000, 123);
	clock_t stop1 = clock();

	clock_t start2 = clock();
	l1.deleteElement(250000);
	clock_t stop2 = clock();

	clock_t start3 = clock();
	l1.popTail();
	clock_t stop3 = clock();

	cout << "Time newHead: " << measure_time(start4, stop4) << endl;
	cout << "Time newTail: " << measure_time(start5, stop5) << endl;
	cout << "Time addElement: " << measure_time(start1, stop1) << endl;
	cout << "Time deleteElement: " << measure_time(start2, stop2) << endl;
	cout << "Time popTail: " << measure_time(start3, stop3) << endl;

	return 0;
		
}