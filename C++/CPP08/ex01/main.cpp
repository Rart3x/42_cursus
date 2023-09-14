#include "Span.hpp"

static void exceptions(void){
    try
    {
        throw;
    }
    catch(Span::EmptyException &e){
        std::cout << e.what() << std::endl;
    }
    catch(Span::FilledException &e){
        std::cout << e.what() << std::endl;
    }
    catch(Span::InvalidNbValues &e){
        std::cout << e.what() << std::endl;
    }
}


int main(void){

    Span mySpan(10000);

    try
    {
         mySpan.addNumberLoop(3000);
    }
    catch (...)
    {
        exceptions();
    }

    try
    {
        std::cout << "Shortest Span : " <<  mySpan.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << mySpan.longestSpan() << std::endl;
    }
    catch(...)
    {
        exceptions();
    }

    std::cout << "*------------------Not enough values----------------*" << std::endl;

    mySpan.clearVec();
    try
    {
        mySpan.addNumberLoop(1);
        std::cout << "Shortest Span : " <<  mySpan.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << mySpan.longestSpan() << std::endl;
    }
    catch (...)
    {
        exceptions();
    }

    std::cout << "*------------------PDF_test----------------*" << std::endl;

    Span sp = Span(3);

    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(8);
        sp.addNumber(11);
    }
    catch(...){
        exceptions();
    }

    ///std::copy(this->vec.begin(), this->vec.end(), std::ostream_iterator<unsigned int>(std::cout));

    try
    {
        std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
        std::cout << "Longest : "  << sp.longestSpan() << std::endl;
    }
    catch(...){
        exceptions();
    }

    return (0);
}