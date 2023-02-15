//��ü�Ҹ�ÿ��� �Ҹ��ڸ� ����.
//�տ� ~�� �ٴ´�.
//�����ڿ� ���� ��ȯ���� ����. ��ȯ���� �ʱ� ����.
//������ �� �Ҹ��ڸ� �� ���� ����Ʈ ������ �� �� ����.
//�Ҹ��ڴ� �����ε��� �� �� ����.

#include<iostream>
#include<cstring>
using namespace std;

class Person
{
	char* name;
	int age;
public:
	Person(const char* myname, int myage)	//cpp���� char*��� const char*�� ��� �������� �ȴ�. ������ ����ũ�μ���Ʈ�� ������ �׷����̴�.
	{
		int len = strlen(myname) + 1;	//strlen�� ���� ���� -1�� int ���� �����س���.
		name = new char[len];
		strcpy(name, myname);	//����. ��ó���⿡ _CRT_SECURE_NO_WARNINGS�� �ٿ��� �Ѵ�. ����ũ�μ���Ʈ�� ������ �׷��� �����̴�.
		age = myage;
	}
	void ShowPersonInfo()const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~Person()	//�Ҹ���
	{
		delete[]name;	//new �����ڷ� char[]�� ����Ǿ��� ������ delete[]name���� �����ش�.
		cout << "called destructor!" << endl;
	}
};

int main()
{
	Person man1("LEE", 29);	//char*�� �´� �μ� ������ ���־�22�� �������� ������, const char*�� ""�� �μ� �����̴�.
	Person man2("JANG", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}