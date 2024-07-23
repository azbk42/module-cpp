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
    template<typename T>
    PmergeMe(T& container, char** av){
        init_pmerge(container, av);
    }
    ~PmergeMe();
    PmergeMe(const PmergeMe& rhs);
    PmergeMe& operator=(const PmergeMe& rhs);

private:
    PmergeMe();
    void parsing_after_find_plus(char x, char after, char before, size_t i);
    void parsing_space(char x, char after);
    void parsing_int_max(const std::string arg);
    void parsing_arg(const std::string arg);
    template <typename T>
    void find_double(int nb, T& array);

    template<typename T>
    void init_pmerge(T& container, char** av);

    template<typename T>
    void print_array(const T& smaller, const T& greater);

    template<typename T>
    void sort_by_pairs(const T& container, T &smaller, T& greater);

    template<typename T>
    T merge_insert_sort(T& container);

    template<typename T>
    void insert_remaining_elements(T& result, const T& smaller, int value_pop);
    
    template<typename T>
    void binary_insert(T& sorted, int element);
};

template<typename T>
void PmergeMe::init_pmerge(T& container, char** av) 
{
    try {
        if (av) {
            for (size_t i = 1; av[i] != NULL; i++) {
                parsing_arg(av[i]);
                std::istringstream iss(av[i]);
                int nb;
                while (iss >> nb) {
                    find_double(nb, container);
                    container.push_back(nb);
                }
            }
            T sorted_container = merge_insert_sort(container);
            std::cout << "Sorted data: ";
            for (typename T::iterator it = sorted_container.begin(); it != sorted_container.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        } 
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
}

template <typename T>
void PmergeMe::print_array(const T& smaller, const T& greater) {
    std::cout << "Smaller: ";
    for (typename T::const_iterator it = smaller.begin(); it != smaller.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\nGreater: ";
    for (typename T::const_iterator it = greater.begin(); it != greater.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n---------------------------- " << std::endl;
}

template <typename T>
void PmergeMe::find_double(int nb, T& array)
{
    if (std::find(array.begin(), array.end(), nb) != array.end()) {
        throw std::invalid_argument("You can't have double");
    }
}

template<typename T>
void PmergeMe::sort_by_pairs(const T& container, T &smaller, T& greater)
{
    size_t j = 0;
    for (size_t i = 0; i < container.size(); i += 2) {
        if (i + 1 < container.size()) {
            if (container[i] < container[i + 1]) {
                smaller[j] = container[i];
                greater[j] = container[i + 1];
            } else {
                smaller[j] = container[i + 1];
                greater[j] = container[i];
            }
        } else {
            smaller[j] = container[i];
        }
        j++;
    }
}

template<typename T>
T PmergeMe::merge_insert_sort(T& container)
{
    if (container.size() <= 1) {
        return container;
    }

    int value_pop = -1;
    if ((container.size() % 2) != 0){
        value_pop = container.back();
        container.pop_back();
        std::cout << "pop: " << value_pop << std::endl;
    }

    T smaller(container.size() / 2);
    T greater(container.size() / 2);

    sort_by_pairs(container, smaller, greater);
    print_array(smaller, greater);

    // Recursively sort the greater elements
    T sorted_greater = merge_insert_sort(greater);
    
    std::cout << "sorted greater" << std::endl;
    print_array(smaller, sorted_greater);

    // Combine the results
    T result;
    result.push_back(smaller[0]); // Insert the element associated with the smallest greater element
    
    insert_remaining_elements(result, smaller, value_pop);

    for (typename T::iterator it = sorted_greater.begin(); it != sorted_greater.end(); ++it) {
        binary_insert(result, *it);
    }

    return result;
}

template<typename T>
void PmergeMe::insert_remaining_elements(T& result, const T& smaller, int value_pop) {
    for (size_t i = 1; i < smaller.size(); ++i) {
        binary_insert(result, smaller[i]);
    }

    if (value_pop != -1) {
        binary_insert(result, value_pop);
    }
}

template<typename T>
void PmergeMe::binary_insert(T& sorted, int element) {
    typename T::iterator it = std::lower_bound(sorted.begin(), sorted.end(), element);
    sorted.insert(it, element);
}

