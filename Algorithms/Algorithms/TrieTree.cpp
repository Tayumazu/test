#include<iostream>
using namespace std;
#include<string>
#include<vector>

//ǰ׺��

//�ڵ�
class Node
{
public:
	int pass;
	int end;
	Node * nexts[26];

	Node()
	{
		pass = 0;
		end = 0;
		//26����ĸ�����ַ�����ܶ�ʱ���ù�ϣ�����ʽ��ʾ·
		for (int i = 0; i < 26; i++)
		{
			nexts[i] = nullptr;
		}
	}

	~Node()
	{
		for (int i = 0; i < 26; i++)
		{
			if (nexts[i])
			{
				delete nexts[i];
				nexts[i] = nullptr;
			}
		}
	}

};

class Trietree
{
private:
	Node* root = nullptr;

public:
	Trietree()
	{
		root = new Node;
	}

	//����word
	void insert(string word)
	{
		if (word.empty())
		{
			return;
		}
		Node* cur = root;
		cur->pass++;
		int index = 0;
		for (int i = 0; i < word.size(); i++)
		{
			index = word[i] - 'a';
			if (cur->nexts[index] == nullptr)
			{
				cur->nexts[index] = new Node;
			}
			cur = cur->nexts[index];
			cur->pass++;

		}
		cur->end++;
	}

	//����word�����˼���
	int search(string word)
	{
		if (word.empty())
		{
			return 0;
		}
		Node* cur = root;
		int index = 0;
		for (int i = 0; i < word.size(); i++)
		{
			index = word[i] - 'a';
			if (cur->nexts[index] == nullptr)
			{
				return 0;
			}
			cur = cur->nexts[index];

		}
		return cur->end;
	}

	//���뵥�����м�������preΪǰ׺��
	//Ҳ������node�м����¼ǰ׺���ı���p
	int findprenum(string pre)
	{
		if (pre.empty())
		{
			return 0;
		}

		Node* cur = root;
		int index = 0;
		for (int i = 0; i < pre.size(); i++)
		{
			index = pre[i] - 'a';
			if (cur->nexts[index] == nullptr)
			{
				return 0;
			}
			cur = cur->nexts[index];
		}
		return cur->pass;
	}

	//ɾ��word
	void delete_word(string word)
	{
		if (search(word)==0)
		{
			return;
		}
		Node* cur = root;
		int index = 0;
		for (int i = 0; i < word.size(); i++)
		{
			index = word[i] - 'a';
			if (--cur->nexts[index]->pass == 0)
			{
				delete cur -> nexts[index];
				cur->nexts[index] = nullptr;
				return;
			}
			cur = cur->nexts[index];
		}
		cur->end--;
	}

};



int main()
{
	Trietree mytree;
	mytree.insert("abdf");
	mytree.insert("abdf");
	mytree.insert("abdfew");
	mytree.insert("abdwf");
	mytree.insert("werabdf");
	mytree.insert("werabdf");
	cout << mytree.search("abdf") << endl;
	cout << mytree.findprenum("abd") << endl;
	mytree.delete_word("abdf");
	cout << mytree.search("abdf") << endl;
	cout << mytree.findprenum("abd") << endl;





	system("pause");
	return 0;
}
