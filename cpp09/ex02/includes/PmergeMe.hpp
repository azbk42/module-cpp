#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <climits>
#include <deque>
#include <sstream>
#include <iterator>

class PmergeMe 
{
public:

    PmergeMe(char** av);
    ~PmergeMe();
    PmergeMe(const PmergeMe& rhs);
    PmergeMe& operator=(const PmergeMe& rhs);

private:
    PmergeMe();
    void parsing_after_find_plus(char x, char after, char before, size_t i);
    void parsing_space(char x, char after);
    void parsing_int_max(const std::string arg);
    void parsing_arg(const std::string arg);
    void init_pmerge(char **av);
    void find_double(int nb, std::vector<int> &array);

    // vector
    std::vector<int> FordJ(std::vector<int> vec);
    void create_and_sort_pair(std::vector<int> const &vec, std::vector<std::pair<int, int> > &p);
    void merge_sort(std::vector<std::pair<int, int> > &p, int left, int right);
    void merge(std::vector<std::pair<int, int> > &p, int left, int mid, int right);

    std::vector<int> _vec;
    std::deque<int> _deq;
    
};


