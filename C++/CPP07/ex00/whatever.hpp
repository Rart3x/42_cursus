#pragma once 

#include <iostream>
#include <string>

template <typename SWAP>

void swap(SWAP &first, SWAP &second){

    SWAP tmp;

    tmp = second;
    second = first;
    first = tmp;
}

template <typename MIN>

const MIN &min(const MIN &first, const MIN &second){
    return (first < second ? first : second);
}

template <typename MAX>

const MAX &max(const MAX &first, const MAX &second){
    return (first > second ? first : second);
}