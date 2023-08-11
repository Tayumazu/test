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
//test1()结束后自动调用析构函数
void test1()
{
	person p(10);
	system("pause");
}



//多态
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

//animal1是创建在堆区，需要手动释放，而test1是创建在栈区，test1（）运行结束会自动释放，所以会自动调用类的析构函数
void test3() {
	animal* animal1 = new cat("Tom");
	animal1->speak();
	system("pause");
	cout << "delete animal1" << endl;
	delete animal1;//释放animal1内存，并且调用子类析构函数，释放创建在堆中的数据
	system("pause");
}

void test4() {
	fstream fst("test.txt", ios::out);
	//fst.open("test.txt",ios::out);
	fst << "姓名：" << endl;
	fst << "性别：" << endl;
	fst << "nianling：" << endl;
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
