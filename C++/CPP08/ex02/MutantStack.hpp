#pragma once

#include <algorithm>
#include <iostream> 
#include <iterator>
#include <list>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

template <typename T>

class MutantStack : public std::stack<T>{
    public:
        
        typedef std::stack<T> stack;
	    typedef typename std::stack<T>::container_type::iterator iterator;

        MutantStack(){};
        MutantStack(const MutantStack &src) : std::stack<T>(src){
            *this = src;
        };

        ~MutantStack(){};

        MutantStack& operator=(const MutantStack &src){
            if (*this != src){
                *this = src;
                return (*this);
            }
        }

        iterator begin(void){
            return (std::stack<T>::c.begin());
        }

        iterator end(void){
            return (std::stack<T>::c.end());
        }

    private:

};