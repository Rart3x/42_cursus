#pragma once 

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>

void easyfind(T first, int second){

    if (std::find(first.begin(), first.end(), second) == first.end())
        std::cout << "element not found" << std::endl;
    else
        std::cout << *std::find(first.begin(), first.end(), second) << std::endl;
}