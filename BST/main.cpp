#include <iostream>
#include "node.h"

using namespace std;


int main(void)
{
	bag<int> b1;

	b1.insert(7);
	b1.insert(6);
	b1.insert(9);
	b1.insert(3);
	b1.insert(37);
	b1.insert(45);
	b1.insert(9);
	b1.insert(29);
	b1.insert(5);
	b1.debug();
	//init

	cout << "dd" << endl;

	for (;;) {}
	

	return 0;
}