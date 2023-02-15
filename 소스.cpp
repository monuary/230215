//객체소멸시에는 소멸자를 쓴다.
//앞에 ~가 붙는다.
//생성자와 같이 반환형이 없다. 반환하지 않기 때문.
//생성자 및 소멸자를 쓸 때엔 디폴트 설정을 할 수 없다.
//소멸자는 오버로딩을 할 수 없다.

#include<iostream>
#include<cstring>
using namespace std;

class Person
{
	char* name;
	int age;
public:
	Person(const char* myname, int myage)	//cpp에서 char*대신 const char*를 써야 컴파일이 된다. 이유는 마이크로소프트의 기준이 그래서이다.
	{
		int len = strlen(myname) + 1;	//strlen이 문자 길이 -1의 int 값을 도출해낸다.
		name = new char[len];
		strcpy(name, myname);	//복사. 전처리기에 _CRT_SECURE_NO_WARNINGS를 붙여야 한다. 마이크로소프트의 기준이 그렇기 때문이다.
		age = myage;
	}
	void ShowPersonInfo()const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()	//소멸자
	{
		delete[]name;	//new 연산자로 char[]가 선언되었기 때문에 delete[]name으로 지워준다.
		cout << "called destructor!" << endl;
	}
};

int main()
{
	Person man1("LEE", 29);	//char*에 맞는 인수 형식은 비주얼22에 존재하지 않지만, const char*는 ""가 인수 형식이다.
	Person man2("JANG", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}