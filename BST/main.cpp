#include <iostream>
#include "node.h"

using namespace std;


int main(void)
{
	bag<int> b1;

	b1.insert(45);
	b1.insert(9);
	b1.insert(17);
	b1.insert(13);
	b1.insert(3);
	b1.insert(13);
	b1.insert(9);
	b1.insert(53);
	b1.insert(54);
	b1.insert(13);
	b1.insert(51);
	b1.insert(9);
	b1.insert(13);
	b1.debug();
	b1.sort();


	cout << "--------------------------------------------------------------" << endl;
	cout << "총 " << b1.erase(9) << "개를 삭제 하였습니다." << endl;
	b1.sort();

	b1.debug();
	cout << "--------------------------------------------------------------" << endl;
	cout << "총 " << b1.erase(13) << "개를 삭제 하였습니다." << endl;
	b1.debug();
	b1.sort();

	//init

	cout << "dd" << endl;

	for (;;) {}
	

	return 0;
}