#include "MutantStack.hpp"

int main()
{
    std::cout << "--------------------PDF-------------------------" << std::endl;
    
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    size_t j = 0;

    while (it != ite)
    {
        std::cout << "VALUE " << j << " : " << *it << std::endl;
        ++it;
        j++;
    }

    {
        std::cout << "--------------------PDF VECTOR W/ LIST-------------------------" << std::endl;
        
        std::list<int> lst;

        lst.push_back(5);
        
        std::cout << lst.size() << std::endl;
        
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);
        
        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        
        ++it;
        --it;
        
        size_t j = 0;

        while (it != ite)
        {
            std::cout << "VALUE " << j << " : " << *it << std::endl;
            ++it;
            j++;
        }
    }

    std::cout << "-----------EMPTY----------------" << std::endl;

    std::stack<int> s(mstack);

    std::stack<unsigned int> stack;

    if (stack.empty())
      std::cout << "The stack is empty." << std::endl;
    else
      std::cout << "The stack is not empty." << std::endl;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    std::cout << "-----------FILLED----------------" << std::endl;

    if (stack.empty())
      std::cout << "The stack is empty." << std::endl;
    else
      std::cout << "The stack is not empty." << std::endl;

    std::stack<unsigned int>::size_type i;

    i = stack.top();
    std::cout << "Stack's first element is " <<  i << std::endl;

    i = stack.size();
    std::cout << "Stack's number of element is  " <<  i << std::endl;
    
    stack.pop();
    std::cout << "-----------POP----------------" << std::endl;
    
    i = stack.top();
    std::cout << "Stack's first element after pop is " <<  i << std::endl;
    
    i = stack.size();
    std::cout << "Stack's number of element after pop is  " << i << std::endl;

    std::cout << "-----------STRING----------------" << std::endl;

    MutantStack<std::string> stringsStack;

    std::string value = "STRING NUMBER";
    std::string nb;
    std::stringstream ss;

    for (size_t k = 0; k < 10; k++){
        ss << k;
        ss >> nb;
        value += " " + nb;
        stringsStack.push(value);
    }

    for(MutantStack<std::string>::iterator it1 = stringsStack.begin(); it1 < stringsStack.end(); it1++){
        std::cout << (*it1) << std::endl;
    }
    return (0);
}