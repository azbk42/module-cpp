#pragma once
#include <iostream>
#include <set>

#define BLUE "\033[34m"
#define RESET "\033[0m"

class Span
{
    public:

        void addNumber(int n);
        void addRange(int begin, int end);

        template <typename It>
        void addRange(It begin, It end);

        unsigned int shortestSpan(void);
        unsigned int longestSpan(void);

        Span(unsigned int N);
        ~Span();
        Span(const Span & rhs );
        Span & operator =(const Span & rhs);

        std::multiset<int> getArray(void) const;
 
    private:
        
        Span();
        const unsigned int _N;
        std::multiset<int> _tab;
};

std::ostream &operator<<(std::ostream &os, const Span &rhs);

template <typename It>
void Span::addRange(It begin, It end) {
    if (std::distance(begin, end) + _tab.size() > _N) {
        throw std::out_of_range("Adding these elements would exceed the maximum capacity of the Span.");
    }
    _tab.insert(begin, end);
}