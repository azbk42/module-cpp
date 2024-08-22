#include "PmergeMe.hpp"

int main(int ac, char** av)
{
    if (ac < 2 ) {
        std::cerr << "Error !\n"
                  << "Plz, we only need positive numbers with max INT with this format: \n"
                  << "./PmergeMe \"5 4 3 8 7 1 2 9\"" << std::endl;
        return 2;
    }

    PmergeMe pmerge(av);

    return 0;
}
