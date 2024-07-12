#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "Constructor for Animal only:" << std::endl;
    Animal only;

    std::cout << "\nConstructor for rex (Dog):" << std::endl;
    Animal* rex = new Dog();

    std::cout << "\nConstructor for pluto (Animal):" << std::endl;
    Animal* pluto = new Animal();

    std::cout << "\nConstructor for minou (Cat):" << std::endl;
    Animal* minou = new Cat();

    std::cout << "\nType for rex (Dog):" << std::endl;
    std::cout << rex->getType() << std::endl;

    std::cout << "\nType for pluto (Animal):" << std::endl;
    std::cout << pluto->getType() << std::endl;

    std::cout << "\nType for minou (Cat):" << std::endl;
    std::cout << minou->getType() << std::endl;

    std::cout << "\nCall method makesound():" << std::endl;
    rex->makeSound();
    pluto->makeSound();
    minou->makeSound();
    
    std::cout << "\nDestructor for rex (Dog):" << std::endl;
    delete rex;

    std::cout << "\nDestructor for pluto (Animal):" << std::endl;
    delete pluto;

    std::cout << "\nDestructor for minou (Cat):" << std::endl;
    delete minou;


    std::cout << "\nInit Wrongcat who Inherit from WrongAnimal:" << std::endl;
    WrongAnimal* test = new WrongCat();
    test->makeSound();

    std::cout << "\nInit WrongCat to test makesound:" << std::endl;
    WrongCat verif;
    verif.makeSound();

    std::cout << "\nDestructor for test (WrongAnimal):" << std::endl;
    delete test;

    std::cout << "\nDestructor stack:" << std::endl;

    return (0);
}