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
	b1.sort();
	cout << endl << "aaa : " <<  b1.count(22);


	cout << "--------------------------------------------------------------" << endl;
	cout << "총 " << b1.erase(22) << "개를 삭제 하였습니다." << endl;
	b1.sort();

	b1.show_content();
	cout << "--------------------------------------------------------------" << endl;
	cout << "총 " << b1.erase(13) << "개를 삭제 하였습니다." << endl;
	b1.show_content();
	b1.sort();

	//init

	cout << "dd" << endl;

	for (;;) {}
	

	return 0;
}