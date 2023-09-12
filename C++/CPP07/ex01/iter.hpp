#pragma once 

#include <cstdio>
#include <iostream>
#include <string>

template <typename T>

void iter(T *array, unsigned int length, void (*func)(T&)){

    if (!array || !func)
        return ;
    for (unsigned int i = 0; i < length; i++)
        func(array[i]);
}