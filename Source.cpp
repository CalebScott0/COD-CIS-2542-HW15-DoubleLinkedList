#include "LinkedList.h"
#include <iostream>

int main()
{
    LinkedList l;

    l.push_front(1);
    l.insert(1, 999);


        
    std::cout << l << std::endl;

    return 0;
};
