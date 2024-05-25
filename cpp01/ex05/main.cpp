#include "Harl.hpp"


int main(void) {

    Harl harl;

    std::cout << GREEN << "DEBUG: " << RESET << std::endl;
    harl.complain("DEBUG");

    std::cout << GREEN << std::endl << "INFO: " << RESET << std::endl;
    harl.complain("INFO");

    std::cout << GREEN << std::endl << "WARNING: " << RESET << std::endl;
    harl.complain("WARNING");

    std::cout << GREEN << std::endl << "ERROR: " << RESET << std::endl;
    harl.complain("ERROR");

    std::cout << GREEN << std::endl << "UNKNOWN: " << RESET << std::endl;
    harl.complain("UNKNOWN");

    return 0;
}