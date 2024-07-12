#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <deque>


template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;

        iterator begin()
        { return this->c.begin(); }
        const_iterator begin() const { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        const_iterator end() const { return this->c.end(); }
    private:

};

template <typename T, typename Container>
std::ostream& operator<<(std::ostream& os, const MutantStack<T, Container>& stack)
{
    typename Container::const_iterator it = stack.end();
    while (it != stack.begin())
    {
        --it;
        os << *it << " ";
    }
    return os;
}

