#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <ostream>

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void push_front(long long int v);

    friend std::ostream& operator << (std::ostream& ostrm, const LinkedList& right);

private:
    struct ListNode
    {
        ListNode(long long int v, ListNode* prev = nullptr, ListNode* n = nullptr);

        long long int value;
        struct ListNode* previous;
        struct ListNode* next;
    };

    ListNode* head;
};

#endif
