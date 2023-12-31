#include <iostream>
using namespace std;

//单向链表模板
class SingleList
{
private:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int x) :val(x), next(nullptr) {}
    };
    ListNode* head;
public:
    SingleList() :head(nullptr) {}

    //获得链表中第index个节点的值
    int get(int index) {
        int i = 0;
        ListNode* p = head;
        while (p && i < index) {
            p = p->next;
            i++;
        }
        if (p)return p->val;
        else return -1;
    }

    //在链表头部插一个值为val的节点
    void addAtHead(int val) {
        ListNode* p = new ListNode(val);
        p->next = head;
        head = p;//更换头节点
    }

    //在链表尾部添加一个值为val的节点
    void addAtTail(int val) {
        ListNode* p = new ListNode(val);
        //链表为空，直接将新节点作为头节点
        if (head == nullptr) {
            head = p;
            return;
        }
        ListNode* q = head;
        //遍历直到q的next节点为空
        while (q->next) {
            q = q->next;
        }
        q->next = p;
    }

    //在索引为index的节点之前添加值为val的节点
    void addAtIndex(int index, int val) {
        ListNode* node = new ListNode(val);
        //1、index小于等于0，直接在头部插入节点
        if (index <= 0)
        {//若index小于等于0，我们仅需要在头节点前面插入新节点就行了
        //注意这里不能使用指针p，因为p=node时，p所指向的地址发生了变化，head指向的地址没有变化，所以我们这里要使用指针head
            node->next = head;
            head = node;
            return;
        }
        int i = 0;
        ListNode* p = head;
        //在索引为index的节点之前插入新节点，我们需要找到它的前驱节点，然后插入在它的前驱节点后面
        while (p && i < index - 1)
        {
            p = p->next;
            ++i;
        }
        //2、p为索引节点的前驱节点
        if (p)
        {
            node->next = p->next;
            p->next = node;
        }
    }

    //删除索引为index的节点
    void deleteAtIndex(int index) {
        //1、index为0，我们直接删除head节点
        if (index == 0 && head != nullptr)
        {
            ListNode* del = head;
            head = head->next;
            delete del;
            return;
        }
        int i = 0;
        ListNode* p = head;
        //删除索引为index的节点，我们需要找到它的前驱节点p，p->next为需要删除节点
        while (p && i < index - 1)
        {
            p = p->next;
            i++;
        }
        //2、index超过链表范围，删除失败
        if (!p)return;
        //3、index的位置合法，我们找到需要删除的p->next节点
        if (p->next)
        {
            ListNode* del = p->next;
            p->next = del->next;
            delete del;
        }
    }

    int length() {
        int i = 0;
        ListNode* p = head;
        while (p) {
            i++;
            p = p->next;
        }
        return i;
    }
};

//双向链表模板
class DoubleList
{
private:
    struct ListNode
    {
        int val;
        ListNode* next, * pre;
        ListNode(int x) :val(x), next(nullptr), pre(nullptr) {}
    };
private:
    //头节点尾节点都为空，表示为空链表
    ListNode* head, * tail;
    int size = 0;
public:
    DoubleList() :size(0), head(nullptr), tail(nullptr) {}

    int get(int index) {
        int i = 0;
        ListNode* p = head;
        while (p && i < index) {
            p = p->next;
            i++;
        }
        if (p)return p->val;
        else return -1;
    }

    void addAtHead(int val) {
        if (head != nullptr) {
            ListNode* node = new ListNode(val);
            node->next = head;
            head->pre = node;
            head = node;
        }
        else {
            head = new ListNode(val);
            tail = head;
        }
        ++size;
    }

    void addAtTail(int val) {
        if (tail != nullptr) {
            ListNode* node = new ListNode(val);
            node->pre = tail;
            tail->next = node;
            tail = node;
        }
        else {//尾节点为空，那么头节点也为空，然后首尾节点都为新节点
            tail = new ListNode(val);
            head = tail;
        }
        ++size;
    }

    void addAtIndex(int index, int val) {
        //首先排除三种特殊情况的index，然后剩下来的index肯定在链表内
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        if (index > size)return;
        ListNode* p = nullptr, * cur = head;
        int i = 0;
        while (cur && i < index) {
            p = cur;
            cur = cur->next;
            i++;
        }
        ListNode* node = new ListNode(val);
        //由于前面已经将特殊情况的index排除了，现在的p和cur都有效，都在链表内
        p->next = node;
        node->pre = p;
        node->next = cur;
        cur->pre = node;
        size++;
    }

    void deleteAtIndex(int index) {
        //链表为空时，不能删除
        if (!head)return;
        if (index == 0)
        {
            ListNode* del = head;
            head = head->next;
            if (head) {//链表有2个以上节点
                head->pre = nullptr;
            }
            else {//链表只有一个节点，将尾部制空
                tail = nullptr;
            }
            delete del;
            size--;
            return;
        }
        //index为最后为尾节点，我们需要删除尾节点
        if (index == size - 1) {
            ListNode* del = tail;
            tail = tail->pre;
            //注意这里不用处理tail为空，因为tail为空的话，那么链表只有单个节点
            //然而单个节点只能删除0号节点，只有index为0时才能删除，前面已经处理过了index为0的情况了，所以这里不在处理
            if (tail) {
                tail->next = nullptr;
            }
            delete del;
            size--;
            return;
        }
        int i = 0;
        ListNode* p = nullptr, * cur = head;
        while (cur) {
            if (i == index) {
                ListNode* del = cur;
                p->next = cur->next;
                if (cur->next) {
                    cur->next->pre = p;
                }
                delete del;
                size--;
                return;
            }
            p = cur;
            cur = cur->next;
            ++i;
        }
    }

    int length() {
        return size;
    }
};




void test1() {
    SingleList List1;
    List1.addAtIndex(0, 10);
    List1.addAtIndex(0, 20);
    List1.addAtIndex(1, 30);
    for (int i = 0; i < List1.length(); ++i) {
        cout << List1.get(i) << " ";
    }
    cout << endl;
}

void test2() {
    DoubleList List2;
    List2.addAtHead(1);
    List2.addAtTail(3);
    List2.addAtHead(4);
    List2.addAtHead(5);
    List2.addAtIndex(1, 2);
    for (int i = 0; i < List2.length(); ++i) {
        cout << List2.get(i) << " ";
    }
    cout << endl;
    List2.deleteAtIndex(1);
    for (int i = 0; i < List2.length(); ++i) {
        cout << List2.get(i) << " ";
    }
    cout << endl;
}

int main()
{
    test1();
    test2();
    system("pause");
}
