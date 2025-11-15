#include "LinkedList.h"
#include <limits>

LinkedList::LinkedList()
    : head(nullptr)
{
    // Empty  
}

LinkedList::~LinkedList()
{
    while(!empty())
    {
        pop_front();
    }
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
    if(empty())
    {
        return;
    }

    ListNode* temp = head;
    head = head->next;
    
    // if there was more than 1 element in list
    if(!empty())
    {
        head->previous = nullptr;
    }

    delete temp;
}

void LinkedList::push_front(long long v)
{
    // newNode->next will point to previous head when pushed to front, or head == nullptr if empty list
    ListNode* newNode = new ListNode(v, nullptr, head);

    if(!empty())
    {
        head->previous = newNode;
    }
    head = newNode;
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
    // insert at head (empty list or idx <= 0)
    if(idx <= 0 || empty())
    {
        push_front(val);
        return;
    }

    ListNode* current = head;
    int currentIdx = 0;

    // traverse to the node at index idx
    while(current->next && currentIdx < idx)
    {
        current = current->next;
        ++currentIdx;
    }

    if(currentIdx < idx) 
    {
        // idx is beyond the last element, insert at the end
        ListNode* newNode = new ListNode(val, current, nullptr);
        current->next = newNode;
    }
    else
    {
        // insert before current
        ListNode* newNode = new ListNode(val, current->previous, current);
        current->previous->next = newNode;
        current->previous = newNode;
    }
}

void LinkedList::erase(int idx)
{
    if(empty())
    {
        return;
    }

    // erase head
    if(idx == 0)
    {
        pop_front();
        return;
    }

    int currentIdx = 0;
    ListNode* current = head;
    while(current && currentIdx != idx)
    {
        ++currentIdx;
        current = current->next;
    }

    // arg index is valid
    if(current)
    {
        // erase idx will never be head here, current->previous always true
        current->previous->next = current->next;
        if(current->next)
        {
            current->next->previous = current->previous;
        }
        delete current;
    }
}

int LinkedList::find(long long val) const
{
    ListNode* current = head;
    int index = 0;
    while(current)
    {
        if(current->value == val)
        {
            // found value
            return index;
        }
        ++index;
        current = current->next;
    }

    return -1;
}

long long LinkedList::operator [] (int idx) const
{
    ListNode* current = head;
    int index = 0;
    while(current)
    {
        if(index == idx)
        {
            // found value
            return current->value;
        }
        ++index;
        current = current->next;
    }

    return std::numeric_limits<short>::min();

}

std::ostream& operator << (std::ostream& ostrm, const LinkedList& right)
{
    LinkedList::ListNode* current = right.head;

    while(current)
    {
        ostrm << current->value << " ";
        current = current->next;
    }
    ostrm << std::endl;

    return ostrm;
}

