#include <iostream>
using namespace std;
#include<fstream>
#include<string>


class person
{
	int age;
public:
	person(int a):age(a)
	{
		cout << "gouzhao" << endl;

	}
	void showage () {
		if (this == NULL) {
return;
		}
		cout << age << endl;
	}
	~person()
	{
		cout << "xigou" << endl;

	}

};
//test1()�������Զ�������������
void test1()
{
	person p(10);
	system("pause");
}



//��̬
class caculator
{
public:

	virtual int getresult() { return 0; };
	int num1;
	int num2;
};
class add :public caculator {
public:
	int getresult() {
		return num1 + num2;
	}

};

class sub :public caculator {
public:
	int getresult() {
		return num1 - num2;
	}

};

class mul :public caculator {
public:
	int getresult() {
		return num1 * num2;
	}

};


void test2() {
	caculator* abc = new add;
	abc->num1 = 10;
	abc->num2 = 20;
	cout << abc->getresult() << endl;
	delete abc;

	abc = new sub;
	abc->num1 = 10;
	abc->num2 = 20;
	cout << abc->getresult() << endl;
	delete abc;

	abc = new mul;
	abc->num1 = 10;
	abc->num2 = 20;
	cout << abc->getresult() << endl;
	delete abc;


}

class animal {
public:
	animal() {
		cout << "animalgouzao" << endl;
	}
	virtual void speak() = 0;
	virtual ~animal() = 0;
};

animal::~animal() {
	cout << "animalxigou" << endl;
}

class cat :public animal {
public:
	cat(string name) {
		cout << "catgouzao" << endl;
		m_name = new string(name);
	}
	void speak() {
		cout << *m_name << "catspeak" << endl;
	}
	~cat() {
		cout << "catxigou" << endl;
		if(this->m_name != NULL){
			delete m_name;
			m_name = NULL;
		}
	}

public:
	string* m_name;
};

//animal1�Ǵ����ڶ�������Ҫ�ֶ��ͷţ���test1�Ǵ�����ջ����test1�������н������Զ��ͷţ����Ի��Զ����������������
void test3() {
	animal* animal1 = new cat("Tom");
	animal1->speak();
	system("pause");
	cout << "delete animal1" << endl;
	delete animal1;//�ͷ�animal1�ڴ棬���ҵ������������������ͷŴ����ڶ��е�����
	system("pause");
}

void test4() {
	fstream fst("test.txt", ios::out);
	//fst.open("test.txt",ios::out);
	fst << "������" << endl;
	fst << "�Ա�" << endl;
	fst << "nianling��" << endl;
	fst.close();
	system("pause");
	fst.open("test.txt", ios::in);
	string buf;
	while (getline(fst, buf))
	{
		cout << buf << endl;
	}
	fst.close();


}


int main() {
	//test1();
	//test2();
	//test3();

	test4();

	system("pause");
	return 0;

}
