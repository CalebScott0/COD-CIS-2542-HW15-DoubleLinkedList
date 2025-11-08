#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>
#include <ostream>

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void pop_front();
    void push_front(long long v);

    //long long operator [] (int idx);

    bool empty() const;
    int size() const;
    void insert(int idx, long long val);
    void erase(int idx);

    friend std::ostream& operator << (std::ostream& ostrm, const LinkedList& right);

private:
    struct ListNode
    {
        ListNode(long long v, ListNode* prev = nullptr, ListNode* n = nullptr);

        long long value;
        struct ListNode* previous;
        struct ListNode* next;
    };

    ListNode* head;
};

#endif
