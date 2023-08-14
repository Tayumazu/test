#include <iostream>
using namespace std;
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<unordered_map>
#include<queue>
#include<set>




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

//函数对象，仿函数
class myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}

};



void test5()
{
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i * 5);
	}


	for_each(v1.begin(), v1.end(), myprint());
	cout << endl;

	for_each(v2.begin(), v2.end(), myprint());
	cout << endl;

	vector<int> v_target1(max(v1.size(), v2.size()));
	cout << "v1 and v2 difference:" << endl;
	vector<int>::iterator itend1 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v_target1.begin());
	for_each(v_target1.begin(), itend1, myprint());
	cout << endl;

	vector<int> v_target2(max(v1.size(), v2.size()));
	cout << "v2 and v1 difference:" << endl;
	vector<int>::iterator itend2 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v_target2.begin());
	for_each(v_target2.begin(), itend2, myprint());
	cout << endl;

}

void test6()
{
	vector<int> v1(20);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(33);
	v1.push_back(31);
	v1.push_back(23);
	v1.push_back(13);
	v1.push_back(43);
	v1.push_back(312);
	cout<<accumulate(v1.begin(), v1.end(), 33)<<endl;
	for_each(v1.begin(), v1.end(), myprint());
	cout << endl;
	fill(v1.begin(), --v1.end(), 1);
	for_each(v1.begin(), v1.end(), myprint());
	cout << endl;
}

void test7()
{
	unordered_map<string, int> m;
	m["lihua"] = 100;
	m["zhangsahn"] = 1231;
	m["swk"] = 12;
	m["za"] = 21;
	m["sdad"] = 24;
	//m.insert(pair<string,int>("swk",12));
	//m.insert(make_pair("za",21));
	//m.insert(map<string,int>::value_type("sdad",24));

	
	for (auto it = m.begin(); it != m.end(); it++) 
	{
		cout << it->first << ":" << it->second << endl;
	}
}


void test8()
{
	queue<int> p_q;
	p_q.push(3);
	p_q.push(5);
	p_q.push(2);
	p_q.push(7);
	p_q.push(1);
	p_q.push(9);
	p_q.push(8);
	p_q.push(0);
	for (int i = 0; !p_q.empty(); i++)
	{

		cout << p_q.front() << endl;
		p_q.pop();
	}

	priority_queue<int,vector<int>,greater<int>> p_q1;
	p_q1.push(3);
	p_q1.push(5);
	p_q1.push(2);
	p_q1.push(7);
	p_q1.push(1);
	p_q1.push(9);
	p_q1.push(8);
	p_q1.push(0);
	for (int i = 0; ! p_q1.empty(); i++)
	{
		
		cout << p_q1.top() << endl;
		p_q1.pop();
	}
}


int main() {
	//test1();
	//test2();
	//test3();

	//test4();

	//test5();
	//test6();
	//test7();
	test8();

	system("pause");
	return 0;

}
