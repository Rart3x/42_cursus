#pragma once 

#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>

class Array{
    public:

        Array() : arraySize(0){
            this->array = new T[0];
        }

        Array(unsigned int n) : arraySize(n){
            this->array = new T[n];
            std::fill(this->array, this->array + n, T());
        }
    
        Array(const Array &src){
            if (this != &src)
                *this = src;
        }

        ~Array(){
            delete [] this->array;
        }

        const Array& operator=(const Array &src){
            delete [] this->array;
            this->array = new T[src.size()];
            if (this != &src)
                for (size_t i = 0; i < src.size(); i++)
                    this->array[i] = src.array[i];
            return (*this);
        }

        T& operator[](unsigned int n){
            if (n > this->size())
                throw std::out_of_range("invalid index");
            return (this->array[n]);
        }

        unsigned int size() const{
            return (this->arraySize);
        }

        void setElements(unsigned int n, T value){
            if (n > this->size()){
                throw std::out_of_range("invalid index");
            }
            else
                this->array[n] = value;
        }

    private:
        unsigned int arraySize;
        T *array;
};