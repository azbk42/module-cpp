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

    long jacobsthal(int nb);


    // vector
    std::vector<int> FordJ(std::vector<int> vec);
    void create_and_sort_pair(std::vector<int> const &vec, std::vector<std::pair<int, int> > &p);
    void merge_sort(std::vector<std::pair<int, int> > &p, int left, int right);
    void merge(std::vector<std::pair<int, int> > &p, int left, int mid, int right);
    int find_index_in_pair(std::vector<std::pair<int, int> > &p, std::vector<int> &main_chain, int const low_pair, int const n);
    std::vector<int>::iterator binarySearch(std::vector<int> &main_chain, int low, int high, int x);
    void binary_insert(std::vector<int> &low_pair_number, std::vector<int> &main_chain, std::vector<std::pair<int, int> > &p, size_t n);

    // deque
    std::deque<int> FordJ(std::deque<int> vec);
    void create_and_sort_pair(std::deque<int> const &vec, std::deque<std::pair<int, int> > &p);
    void merge_sort(std::deque<std::pair<int, int> > &p, int left, int right);
    void merge(std::deque<std::pair<int, int> > &p, int left, int mid, int right);
    int find_index_in_pair(std::deque<std::pair<int, int> > &p, std::deque<int> &main_chain, int const low_pair, int const n);
    std::deque<int>::iterator binarySearch(std::deque<int> &main_chain, int low, int high, int x);
    void binary_insert(std::deque<int> &low_pair_number, std::deque<int> &main_chain, std::deque<std::pair<int, int> > &p, size_t n);

    std::vector<int> _vec;
    std::deque<int> _deq;

    template<typename T>
    void print_array(T array);

};


template <typename T>
void PmergeMe::print_array(T array) 
{
    typename T::const_iterator it;
    for (it = array.begin(); it != array.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}