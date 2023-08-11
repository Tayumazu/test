#include <iostream>
using namespace std;

//��������ģ��
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

    //��������е�index���ڵ��ֵ
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

    //������ͷ����һ��ֵΪval�Ľڵ�
    void addAtHead(int val) {
        ListNode* p = new ListNode(val);
        p->next = head;
        head = p;//����ͷ�ڵ�
    }

    //������β�����һ��ֵΪval�Ľڵ�
    void addAtTail(int val) {
        ListNode* p = new ListNode(val);
        //����Ϊ�գ�ֱ�ӽ��½ڵ���Ϊͷ�ڵ�
        if (head == nullptr) {
            head = p;
            return;
        }
        ListNode* q = head;
        //����ֱ��q��next�ڵ�Ϊ��
        while (q->next) {
            q = q->next;
        }
        q->next = p;
    }

    //������Ϊindex�Ľڵ�֮ǰ���ֵΪval�Ľڵ�
    void addAtIndex(int index, int val) {
        ListNode* node = new ListNode(val);
        //1��indexС�ڵ���0��ֱ����ͷ������ڵ�
        if (index <= 0)
        {//��indexС�ڵ���0�����ǽ���Ҫ��ͷ�ڵ�ǰ������½ڵ������
        //ע�����ﲻ��ʹ��ָ��p����Ϊp=nodeʱ��p��ָ��ĵ�ַ�����˱仯��headָ��ĵ�ַû�б仯��������������Ҫʹ��ָ��head
            node->next = head;
            head = node;
            return;
        }
        int i = 0;
        ListNode* p = head;
        //������Ϊindex�Ľڵ�֮ǰ�����½ڵ㣬������Ҫ�ҵ�����ǰ���ڵ㣬Ȼ�����������ǰ���ڵ����
        while (p && i < index - 1)
        {
            p = p->next;
            ++i;
        }
        //2��pΪ�����ڵ��ǰ���ڵ�
        if (p)
        {
            node->next = p->next;
            p->next = node;
        }
    }

    //ɾ������Ϊindex�Ľڵ�
    void deleteAtIndex(int index) {
        //1��indexΪ0������ֱ��ɾ��head�ڵ�
        if (index == 0 && head != nullptr)
        {
            ListNode* del = head;
            head = head->next;
            delete del;
            return;
        }
        int i = 0;
        ListNode* p = head;
        //ɾ������Ϊindex�Ľڵ㣬������Ҫ�ҵ�����ǰ���ڵ�p��p->nextΪ��Ҫɾ���ڵ�
        while (p && i < index - 1)
        {
            p = p->next;
            i++;
        }
        //2��index��������Χ��ɾ��ʧ��
        if (!p)return;
        //3��index��λ�úϷ��������ҵ���Ҫɾ����p->next�ڵ�
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

//˫������ģ��
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
    //ͷ�ڵ�β�ڵ㶼Ϊ�գ���ʾΪ������
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
        else {//β�ڵ�Ϊ�գ���ôͷ�ڵ�ҲΪ�գ�Ȼ����β�ڵ㶼Ϊ�½ڵ�
            tail = new ListNode(val);
            head = tail;
        }
        ++size;
    }

    void addAtIndex(int index, int val) {
        //�����ų��������������index��Ȼ��ʣ������index�϶���������
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
        //����ǰ���Ѿ������������index�ų��ˣ����ڵ�p��cur����Ч������������
        p->next = node;
        node->pre = p;
        node->next = cur;
        cur->pre = node;
        size++;
    }

    void deleteAtIndex(int index) {
        //����Ϊ��ʱ������ɾ��
        if (!head)return;
        if (index == 0)
        {
            ListNode* del = head;
            head = head->next;
            if (head) {//������2�����Ͻڵ�
                head->pre = nullptr;
            }
            else {//����ֻ��һ���ڵ㣬��β���ƿ�
                tail = nullptr;
            }
            delete del;
            size--;
            return;
        }
        //indexΪ���Ϊβ�ڵ㣬������Ҫɾ��β�ڵ�
        if (index == size - 1) {
            ListNode* del = tail;
            tail = tail->pre;
            //ע�����ﲻ�ô���tailΪ�գ���ΪtailΪ�յĻ�����ô����ֻ�е����ڵ�
            //Ȼ�������ڵ�ֻ��ɾ��0�Žڵ㣬ֻ��indexΪ0ʱ����ɾ����ǰ���Ѿ��������indexΪ0������ˣ��������ﲻ�ڴ���
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
