#include <iostream>
#include <ctime>
#include "header.h"

using namespace std;

int main() {
	Linkedlist l1, l2;
	clock_t start1 = clock();
	for (int i = 0; i < 5000; i++) {
		if (i % 2 == 0) {
			l1.newHead(i);
		}
		else {
			l1.newTail(i);
		}
	}
	//l1.showList();
	clock_t stop1 = clock();

	clock_t start2 = clock();
	for (int i = 0; i < 25000; i++) {
		if (i % 2 == 0) {
			l2.newHead(i);
		}
		else {
			l2.newTail(i);
		}
	}
	//l1.showList();
	clock_t stop2 = clock();

	cout << "Time 1: ";
	measure_time(start1, stop1);
	cout << "Tim1 2: ";
	measure_time(start2, stop2);

	return 0;
		
}