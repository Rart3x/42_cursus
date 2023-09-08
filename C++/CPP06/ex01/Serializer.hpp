#pragma once 

#include <iostream>
#include <stdint.h>

struct Data{

    std::string a;
    std::string b;
};

class Serializer{

    public:
        Serializer();
        Serializer(const Serializer &src);

        ~Serializer();

        Serializer& operator=(const Serializer &src);

        uintptr_t   serialize(Data* ptr);
        Data*       deserialize(uintptr_t raw);

    private:

};

