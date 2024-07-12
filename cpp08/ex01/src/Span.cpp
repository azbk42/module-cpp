#include "Span.hpp"
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <climits>

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void Span::addNumber(int nb)
{
    if (_tab.size() == _N){
        throw std::out_of_range("Your array is full!");
    }
    else{
        _tab.insert(nb);
    }
}
  
void Span::addRange(int begin, int end)
{
    if (begin > end)
    {
        throw std::invalid_argument("Start value must be less than or equal to end value.");
    }

    int count = end - begin + 1;
    if (_tab.size() + count > _N)
    {
        throw std::out_of_range("With this range your array will be full !");
    }

    while (begin <= end){
        _tab.insert(begin++);
    }   
   
}


unsigned int Span::shortestSpan(void)
{
    if (_tab.size() <= 1)
    {
        throw std::logic_error("No value or only 1.");
    }

    unsigned int shortest = UINT_MAX;
    unsigned int span;
    std::multiset<int>::const_iterator next;

    for (std::multiset<int>::const_iterator it = _tab.begin(); it != _tab.end(); it++){
        next = it;
        ++next;
        if (next != _tab.end())
        {
            span = *next - *it;
            if (span < shortest)
            {
                shortest = span;
            }
        }
    }
    return (shortest);
}

unsigned int Span::longestSpan(void)
{
    if (_tab.size() <= 1){
        throw std::logic_error("No value or only 1.");
    }
    
    int min = *std::min_element(_tab.begin(), _tab.end());
    int max = *std::max_element(_tab.begin(), _tab.end());

    return (max - min);
}

// ######################################################
// #                 GET - SET                          #
// ######################################################

std::multiset<int> Span::getArray(void) const
{
    return (_tab);
}

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

Span & Span::operator=(const Span & rhs)
{
    if (this != &rhs) {
        _tab = rhs._tab;
    }
    return *this;
}

std::ostream& operator << (std::ostream& o, const Span & rhs)
{
    const std::multiset<int> tab = rhs.getArray();
    for (std::multiset<int>::const_iterator it = tab.begin(); it != tab.end(); it++){
        o << "[" << *it << "] ";
    }
    return o;
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

Span::Span(const Span & rhs) : _N(rhs._N), _tab(rhs._tab)
{
}

Span::Span(unsigned int N): _N(N)
{
}

Span::~Span()
{
}
// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################

