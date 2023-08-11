#include <iostream>
using namespace std;
#include<math.h>
#include<ctime>
#include<stdlib.h>
#include<vector>


//�������ݣ����ô���
void swap(int& a, int& b) 
{
	if (a == b)
	{
		return;
	}
	/*int temp = a;
	a = b;
	b = temp;*/
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//��ӡ����
void printarr(int* arr,int sumofnum)
{
	for (int i = 0; i < sumofnum; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

////������������
//int *generateRandomArray(int maxSize,int maxValue)
//{
//	srand((unsigned int)time(NULL));
//	int arr_size = rand() % (maxSize);
//	cout << arr_size<<endl;
//	int *arr=new int(arr_size);
//	for (int i = 0; i < arr_size; i++)
//	{
//		srand((unsigned int)time(NULL));//��������� ͷ�ļ�#include<ctime>:time ͷ�ļ�<stdlib.h>:rand(),srand()
//		arr[i] =rand()% (maxValue+1);
//		cout << arr[i] << endl;
//	}
//	return arr;
//}

//ѡ������
void SelectionSort(int *arr, int sumofnum)
{
	
	if (arr == NULL || sumofnum < 2)
	{
		return;
	}
	for (int i = 0; i < sumofnum - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < sumofnum; j++) 
		{
			
			minIndex = arr[minIndex] < arr[j] ? minIndex: j;
		}
		swap(arr[minIndex], arr[i]);
		
	}
}


//ð������
void bubbleSort(int arr[], int sumofnum) {
	if (arr == NULL || sumofnum < 2)
	{
		return;
	}
	for (int i = sumofnum - 1; i > 0 ; i--)
	{
		for (int j = 0; j < i; j++)
		{
			int maxIndex = arr[j] > arr[j+1] ? j : j+1;
			swap(arr[maxIndex],arr[j+1]);
		}
	}
}

//��������
void insertionSort(int arr[], int sumofnum)
{
	if (arr == NULL || sumofnum < 2)
	{
		return;
	}
	for (int i = 1; i < sumofnum; i++)
	{
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
		{
			swap(arr[j], arr[j + 1]);
		}
	}
}


int main()
{
	int a = 1;
	int b = 4;
	cout << "a=" << a << endl << "b=" << b<<endl;
	swap(a, b);
	cout << "-----------------" << endl;
	cout << "a=" << a << endl << "b=" << b<<endl;
	vector<int> arr = { 1,4,2,5,3 };
	
	//int arr[5] = { 1,4,2,5,3 };
	//int sumofnum = sizeof(arr) / sizeof(arr[0]);
	//printarr(arr,sumofnum);
	//SelectionSort(arr, sumofnum);
	//bubbleSort(arr, sumofnum);
	//insertionSort(arr, sumofnum);
	//printarr(arr, sumofnum);
	//cout << arr;


	//int *arr = generateRandomArray(20, 100);
	////int sumofnum = sizeof(arr) / sizeof(arr[0]);
	////printarr(arr, sumofnum);
	////cout << sumofnum;

	//delete arr;
	system("pause");
	return 0;
}