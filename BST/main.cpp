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

	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      1. insert() 예시                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " ▶ BEFORE" << endl << endl;
	b1.show_content();
	cout << " ▶ insert 함수로 13, 10, 22, 19, 22, 65 추가" << endl << endl;
	cout << " ▶ AFTER" << endl << endl;
	b1.insert(13);
	b1.insert(10);
	b1.insert(22);
	b1.insert(19);
	b1.insert(22);
	b1.insert(65);
	b1.show_content();
	cout << "--------------------------------------------------------------" << endl;

	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      2. erase() 예시                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " ▶ BEFORE" << endl << endl;
	b1.show_content();
	cout << endl << " ▶ erase 함수로 22가 " << b1.erase(22) << "개 제거" << endl;
	cout << " ▶ AFTER" << endl << endl;
	b1.show_content();
	cout << "--------------------------------------------------------------" << endl;


	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      3. erase_one() 예시                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " ▶ BEFORE" << endl << endl;
	b1.show_content();
	cout << " ▶ erase_one 함수로 17 제거" << endl << endl;
	cout << " ▶ AFTER" << endl << endl;
	b1.erase_one(17);
	b1.show_content();
	cout << "--------------------------------------------------------------" << endl;

	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      4. size() 예시                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " ▶ 총 트리 개수는 " << b1.size() << "개 입니다." << endl << endl;
	b1.show_content();
	cout << "--------------------------------------------------------------" << endl;

	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      5. count() 예시                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	b1.insert(13);
	cout << " ▶ 총 데이터가 13인 트리 개수는 " << b1.count(13) << "개 입니다." << endl << endl;
	b1.show_content();
	cout << "--------------------------------------------------------------" << endl;

	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      6. sort() 예시                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " ▶ sort 결과 : ";
	b1.sort();
	cout << endl << endl;
	b1.show_content();
	cout << " ▶ insert(9)를 한뒤 다시 sort() 결과" << endl;
	b1.insert(9);
	cout << " ▶ sort 결과 : ";
	b1.sort();
	cout << endl << endl;
	b1.show_content();
	cout << "--------------------------------------------------------------" << endl;

	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      7. operator = 예시                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " ▶ b1 트리 :" << endl << endl;
	b1.show_content();
	cout << " ▶ b2 트리 :" << endl << endl;
	bag<int> b2;
	b2.insert(2);
	b2.insert(5);
	b2.insert(3);
	b2.insert(1);
	b2.show_content();
	cout << " ▶ operator = 를 이용하여 b2 = b1 연산" << endl;
	cout << " ▶ b2 트리 :" << endl << endl;
	b2 = b1;
	b2.show_content();
	cout << endl << endl;
	cout << "--------------------------------------------------------------" << endl;

	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      7. operator += 예시                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " ▶ b1 트리 :" << endl << endl;
	b1.show_content();
	cout << " ▶ b3 트리 :" << endl << endl;
	bag<int> b3;
	b3.insert(2);
	b3.insert(5);
	b3.insert(3);
	b3.insert(1);
	b3.show_content();
	cout << " ▶ operator = 를 이용하여 b3 += b1 연산" << endl;
	cout << " ▶ b3 트리 :" << endl << endl;
	b3 += b1;
	b3.show_content();
	cout << endl << endl;
	cout << "--------------------------------------------------------------" << endl;


	for (;;) {}


	return 0;
}