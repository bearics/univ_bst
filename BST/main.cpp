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
	cout << "*                      1. insert() ����                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " �� BEFORE" << endl << endl;
	b1.show_content();
	cout << " �� insert �Լ��� 13, 10, 22, 19, 22, 65 �߰�" << endl << endl;
	cout << " �� AFTER" << endl << endl;
	b1.insert(13);
	b1.insert(10);
	b1.insert(22);
	b1.insert(19);
	b1.insert(22);
	b1.insert(65);
	b1.show_content();
	cout << "--------------------------------------------------------------" << endl;

	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      2. erase() ����                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " �� BEFORE" << endl << endl;
	b1.show_content();
	cout << endl << " �� erase �Լ��� 22�� " << b1.erase(22) << "�� ����" << endl;
	cout << " �� AFTER" << endl << endl;
	b1.show_content();
	cout << "--------------------------------------------------------------" << endl;


	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      3. erase_one() ����                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " �� BEFORE" << endl << endl;
	b1.show_content();
	cout << " �� erase_one �Լ��� 17 ����" << endl << endl;
	cout << " �� AFTER" << endl << endl;
	b1.erase_one(17);
	b1.show_content();
	cout << "--------------------------------------------------------------" << endl;

	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      4. size() ����                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " �� �� Ʈ�� ������ " << b1.size() << "�� �Դϴ�." << endl << endl;
	b1.show_content();
	cout << "--------------------------------------------------------------" << endl;

	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      5. count() ����                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	b1.insert(13);
	cout << " �� �� �����Ͱ� 13�� Ʈ�� ������ " << b1.count(13) << "�� �Դϴ�." << endl << endl;
	b1.show_content();
	cout << "--------------------------------------------------------------" << endl;

	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      6. sort() ����                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " �� sort ��� : ";
	b1.sort();
	cout << endl << endl;
	b1.show_content();
	cout << " �� insert(9)�� �ѵ� �ٽ� sort() ���" << endl;
	b1.insert(9);
	cout << " �� sort ��� : ";
	b1.sort();
	cout << endl << endl;
	b1.show_content();
	cout << "--------------------------------------------------------------" << endl;

	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      7. operator = ����                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " �� b1 Ʈ�� :" << endl << endl;
	b1.show_content();
	cout << " �� b2 Ʈ�� :" << endl << endl;
	bag<int> b2;
	b2.insert(2);
	b2.insert(5);
	b2.insert(3);
	b2.insert(1);
	b2.show_content();
	cout << " �� operator = �� �̿��Ͽ� b2 = b1 ����" << endl;
	cout << " �� b2 Ʈ�� :" << endl << endl;
	b2 = b1;
	b2.show_content();
	cout << endl << endl;
	cout << "--------------------------------------------------------------" << endl;

	cout << "--------------------------------------------------------------" << endl;
	cout << "*                      7. operator += ����                        *" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " �� b1 Ʈ�� :" << endl << endl;
	b1.show_content();
	cout << " �� b3 Ʈ�� :" << endl << endl;
	bag<int> b3;
	b3.insert(2);
	b3.insert(5);
	b3.insert(3);
	b3.insert(1);
	b3.show_content();
	cout << " �� operator = �� �̿��Ͽ� b3 += b1 ����" << endl;
	cout << " �� b3 Ʈ�� :" << endl << endl;
	b3 += b1;
	b3.show_content();
	cout << endl << endl;
	cout << "--------------------------------------------------------------" << endl;


	for (;;) {}


	return 0;
}