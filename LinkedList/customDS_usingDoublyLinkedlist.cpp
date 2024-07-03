#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        data = 0;
        prev = nullptr;
        next = nullptr;
    }
    Node(int d)
    {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};

class LinkedList
{
    Node *dummy, *head, *curr, *tail;
    int size;
    int currInd;

public:
    LinkedList()
    {
        dummy = new Node();
        curr = nullptr;
        head = nullptr;
        tail = nullptr;
        size = 0;
        currInd = -1;
    }
    void addAtFirst(int data)
    {
        Node *node = new Node(data);
        if (size == 0)
        {
            head = node;
            dummy->next = node;
            head->prev = dummy;
            tail = head;
        }
        else
        {
            head->prev = node;
            node->next = head;
            head = node;
        }
        size++;
        currInd = 0;
        curr = head;
    }
    void addAtLast(int data)
    {
        Node *node = new Node(data);
        if (size == 0)
        {
            head = node;
            dummy->next = node;
            head->prev = dummy;
            tail = head;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
        currInd = size - 1;
        curr = tail;
    }
    void addHere(int data)
    {
        Node *node = new Node(data);
        if (size == 0)
        {
            head = node;
            head->prev = dummy;
            dummy->next = head;
            tail = head;
            curr = head;
        }
        else if (curr->prev)
        {
            curr->prev->next = node;
            node->prev = curr->prev;
            node->next = curr;
            curr->prev = node;
            curr = node;
        }
        size++;
    }
    void goForward()
    {
        if (curr->next)
        {
            currInd++;
            curr = curr->next;
        }
    }
    void goBackward()
    {
        if (curr->prev != dummy && curr->prev)
        {
            currInd--;
            curr = curr->prev;
        }
    }
    int getCurr()
    {
        return curr->data;
    }
    int getCurrInd()
    {
        return currInd;
    }
    void updateCurr(int data)
    {
        curr->data = data;
    }
    void removeCurr()
    {
        if (curr == dummy || size == 0)
        {
            return;
        }
        if (curr == head)
        {
            head = curr->next;
            head->prev = dummy;
        }
        else if (curr == tail)
        {
            tail = curr->prev;
            tail->next = nullptr;
        }
        else
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        delete curr;
        size--;
    }
    void removeFirst()
    {
        if (head == dummy)
        {
            return;
        }
        if (head->next)
        {
            head->next->prev = dummy;
        }
        head = head->next;
        size--;
        currInd--;
    }
    void removeLast()
    {
        if (tail == dummy)
        {
            return;
        }
        tail->prev->next = nullptr;
        tail = tail->prev;
        size--;
    }
    int getFirst()
    {
        return head->data;
    }
    int getLast()
    {
        return tail->data;
    }
    vector<int> getList()
    {
        vector<int> v;
        Node *temp = head;
        while (temp)
        {
            v.push_back(temp->data);
            temp = temp->next;
        }
        return v;
    }
    int getSize()
    {
        return size;
    }
};

void printList(vector<int> &v)
{
    cout << "List: ";
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    cout << "-------------------------------------\n";
    cout << "|              LinkedList           |\n";
    cout << "-------------------------------------\n";
    int n;
    cout << "Enter the number of data you want to add to list:\n";
    cin >> n;
    LinkedList list;
    cout << "Now enter all the data:\n";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        list.addAtLast(num);
    }
    cout << "Size: " << list.getSize() << endl;
    vector<int> v = list.getList();
    printList(v);
    cout << "First element: " << list.getFirst() << endl;
    cout << "Last element: " << list.getLast() << endl;
    cout << "Current index: " << list.getCurrInd() << endl;
    cout << "Current element: " << list.getCurr() << endl;
    list.goBackward();
    cout << "Current element after 1 backward: " << list.getCurr() << endl;
    list.goBackward();
    cout << "Current element after 2 backward: " << list.getCurr() << endl;
    list.goForward();
    cout << "Current element after 1 forward: " << list.getCurr() << endl;
    list.goForward();
    cout << "Current element after 2 forward: " << list.getCurr() << endl;
    cout << "Adding 57 to the first\n";
    list.addAtFirst(57);
    v = list.getList();
    printList(v);
    cout << "Current index: " << list.getCurrInd() << endl;
    cout << "Going 1 step forward\n";
    list.goForward();
    cout << "Current index: " << list.getCurrInd() << endl;
    cout << "Now adding -87 here\n";
    list.addHere(-87);
    v = list.getList();
    printList(v);
    cout << "Going 1 step forward\n";
    list.goForward();
    cout << "Current index: " << list.getCurrInd() << endl;
    cout << "Now adding 155 here\n";
    list.addHere(155);
    v = list.getList();
    printList(v);
    cout << "Current index: " << list.getCurrInd() << endl;
    cout << "Current element: " << list.getCurr() << endl;
    cout << "Now updating current element to 999\n";
    list.updateCurr(999);
    v = list.getList();
    printList(v);
    cout << "Now deleting the first element\n";
    list.removeFirst();
    v = list.getList();
    printList(v);
    cout << "Current index: " << list.getCurrInd() << endl;
    cout << "Current element: " << list.getCurr() << endl;
    cout << "Now deleting the last element\n";
    list.removeLast();
    v = list.getList();
    printList(v);
    cout << "Current index: " << list.getCurrInd() << endl;
    cout << "Current element: " << list.getCurr() << endl;
    cout << "Now deleting the current element\n";
    list.removeCurr();
    v = list.getList();
    printList(v);
    return 0;
}