#include "Span.hpp"

Span::Span(void){}

Span::Span(unsigned int N){
    this->myStatic = 0;
    this->max = N;
}

Span::Span(const Span &src){
    if (this != &src)
        *this = src;
}

Span::~Span(){}

Span& Span::operator=(const Span &src){
    if (this != &src){
        this->myStatic = src.myStatic;
        this->max = src.max;
        this->vec = src.vec;
    }
    return (*this);
}

void Span::addNumber(unsigned int number){

    static unsigned int i = 0;

    if (this->myStatic < this->max){
        this->vec.push_back(number);
        i++;
        this->myStatic = i;
    }
    else
        throw Span::FilledException();  
}

void Span::addNumberLoop(unsigned int number){

    srand(time(NULL));

    for(unsigned int i = 0; i < number; i++){
        if (i > this->max)
            throw Span::FilledException();
        this->vec.push_back(rand() % MAX_INT);
    }
}

void Span::clearVec(void){
    this->vec.clear();
}

unsigned int Span::longestSpan(){

    if (this->vec.empty() == true || this->vec.size() == 1){
        throw Span::InvalidNbValues();
    }
    else
    {
        std::sort(this->vec.begin(), this->vec.end());

        std::vector<unsigned int>::iterator it = this->vec.begin();
        std::vector<unsigned int>::reverse_iterator iter = this->vec.rbegin();

        std::cout << "[" << *iter << " - " << *it << "] = ";
        return (*iter - *it);        
    }
}

unsigned int Span::shortestSpan(){

    if (this->vec.empty() == true || this->vec.size() == 1){
        throw Span::InvalidNbValues();
    }
    else
    {
        std::sort(this->vec.begin(), this->vec.end());
        std::vector<unsigned int>::iterator it1 = this->vec.end() - 1;
        unsigned int tmp (*it1);
        unsigned int a;
        unsigned int b;

        for (std::vector<unsigned int>::iterator it = this->vec.begin(); it < this->vec.end(); it++){
            for (std::vector<unsigned int>::iterator iter = it+1; iter < this->vec.end(); iter++){
                if ((*iter - *it) < tmp){
                    tmp = (*iter - *it);
                    a = (*iter);
                    b = (*it);
                }
            }
        }
        std::cout << "[" << a << " - " << b << "] = ";
        return (tmp);
    }
}

const char* Span::EmptyException::what() const throw(){
    return ("error: vec is empty");
}

const char* Span::InvalidNbValues::what() const throw(){
    return ("error: vec have not enough values");
}

const char* Span::FilledException::what() const throw(){
    return ("error: vec is full");
}

unsigned int Span::getMyStatic(){
    return (this->myStatic);
}

unsigned int Span::getMyMax(){
    return (this->max);
}

std::vector<unsigned int> Span::getMyVec(){
    return (this->vec);
}
