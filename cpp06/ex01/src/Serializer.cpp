#include "Serializer.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t a = reinterpret_cast<uintptr_t>(ptr);

    return (a);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* a = reinterpret_cast<Data*>(raw);

    return (a);
}

// ######################################################
// #                    GET - SET                       #
// ######################################################

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

Serializer& Serializer::operator=(const Serializer& rhs)
{
    if (this != &rhs){

    }
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

Serializer::Serializer(const Serializer& rhs) { *this = rhs;};

Serializer::Serializer() {};
        
Serializer::~Serializer() {};

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################


