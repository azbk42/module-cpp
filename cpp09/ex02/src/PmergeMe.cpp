#include "PmergeMe.hpp"

#include <ctime>
// ################################################################################
// #                                  PMERGE                                      #
// ################################################################################


// ################################################################################
// #                                  VECTOR                                      #
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

        size_t n = _vec.size();
        std::cout << "before: ";
        print_array(_vec);

        clock_t time_vec = clock();
        if (n > 1){
            _vec = FordJ(_vec);
        }
        time_vec = clock() - time_vec;

        std::cout << "after: ";
        print_array(_vec);

        std::cout << "Time to process a range of " << n << " elements with std::vector : " << (float)time_vec * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
		//std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << (float)timeDeq * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
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
    size_t len  = vec.size();
    size_t n = len / 2;
    size_t i = 0;

    create_and_sort_pair(vec, p);

    // use merge sort to sort pair with p.first
    merge_sort(p, 0, (n - 1));

    // add the number who is paired with the first one
    std::vector<int> main_chain;
    i = 0;
    main_chain.push_back(p[0].second);
    while (i < n){
        main_chain.push_back(p[i].first);
        i++;
    }

    std::vector<int> low_pair_number;
    i = 1;
    while (i < n){
        low_pair_number.push_back(p[i].second);
        i++;
    }

    if ((len % 2) != 0){
        int nb = vec[len-1];
        std::vector<int>::iterator index = binarySearch(main_chain, 0, len - 1, nb);
        main_chain.insert(index, nb);
    }
    binary_insert(low_pair_number, main_chain, p, n);

    return main_chain; 
}

void PmergeMe::binary_insert(std::vector<int> &low_pair_number, std::vector<int> &main_chain, std::vector<std::pair<int, int> > &p, size_t n)
{

    for (size_t i = 0; i < low_pair_number.size(); i++){
        int right = find_index_in_pair(p, main_chain ,low_pair_number[i], n);

        std::vector<int>::iterator index = binarySearch(main_chain, 0, right, low_pair_number[i]);
        main_chain.insert(index, low_pair_number[i]);
    }

}

std::vector<int>::iterator PmergeMe::binarySearch(std::vector<int> &main_chain, int low, int high, int x)
{
    std::vector<int>::iterator high_it = main_chain.begin() + high;
    std::vector<int>::iterator low_it = main_chain.begin() + low;
    std::vector<int>::iterator mid_it;

    while (low_it <= high_it) {
        mid_it = low_it + std::distance(low_it, high_it) / 2;

        // Si l'élément trouvé est plus grand que x
        if (*mid_it > x) {
            // Vérifiez si le précédent est plus petit ou égal à x
            if (mid_it == main_chain.begin() || *(mid_it - 1) <= x) {
                return mid_it;
            }
            // Sinon, continuez la recherche à gauche
            high_it = mid_it - 1;
        }
        // Si l'élément trouvé est inférieur ou égal à x, continuez à droite
        else {
            low_it = mid_it + 1;
        }
    }
    
    // Si aucun élément ne remplit la condition, retournez low_it qui sera l'emplacement d'insertion
    if (x <= *(main_chain.begin()))
        return main_chain.begin();
    else{
        return main_chain.end();
    }
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

int PmergeMe::find_index_in_pair(std::vector<std::pair<int, int> > &p, std::vector<int> &main_chain,int const low_pair, int const n)
{
    int i = 1;
    int first = 0;
    while (i < n){
        if (low_pair == p[i].second){
            first = p[i].first;
        }
        i++;
    }
    i = 0;
    while (main_chain[i] != first){
        i++;
    }
    return i;
}

long PmergeMe::jacobsthal(int nb)
{
    if (nb == 0){
        return 0;
    }
    if (nb == 1){
        return 1;
    }

    return (jacobsthal(nb-1) + (2 * jacobsthal(nb - 2)));
}


// ################################################################################
// #                                   DEQUE                                      #
// ################################################################################



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