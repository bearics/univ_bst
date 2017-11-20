#include <iostream>
#include "node.h"

using namespace std;


int main(void)
{
	bag<int> b1;

	b1.insert(17);
	b1.insert(8);
	b1.insert(3);
	b1.insert(1);
	b1.insert(5);
	b1.insert(13);
	b1.insert(10);
	b1.insert(22);
	b1.insert(19);
	b1.insert(22);
	b1.insert(65);
	b1.show_content();

	cout << "--------------------------------------------------------------" << endl;


	b1.erase(22);
	b1.show_content();
	b1.sort();

	for (;;) {}
	

	return 0;
}