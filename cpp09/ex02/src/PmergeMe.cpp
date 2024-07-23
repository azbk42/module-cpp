#include "PmergeMe.hpp"
// ################################################################################
// #                                  PMERGE                                      #
// ################################################################################


// ################################################################################
// #                                  PARSING                                     #
// ################################################################################

void PmergeMe::parsing_after_find_plus(char x, char after, char before, size_t i) {
    if (x == '+') {
        if (i != 0) {
            if (before != ' ') {
                throw std::invalid_argument("Error You must have a space before your '+'");
            }
        }
        if (!isdigit(after)) {
            throw std::invalid_argument("Error you can't put a '+' alone");
        }
    }
}

void PmergeMe::parsing_space(char x, char after) {
    if (isdigit(x)) {
        if ((after != '\0' && after != ' ') && (!isdigit(after))) {
            throw std::invalid_argument("Error you must have a space at the end of a digit or nothing if its the last one.");
        }
    }
}

void PmergeMe::parsing_int_max(const std::string arg) {
    size_t i = 0;
    long result = 0;

    while (isdigit(arg[i])) {
        result *= 10;
        result += arg[i] - '0';
        if (result > INT_MAX) {
            throw std::invalid_argument("Element must be INT MAX or less!");
        }
        i++;
    }
}

void PmergeMe::parsing_arg(const std::string arg) {
    for (size_t i = 0; i < arg.length(); i++) {
        parsing_after_find_plus(arg[i], arg[i + 1], arg[i - 1], i);
        parsing_space(arg[i], arg[i + 1]);

        if (!isdigit(arg[i]) && arg[i] != '+' && arg[i] != ' ') {
            throw std::invalid_argument("Arg must start with '+' or space or digit");
        }
        if (arg[i] == '+' || (i == 0 && (isdigit(arg[i]))) || arg[i - 1] == ' ' || (arg[i - 1] == '+' && isdigit(arg[i]))) {
            parsing_int_max(&arg[i]);
        }
    }
}

// Constructeurs et destructeurs
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& rhs) { *this = rhs; }
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) 
{
    if (this != &rhs) {
    }
    return *this;
}