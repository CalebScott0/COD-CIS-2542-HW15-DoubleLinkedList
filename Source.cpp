#include <iostream>
#include <limits>
#include "LinkedList.h"

int main() {
    LinkedList list;

    std::cout << "=== Test: empty() on new list ===" << std::endl;
    std::cout << (list.empty() ? "PASS" : "FAIL") << std::endl;

    std::cout << std::endl << "=== Test: push_front ===" << std::endl;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    std::cout << list;  // Expected: 30 20 10
    std::cout << (list.size() == 3 ? "PASS" : "FAIL") << " (size after push_front)" << std::endl;

    std::cout << std::endl << "=== Test: operator[] ===" << std::endl;
    std::cout << list[0] << " " << list[1] << " " << list[2] << std::endl; // Expected: 30 20 10
    std::cout << (list[3] == std::numeric_limits<short>::min() ? "PASS" : "FAIL") << " (out-of-bounds)" << std::endl;

    std::cout << std::endl << "=== Test: pop_front ===" << std::endl;
    list.pop_front();   // removes 30
    std::cout << list;  // Expected: 20 10
    list.pop_front();
    list.pop_front();
    std::cout << list;  // Expected: empty
    std::cout << (list.empty() ? "PASS" : "FAIL") << " (empty after popping all)" << std::endl;

    std::cout << std::endl << "=== Test: insert ===" << std::endl;
    list.push_front(1); // List: 1
    list.insert(0, 0);  // List: 0 1 (insert at head)
    list.insert(1, 5);  // List: 0 5 1 (insert middle)
    list.insert(10, 100); // List: 0 5 1 100 (insert at back because idx >= size)
    std::cout << list;  // Expected: 0 5 1 100

    std::cout << std::endl << "=== Test: erase ===" << std::endl;
    list.erase(0);      // removes head, List: 5 1 100
    list.erase(1);      // removes middle, List: 5 100
    list.erase(10);     // no-op because index >= size
    std::cout << list;  // Expected: 5 100
    list.erase(0);
    list.erase(0);      // list empty now
    std::cout << (list.empty() ? "PASS" : "FAIL") << " (erase all elements)" << std::endl;

    std::cout << std::endl << "=== Test: find ===" << std::endl;
    list.push_front(7);
    list.push_front(14);
    list.push_front(21); // List: 21 14 7
    std::cout << "Find 14: " << list.find(14) << " (Expected 1)" << std::endl;
    std::cout << "Find 100: " << list.find(100) << " (Expected -1)" << std::endl;

    std::cout << std::endl << "=== Test: size on non-empty list ===" << std::endl;
    std::cout << "Size: " << list.size() << " (Expected 3)" << std::endl;

    std::cout << std::endl << "=== Test: operator<< ===" << std::endl;
    std::cout << list;  // Expected: 21 14 7

    std::cout << std::endl << "=== Test: insert at exact back (idx == size) ===" << std::endl;
    list.insert(list.size(), 42); // List: 21 14 7 42
    std::cout << list;

    std::cout << std::endl << "=== Test: erase at invalid index ===" << std::endl;
    list.erase(100); // no-op
    std::cout << list;  // List unchanged

    std::cout << std::endl << "=== Test: operator[] edge cases ===" << std::endl;
    std::cout << "Index -1: " << list[-1] << " (Expected min short)" << std::endl;
    std::cout << "Index size: " << list[list.size()] << " (Expected min short)" << std::endl;

    std::cout << std::endl << "=== All tests completed ===" << std::endl;

    return 0;
}
