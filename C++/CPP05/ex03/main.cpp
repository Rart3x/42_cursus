#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){

    std::srand(std::time(NULL));

    Intern someRandomIntern;
    AForm* rrf;
    Bureaucrat *bureaucrat = new Bureaucrat("Keny", 1);

    std::cout << "-----------------President----------------" << std::endl;
    try{
        rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
        
        std::cout << rrf->getName() << std::endl;
        bureaucrat->signForm(*rrf);
        rrf->execute(*bureaucrat);
        delete rrf;
    }
    catch (Intern::FormNameInexistant &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------Robotomy----------------" << std::endl;
    try{
        rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        
        std::cout << rrf->getName() << std::endl;
        bureaucrat->signForm(*rrf);
        rrf->execute(*bureaucrat);
        delete rrf;
    }
    catch (Intern::FormNameInexistant &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------Shrubbery----------------" << std::endl;
    try{
        rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
        
        std::cout << rrf->getName() << std::endl;
        bureaucrat->signForm(*rrf);
        rrf->execute(*bureaucrat);
        delete rrf;
    }
    catch (Intern::FormNameInexistant &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------False----------------" << std::endl;
    try{
        rrf = someRandomIntern.makeForm("lol", "Bender");
        
        std::cout << rrf->getName() << std::endl;
    }
    catch (Intern::FormNameInexistant &e){
        std::cout << e.what() << std::endl;
    }
    delete bureaucrat;
}