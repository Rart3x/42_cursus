#include "Serializer.hpp"

int main(void){

    Data        data;
    Serializer  obj;

    data.a = "STRING A";
    data.b = "STRING B";

    uintptr_t ptr = obj.serialize(&data);

    std::cout << ptr << std::endl;

    Data* newData;

    newData = obj.deserialize(ptr);

    std::cout << newData->a << std::endl;
    std::cout << newData->b << std::endl;
}