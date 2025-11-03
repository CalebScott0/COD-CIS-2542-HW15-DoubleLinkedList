#include "LinkedList.h"

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
LinkedList::ListNode::ListNode(long long int v, ListNode* prev, ListNode* n)
    : value(v),
      previous(prev),
      next(n)
{
    // Empty
}

void LinkedList::push_front(long long int v)
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

