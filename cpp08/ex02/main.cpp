#include "MutantStack.hpp"

#include <algorithm>
#include <list>
#include <iostream>

int main(void)
{

    MutantStack<int> mstack;

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(78);
    mstack.push(1);
    mstack.push(222);

    MutantStack<int>::const_iterator it = mstack.end();
    while (it != mstack.begin())
    {
        --it;
        std::cout << "[" << *it << "]" << std::endl;
    }

    mstack.pop();
    std::cout << "stack: "<< mstack << std::endl;
    
    std::cout << "-----------------------------------------------------------------------------" << std::endl;
    std::cout << "-----------------------------Test 42-----------------------------------------" << std::endl;
    
    MutantStack<int> test;

    test.push(5);
    test.push(17);

    std::cout << test.top() << std::endl;

    test.pop();

    std::cout << test.size() << std::endl;

    test.push(3);
    test.push(5);
    test.push(737);
    //[...]

    test.push(0);

    MutantStack<int>::iterator it_42 = test.begin();
    MutantStack<int>::iterator ite_42 = test.end();

    ++it_42;
    --it_42;
    while (it_42 != ite_42)
    {
        std::cout << *it_42 << std::endl;
        ++it_42;
    }
    std::stack<int> s(test);

    std::cout << "-----------------------------------------------------------------------------" << std::endl;
    std::cout << "-----------------------------Test 42 with LIST-------------------------------------" << std::endl;
    
    std::list<int> test_list;

    test_list.push_back(5);
    test_list.push_back(17);

    std::cout << test_list.back() << std::endl;

    test_list.pop_back();

    std::cout << test_list.size() << std::endl;

    test_list.push_back(3);
    test_list.push_back(5);
    test_list.push_back(737);
    //[...]

    test_list.push_back(0);

    std::list<int>::iterator it_test = test_list.begin();
    std::list<int>::iterator ite_test = test_list.end();

    ++it_test;
    --it_test;
    while (it_test != ite_test)
    {
        std::cout << *it_test << std::endl;
        ++it_test;
    }

    std::list<int> d(test_list);
}
