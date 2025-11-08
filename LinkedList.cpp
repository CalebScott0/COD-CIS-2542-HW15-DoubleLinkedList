#include "LinkedList.h"
#include <cstddef>

LinkedList::LinkedList()
    : head(nullptr)
{
    // Empty  
}

LinkedList::~LinkedList()
{
    // TODO: FILL IN
}

// ListNode struct constructor
LinkedList::ListNode::ListNode(long long v, ListNode* prev, ListNode* n)
    : value(v),
      previous(prev),
      next(n)
{
    // Empty
}

void LinkedList::pop_front()
{
    if(head)
    {
        head->next->previous = nullptr;
        head = head->next;
    }
}

void LinkedList::push_front(long long v)
{
    ListNode* newNode = new ListNode(v);

    if(!head)
    {
        head = newNode;
    }
    else
    {
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
    }
}

bool LinkedList::empty() const
{
    return (head == nullptr);
}

int LinkedList::size() const
{
    int count = 0;
    ListNode* current = head;
    while(current)
    {
        ++count;
        current = current->next;
    }

    return count;

}

void LinkedList::insert(int idx, long long val)
{
    ListNode* newNode = new ListNode(val);
    // inserting at head of list
    if(idx == 0)
    {
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
    }
    else
    {
        int currentIdx = 0;
        ListNode* current = head;
        while(current->next && currentIdx != idx)
        {
            ++currentIdx;
            current = current->next;
        }
        // inserting at end
        if(!current->next)
        {
            newNode->previous = current;
            current->next = newNode;
        }
        else
        {
            current->previous->next = newNode;
            newNode->previous = current->previous;
            current->previous = newNode;
            newNode->next = current;
        }
    }

}

void LinkedList::erase(int idx)
{
    // erase head
    if(idx == 0)
    {
        head = head->next;
        delete head->previous;
        head->previous = nullptr;
    }

    int currentIdx = 0;
    ListNode* current = head;
    while(current->next && currentIdx != idx)
    {
        ++currentIdx;
        current = current->next;
    }
    if(currentIdx == idx)
    {

    }
};

//long long LinkedList::operator [] (int idx)
//{
    //int count = 0;
    //ListNode* current = head;
//
//}

std::ostream& operator << (std::ostream& ostrm, const LinkedList& right)
{
    LinkedList::ListNode* current = right.head;

    while(current)
    {
        ostrm << current->value;
        current = current->next;
    }

    return ostrm;
}

