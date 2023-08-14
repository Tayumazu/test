#include "MYarray.hpp"
#include <string>
#include<vector>

void printintarray(myarray<int>& arr) {
	for (int i = 0; i < arr.getsize(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//测试内置数据类型
void test1()
{
	myarray<int> array1(10);
	for (int i = 0; i < 9; i++)
	{
		array1.push_back(i);
	}
	cout << "array1:" << endl;
	printintarray(array1);
	cout << "array1_size:" << array1.getsize() << endl;
	cout << "array1_capacity:" << array1.getcapacity() << endl;
	cout << "---------------------------------" << endl;

	myarray<int>array2(array1);
	printintarray(array2);
	cout << "array2_size:" << array2.getsize() << endl;
	cout << "array2_capacity:" << array2.getcapacity() << endl;

}

//测试自定义数据
class person
{
public:
	person() {}
	person(string name,int age):m_name(name),m_age(age) {}

public:
	string m_name;
	int m_age;
};
void printpersonarray(myarray<person>& personarr) {
	for (int i = 0; i < personarr.getsize(); i++) {
		cout << "name:" << personarr[i].m_name << "age:" << personarr[i].m_age << endl;;
	}

}

void test2() {
	myarray<person> parr(10);
	person p1("孙悟空",30);
	person p2("hx",20);
	person p3("dj", 18);
	person p4("wzj", 15);
	person p5("zy", 24);

	parr.push_back(p1);
	parr.push_back(p2);
	parr.push_back(p3);
	parr.push_back(p4);
	parr.push_back(p5);

	printpersonarray(parr);
	cout << "parr_size:" << parr.getsize() << endl;
	cout << "parr_capacity" << parr.getcapacity() << endl;
}



int main() {
	//test1();
	//test2();
	vector<int> vec;
	for (int i = 0; i < 10; i++) {
		vec.push_back(i);
	}
	
	vector<int>::iterator it = vec.begin();
	
	vec.insert(++it, 11);
	cout << vec.size() << endl;
	for (int i = 0; i <vec.size(); i++) {
		cout<<vec[i]<<endl;
	}


	system("pause");
	return 0;
}