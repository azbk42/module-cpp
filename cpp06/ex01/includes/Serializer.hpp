#pragma once
# include <iostream>
# include <string>
# include <cstdlib>
# include <cstring>
# include <climits>
# include <stdint.h>
#include "Serializer.hpp"

struct Data
{
    size_t height;
    size_t weight;
};

class Serializer
{

    public:

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

    private:

        Serializer(const Serializer& rhs);
        Serializer();
        ~Serializer();

        Serializer& operator = (const Serializer& rhs);
};