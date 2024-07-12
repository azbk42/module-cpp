#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "include.hpp"
#include <iostream>

int main(void)
{
    Base* testA = new A();
    Base* testB = new B();
    Base* testC = new C();

    identify(testA);
    identify(testB);
    identify(testC);

    std::cout << "\nGenerate random Base:" << std::endl;
    Base* gen = generate();

    identify(gen);

    std::cout << "\nidentify by ref:" << std::endl;
    identify(*gen);

    delete testA;
    delete testB;
    delete testC;
    delete gen;

    return (0);
}