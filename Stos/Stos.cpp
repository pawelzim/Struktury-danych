#include <iostream>
#include "Header.h"

using namespace std;

int main() {
	Stack s1;
	s1.push(15);
	s1.push(30);
	s1.push(45);
	s1.display();
	s1.pop();
	s1.display();
	s1.value();

	return 0;
}