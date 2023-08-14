#pragma once
#include<iostream>
using namespace std;

template<typename T>
class myarray
{
private:
	T* paddress;//ָ��һ���ѿռ䣬�洢����������
	int m_capacity;//����
	int m_size;//��С
public:
	//���캯��
	myarray(int capacity)
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		this->paddress = new T[m_capacity];
	}

	//��������
	myarray(const myarray& arr)
	{
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->paddress = new T[this->m_capacity];//���
		for (int i = 0; i < this->m_size; i++) {
			//��TΪ�����Ұ���ָ�룬���������=����������Ϊ����ȺŲ��ǹ�����Ǹ�ֵ
			//��ͨ���Ϳ���ֱ����=��ָ������Ҫ���
			this->paddress[i] = arr.paddress[i];
		}
	}

	//����=����ֹǳ��������
	myarray& operator=(const myarray& Myarray) {
		if (this->paddress != NULL) {
			delete[] this->paddress;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = Myarray.m_capacity;
		this->m_size = Myarray.m_size;
		this->paddress = new T[this->m_capacity];//���
		for (int i = 0; i < this->m_size; i++) {
			this->paddress[i] = Myarray.paddress;
		}
		return *this;
	}

	//����[]��������a[]
	T& operator[](int index) {
		return this->paddress[index];//������Խ�磬�û��Լ�����
	}

	//β�巨
	void push_back(const T& val)
	{
		if (this->m_capacity == this->m_size) {
			return;
		}
		this->paddress[this->m_size] = val;
		this->m_size++;
	}
	
	//βɾ��
	void pop_back() {
		if (this->msize == 0) {
			return;
		}
		this->size--;
	}

	//��ȡ��������
	int getcapacity() {
		return this->m_capacity;
	}

	//��ȡ�����С
	int getsize() {
		return this->m_size;
	}

	//����
	~myarray() {
		if (this->paddress != NULL) {
			delete[] this->paddress;
			this->paddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;

		}
	}


};

