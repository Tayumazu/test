#include <iostream>
using namespace std;
#include<math.h>
#include<ctime>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<unordered_map>


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
void printarr(vector<int> arr)
{
	for (auto it = arr.begin(); it!= arr.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

//������������
vector<int> generateRandomArray(int maxSize,int maxValue)
{
	srand((unsigned int)time(NULL));//��������� ͷ�ļ�#include<ctime>:time ͷ�ļ�<stdlib.h>:rand(),srand()
	int arr_size = rand() % (maxSize-9)+10;//rand()��Ҫ����ͷ�ļ�stdlib.h
	//cout << arr_size<<endl;
	vector<int> arr(arr_size);
	for (int i = 0; i < arr_size; i++)
	{
		arr[i] =rand()% (maxValue+1);
	}
	return arr;
}

//ѡ������
void SelectionSort(vector<int>& arr)
{
	
	if (arr.empty() || arr.size() < 2)
	{
		return;
	}
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			
			minIndex = arr[minIndex] < arr[j] ? minIndex: j;
		}
		swap(arr[minIndex], arr[i]);
		
	}
}


//ð������
void bubbleSort(vector<int>& arr) {
	if (arr.empty() || arr.size() < 2)
	{
		return;
	}
	for (int i = arr.size() - 1; i > 0 ; i--)
	{
		for (int j = 0; j < i; j++)
		{
			int maxIndex = arr[j] > arr[j+1] ? j : j+1;
			swap(arr[maxIndex],arr[j+1]);
		}
	}
}

//��������
void insertionSort(vector<int>& arr)
{
	if (arr.empty() || arr.size() < 2)
	{
		return;
	}
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
		{
			swap(arr[j], arr[j + 1]);
		}
	}
}

//�鲢����
void merge(vector<int>& arr, int L, int mid, int R);
void mergeSort(vector<int>& arr,int L,int R)
{
	if (arr.empty())
	{
		return;
	}
	
	if (L==R)
	{
		return;
	}
	int mid = L + ((R - L) >> 1);
	mergeSort(arr, L, mid);
	mergeSort(arr, mid + 1, R);
	merge(arr, L, mid, R);

}
void merge(vector<int>& arr, int L,int mid, int R)
{
	vector<int> help(R-L+1);
	int i = 0;
	int a = L;
	int b = mid + 1;
	while (a <= mid && b <= R)
	{
		help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
	}
	while (a <= mid)
	{
		help[i++] = arr[a++];
	}
	while (b <= R)
	{
		help[i++] = arr[b++];
	}
	for (i = 0; i < help.size(); i++)
	{
		arr[L + i] = help[i];
	}
}

//�����������
vector<int> netherlandsFlag(vector<int>& arr, int L, int R);
//int* netherlandsFlag(vector<int>& arr, int L, int R);
void quickSort(vector<int>& arr,int L, int R)
{
	if (arr.empty())
	{
		return;
	}
	if (L >= R)
	{
		return;
	}
	srand((unsigned int)time(NULL));
	int index_rnd = L+rand() % (R-L+1);
	swap(arr[index_rnd], arr[R]);//���Ԫ����Ϊ�ο�ֵ
	vector<int> equalarea= netherlandsFlag(arr, L, R);
	quickSort(arr, L, equalarea[0] - 1);
	quickSort(arr, equalarea[1] + 1, R);

}

vector<int> netherlandsFlag(vector<int>& arr, int L, int R)
//int * netherlandsFlag(vector<int>& arr, int L, int R)
{
	if (L > R)
	{
		return { -1,-1 };
	}
	if (L == R)
	{
		return { L,R };
	}
	int less = L - 1;
	int more = R;
	int index = L;
	while (index < more)
	{
		if (arr[index] == arr[R])
		{
			index++;
		}
		else if (arr[index] < arr[R])
		{
			swap(arr[index++], arr[++less]);
			//less++;
			//	swap(arr[index], arr[less]);
			//index++;
		}
		else
		{
			swap(arr[index], arr[--more]);
			//more--;
			//swap(arr[index], arr[more]);
		}
	}
	swap(arr[more], arr[R]);
	return { less + 1,more };

}


//������
void heapInsert(vector<int>& arr, int index);
void heapify(vector<int>& arr, int index, int heapSize);
void heapSort(vector<int>& arr)
{
	//ʹ��heapInsert����,�������£�O��n*log(n))
	for (int i = 0; i < arr.size(); i++)//O(n)
	{
		heapInsert(arr, i);//O(log(n))
	}
	//ʹ��heapify����,�������ϣ�O(n)
	//T(N)=N/2*1+N/4*2+N/8*3+...;T(N)=2*T(N)-T(N)=N+N/2+N/4+/8...~������O(N);
	for (int i = arr.size()-1; i >0; i--)
	{
		heapify(arr, i,arr.size());
	}

	int heapSize = arr.size();
	swap(arr[0], arr[--heapSize]);
	while (heapSize > 0)
	{
		heapify(arr, 0, heapSize);
		swap(arr[0], arr[--heapSize]);

	}
}

void heapInsert(vector<int> & arr,int index) 
{
	//arr[index] ������ arr[(index - 1)/2]����index=0ʱֹͣ����
	while (arr[index] > arr[(index - 1)/2])
	{
		swap(arr[index], arr[(index - 1)/2]);
		index= (index - 1) / 2;
	}
}

void heapify(vector<int>& arr, int index, int heapSize)
{
	int left = 2 * index + 1;
	while (left < heapSize)
	{
		int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
		largest = arr[largest] > arr[index] ? largest : index;
		if (largest == index)
		{
			break;
		}
		swap(arr[largest], arr[index]);
		index = largest;
		left = 2 * index + 1;
	}
}


//��������
void countSort(vector<int>& arr,int length)
{
	vector<int> count(length,0);
	for (int i = 0; i < arr.size();i++)
	{
		count[arr[i]]++;
	}
	int index = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			arr[index++] = i;
		}
	}
}

//��������




int main()
{
	int a = 1;
	int b = 4;
	cout << "a=" << a << endl << "b=" << b<<endl;
	swap(a, b);
	cout << "-----------------" << endl;
	cout << "a=" << a << endl << "b=" << b<<endl;

	int maxSize=20;
	int maxValue=30;
	vector<int> arr = generateRandomArray(maxSize,maxValue);
	printarr(arr);

	////SelectionSort(arr);
	////bubbleSort(arr);
	////insertionSort(arr);
	//mergeSort(arr, 0, arr.size()-1);
	//quickSort(arr, 0, arr.size() - 1);
	//heapSort(arr);
	countSort(arr, 30);
	printarr(arr);



	//delete arr;
	system("pause");
	return 0;
}