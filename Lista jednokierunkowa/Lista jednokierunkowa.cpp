#include <iostream>
#include <ctime>
#include "header.h"

using namespace std;

void measure_time(clock_t strt, clock_t stp);

int main() {
	clock_t start1 = clock();

	Linkedlist l1;
	for (int i = 0; i < 10000; i = i + 3) {
		if (i % 2 == 0) {
			l1.newHead(i);
		}
		else {
			l1.newTail(i);
		}
	}
	l1.showList();
	l1.addElement(180, 999999);
	l1.deleteElement(54);

	clock_t stop1 = clock();
	measure_time(start1, stop1);

	cout << "-------------------------------------------" << endl;

	clock_t start2 = clock();

	Linkedlist l2;
	for (int i = 20000; i > 0; i = i - 3) {
		if (i % 2 == 0) {
			l2.newHead(i);
		}
		else {
			l2.newTail(i);
		}
	}
	l2.showList();
	l2.addElement(180, 999999);
	l2.deleteElement(53);

	clock_t stop2 = clock();
	measure_time(start2, stop2);

	return 0;
		
}