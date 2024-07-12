#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    int i = rand() % 3;
    if (i == 0)
        return (new A);
    else if (i == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base* p)
{
    A* verifA = dynamic_cast<A*>(p);
    if (verifA){
        std::cout << "Base type = A" << std::endl;
    }

    B* verifB = dynamic_cast<B*>(p);
    if (verifB){
        std::cout << "Base type = B" << std::endl;
    }

    C* verifC = dynamic_cast<C*>(p);
    if (verifC){
        std::cout << "Base type = C" << std::endl;
    }
}

void identify(Base& p)
{

    try{
        A& verifA = dynamic_cast<A &>(p);
        std::cout << "Base type = A" << std::endl;
        (void)verifA;
    }
    catch  (std::exception &bc){
        std::cout << "Conversion A is not OK: " << bc.what() << std::endl;
    }

    try{
        B& verifB = dynamic_cast<B &>(p);
        std::cout << "Base type = B" << std::endl;
        (void)verifB;
    }
    catch  (std::exception &bc){
        std::cout << "Conversion B is not OK: " << bc.what() << std::endl;
    }

    try{
        C& verifC = dynamic_cast<C &>(p);
        std::cout << "Base type = C" << std::endl;
        (void)verifC;
    }
    catch  (std::exception &bc){
        std::cout << "Conversion C is not OK: "<< bc.what() << std::endl;
    }

}