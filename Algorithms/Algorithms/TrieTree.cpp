#include<iostream>
using namespace std;
#include<string>
#include<vector>

//前缀树

//节点
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
		//26个字母；当字符种类很多时可用哈希表的形式表示路
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

	//加入word
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

	//搜索word加入了几次
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

	//加入单词中有几个是以pre为前缀的
	//也可在类node中加入记录前缀数的变量p
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

	//删除word
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
