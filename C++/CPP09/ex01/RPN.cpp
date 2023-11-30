#include "RPN.hpp"

RPN::RPN(void){}

RPN::RPN(const RPN &src){
    
    if (this != &src)
        *this = src;
}

RPN::~RPN(void){}

RPN&    RPN::operator=(const RPN &src){
    
    if (this != &src)
        return (*this);
    return (*this);
}

void RPN::calculate(){
    unsigned int total = 0;
    std::stack<unsigned int> finalStack;

    while (!this->stack.empty()){
        if (this->stack.top() == '+' || this->stack.top() == '-' || this->stack.top() == '*' || this->stack.top() == '/'){
            
            char operation = this->stack.top();
            this->stack.pop();

            if (finalStack.size() < 2){
                throw RPN::InvalidNbChar();
            }

            unsigned int operator2 = finalStack.top();
            finalStack.pop();
            unsigned int operator1 = finalStack.top();
            finalStack.pop();

            switch (operation){
                case '+':
                    total = SUM;
                    break;
                case '-':
                    total = SUBSTRACTION;
                    break;
                case '*':
                    total = FACTOR;
                    break;
                case '/':
                    total = DIVISION;
                    break;
            }
            finalStack.push(total);
        }
        else
        {
            finalStack.push(this->stack.top() - '0');
            this->stack.pop();
        }
    }

    if (finalStack.size() != 1 || !this->stack.empty()){
        throw RPN::InvalidNbChar();
    }

    total = finalStack.top();
    if (total > MAX_INT)
        throw RPN::MaxInt();
    std::cout << total << std::endl;
}

bool RPN::containsInvalidChar(const char* str)const{
    
    while (*str){
        if (*str != '+' && *str != '-' && *str != '*' && *str != '/' && *str != ' '
            && (*str < '0' || *str > '9'))
            return true;
        str++;
    }
    return false;
}

void    RPN::nbArgs(int ac)const{
    
    if (ac != 2)
        throw RPN::InvalidNbArgs();
}
    
void    RPN::program(int ac, char **av){

    try
    {
        this->nbArgs(ac);
        this->verifArguments(av);
        this->calculate();
    }
    catch (...){
        exceptions();
    }
}

void    RPN::verifArguments(char **av){
    
    std::stack<char> tmp;
    if (this->containsInvalidChar(av[1]))
        throw RPN::InvalidChar();
    for (int i = strlen(av[1]) - 1; i >= 0; i--){
        while (av[1][i] == ' ')
            i--;
        this->stack.push(av[1][i]);
    }
}

void    RPN::exceptions(void)const{

    try
    {
        throw;
    }
    catch(RPN::InvalidChar &e){
        std::cout << e.what() << std::endl;
    }
    catch(RPN::InvalidNbArgs &e){
        std::cout << e.what() << std::endl;
    }
    catch(RPN::InvalidNbChar &e){
        std::cout << e.what() << std::endl;
    }
    catch(RPN::MaxInt &e){
        std::cout << e.what() << std::endl;
    }
}

const char* RPN::InvalidChar::what() const throw(){
    return ("error: invalid character");
}

const char* RPN::InvalidNbArgs::what() const throw(){
    return ("error: invalid number of arguments");
}

const char* RPN::InvalidNbChar::what() const throw(){
    return ("error: invalid number of character");
}

const char* RPN::MaxInt::what() const throw(){
    return ("error: max int exceeds");
}