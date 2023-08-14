#pragma once
#include<iostream>
using namespace std;

template<typename T>
class myarray
{
private:
	T* paddress;//指向一个堆空间，存储真正的数据
	int m_capacity;//容量
	int m_size;//大小
public:
	//构造函数
	myarray(int capacity)
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		this->paddress = new T[m_capacity];
	}

	//拷贝函数
	myarray(const myarray& arr)
	{
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->paddress = new T[this->m_capacity];//深拷贝
		for (int i = 0; i < this->m_size; i++) {
			//若T为对象，且包含指针，则必须重载=操作符，因为这个等号不是构造而是赋值
			//普通类型可以直接用=但指针类型要深拷贝
			this->paddress[i] = arr.paddress[i];
		}
	}

	//重载=，防止浅拷贝问题
	myarray& operator=(const myarray& Myarray) {
		if (this->paddress != NULL) {
			delete[] this->paddress;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = Myarray.m_capacity;
		this->m_size = Myarray.m_size;
		this->paddress = new T[this->m_capacity];//深拷贝
		for (int i = 0; i < this->m_size; i++) {
			this->paddress[i] = Myarray.paddress;
		}
		return *this;
	}

	//重载[]操作符，a[]
	T& operator[](int index) {
		return this->paddress[index];//不考虑越界，用户自己处理
	}

	//尾插法
	void push_back(const T& val)
	{
		if (this->m_capacity == this->m_size) {
			return;
		}
		this->paddress[this->m_size] = val;
		this->m_size++;
	}
	
	//尾删法
	void pop_back() {
		if (this->msize == 0) {
			return;
		}
		this->size--;
	}

	//获取数组容量
	int getcapacity() {
		return this->m_capacity;
	}

	//获取数组大小
	int getsize() {
		return this->m_size;
	}

	//析构
	~myarray() {
		if (this->paddress != NULL) {
			delete[] this->paddress;
			this->paddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;

		}
	}


};

