#include "sample.class.hpp"
#include <iostream>

Sample::Sample(void){

    std::cout<< "constructor called" << std::endl;

    this->foo = 12;
    this->bar();

}

Sample::~Sample(void){
    
    std::cout<< "destructor called" << std::endl;

}


void Sample::bar(void)
{
    std::cout<< "Member function 'bar' has been called" << std::endl;
    return;
}