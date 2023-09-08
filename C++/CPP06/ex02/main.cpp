#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void){

    unsigned int i = std::rand() % 3;

    Base *base;

    switch (i){
        case 0:
            base = dynamic_cast<Base *>(new A);
            std::cout << "Generated A" << std::endl;
            break;
        case 1:
            base = dynamic_cast<Base *>(new B);
            std::cout << "Generated B" << std::endl;
            break;
        case 2:
            base = dynamic_cast<Base *>(new C);
            std::cout << "Generated C" << std::endl;
            break;
    }
    return (base);
}

void    identify(Base* p){

    if (p == NULL){
        std::cout << "Error: NULL pointer" << std::endl;
        return ;
    }
    else if (dynamic_cast<A *>(p))
        std::cout << "Identified by * : Object A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Identified by * : Object B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Identified by * : Object C" << std::endl;
}

void    identify(Base& p){

    Base base;

    try
    {
        base = dynamic_cast<A &>(p);
        std::cout << "Identified by & : Object A" << std::endl;
    }
    catch (std::exception&)
    {
        try
        {
            base = dynamic_cast<B &>(p);
            std::cout << "Identified by & : Object B" << std::endl;
        }
        catch (std::exception &)
        {
            try
            {
                base = dynamic_cast<C&>(p);
                std::cout << "Identified by & : Object C" << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
    (void)base;
}

int main(void){

    std::srand(time(NULL));

    Base *objRandom;

    std::cout << "--------------Test Random--------------" << std::endl;
    for(size_t i = 0; i < 15; i++){
        objRandom = generate();
        delete objRandom;
    }

    std::cout << "--------------Test Generate--------------" << std::endl;
    objRandom = generate();
    std::cout << "--------------Test Identify *--------------" << std::endl;
    identify(objRandom);
    std::cout << "--------------Test Identify &--------------" << std::endl;
    identify(*objRandom);
    std::cout << "--------------Test Identify & NULL--------------" << std::endl;
    
    delete objRandom;
    
    objRandom = NULL;

    identify(objRandom);
    identify(*objRandom);
}