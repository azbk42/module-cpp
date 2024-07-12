#include "Serializer.hpp"

int main(void) 
{
    
    Data a = {180, 80};
    Data* ptr = &a;

    uintptr_t raw = Serializer::serialize(ptr);

    std::cout << "raw address (hexa): " << std::hex << raw << std::endl;

    Data* new_ptr = Serializer::deserialize(raw);

    std::cout << ptr << std::endl;
    std::cout << new_ptr << std::endl;

    std::cout << std::dec << ptr->height << std::endl;
    std::cout << new_ptr->height << std::endl;

    std::cout <<  ptr->weight << std::endl;
    std::cout << new_ptr->weight << std::endl;

    return (0);
    
}