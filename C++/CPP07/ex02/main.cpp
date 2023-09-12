#include "Array.hpp"

int main(void){

    try
    {
        Array<int> i(7);
        Array<int> j(5);
        Array<std::string> k(3);

        int *a = new int();

        std::cout << *a << std::endl;

        j = i;
        
        unsigned int value;

        value = i.size();
        std::cout << "I.size : " << value << std::endl;
        
        value = j.size();
        std::cout << "J.size : " << value << std::endl;

        value = k.size();
        std::cout << "K.size : " << value << std::endl;

        std::cout << std::endl;

        int ret;
        std::string str;

        j.setElements(3, 150);
        ret = j[3];
        std::cout << "Element number 4 for J : " << ret << std::endl;

        k.setElements(2, "This is a string");
        str = k[2];
        std::cout << "Element number 3 for K : " << str << std::endl;

        std::cout << std::endl;

        std::cout << "i[4] when unitialized : " << i[4] << std::endl;

        i.setElements(4, 999);

        ret = i[4];
        std::cout << "RET(i[4]) : " << ret << std::endl;

        delete a;
        
        std::cout << std::endl;

        std::cout << k[42] << std::endl;
    }
    catch (std::out_of_range &e){
        std::cout << e.what() << std::endl;
    }

    return (0);
}