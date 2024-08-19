#include "PmergeMe.hpp"
// ################################################################################
// #                                  PMERGE                                      #
// ################################################################################

void PmergeMe::init_pmerge(char** av) 
{
    try {
        for (size_t i = 1; av[i] != NULL; i++) {
            parsing_arg(av[i]);
            std::istringstream iss(av[i]);
            int nb;
            while (iss >> nb) {
                find_double(nb, _vec);
                _vec.push_back(nb);
                _deq.push_back(nb);
            }
        }
        FordJ(_vec);
        // std::cout << "Sorted data: ";
        // for (typename T::iterator it = sorted_container.begin(); it != sorted_container.end(); ++it) {
        //     std::cout << *it << " ";
        // }
        // std::cout << std::endl; 
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
}

void PmergeMe::merge(std::vector<std::pair<int, int> > &p, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<std::pair<int, int> > left_array(n1);
    std::vector<std::pair<int, int> > right_array(n2);

    for (int i = 0; i < n1; i++) {
        left_array[i] = p[left + i];
    }
    for (int j = 0; j < n2; j++) {
        right_array[j] = p[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (left_array[i].first <= right_array[j].first) {  // Corrigé ici
            p[k] = left_array[i];
            i++;
        } else {
            p[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        p[k] = left_array[i];
        i++;
        k++;
    }

    while (j < n2) {
        p[k] = right_array[j];
        j++;
        k++;
    }
}

void PmergeMe::merge_sort(std::vector<std::pair<int, int> > &p, int left, int right)
{
    if (left >= right){
        return;
    }

    int mid = left + (right - left) / 2;
    merge_sort(p, left, mid);
    merge_sort(p, mid+1, right);
    merge(p, left, mid, right);
}

std::vector<int> PmergeMe::FordJ(std::vector<int> vec)
{
    std::vector<std::pair<int, int> > p;
    
    create_and_sort_pair(vec, p);

    size_t i = 0;
    while (i < (vec.size() /2)){
        std::cout << "(" << p[i].first << ", " << p[i].second << ")" << std::endl;
        i++;
    }
    

    // use merge sort to sort pair with p.first

    merge_sort(p, 0, (vec.size() /2 - 1));

    i = 0;
    std::cout << std::endl;
    while (i < (vec.size() /2)){
        std::cout << "(" << p[i].first << ", " << p[i].second << ")" << std::endl;
        i++;
    }

    return vec;
    
}

void PmergeMe::create_and_sort_pair(std::vector<int> const &vec, std::vector<std::pair<int, int> > &p)
{
    size_t n = vec.size() / 2;
    size_t i = 0;
    size_t j = 0;

    while (n != 0){
        p.push_back(std::make_pair(vec.at(i), vec.at(i+1)));
        if (p[j].first < p[j].second){
            int tmp = p[j].first;
            p[j].first = p[j].second;
            p[j].second = tmp;
        }
        i +=2;
        j ++;
        n--;
    } 

}

// ################################################################################
// #                                  PARSING                                     #
// ################################################################################

void PmergeMe::find_double(int nb, std::vector<int> &array)
{
    if (std::find(array.begin(), array.end(), nb) != array.end()) {
        throw std::invalid_argument("You can't have double");
    }
}

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
PmergeMe::PmergeMe(char** av){
        init_pmerge(av);
}
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& rhs) { *this = rhs; }
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) 
{
    if (this != &rhs) {
        _vec = rhs._vec;
        _deq = rhs._deq;
    }
    return *this;
}