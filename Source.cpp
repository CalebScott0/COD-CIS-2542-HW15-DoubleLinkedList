#include "LinkedList.h"
#include <iostream>

int main()
{
    LinkedList l;

    for(int i = 10; i >= 1; --i)
        l.push_front(i);

    std::cout << l << std::endl;

    return 0;
};
