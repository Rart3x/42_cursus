#include "iter.hpp"
#include <cstring>

template <typename T>

static void printValue(T& value){
    std::cout << value << std::endl;
}

template <typename S>

static void ft_toupper(S& value){
    
    unsigned int i = 0;

    while(value[i++])
        value[i] = toupper(value[i]);
}

int main(void){

    char cArray[5][100] = {"One", "Two", "Three", "Four", "Five"};
    int iArray[5] = {1, 2, 3, 4, 5};
    std::string sArray[5] = {"Six", "Seven", "Eight", "Nine", "Ten"};

    ::iter(cArray, 5, printValue);
    std::cout << std::endl;
    ::iter(iArray, 5, printValue);
    std::cout << std::endl;
    ::iter(sArray, 5, printValue);
    std::cout << std::endl;

    ::iter(cArray, 5, ft_toupper);
    ::iter(sArray, 5, ft_toupper);

    ::iter(cArray, 5, printValue);
    std::cout << std::endl;
    ::iter(sArray, 5, printValue);

    return (0);
}