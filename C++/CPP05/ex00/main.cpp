#include "Bureaucrat.hpp"

void    exceptions(){

    try{
        throw;
    }
    catch (Bureaucrat::GradeTooHighException &e){
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e){
        std::cout << e.what() << std::endl;
    }
}

int main(void){

    try{
        Bureaucrat Keny("Keny", 1);
        Bureaucrat Dylan("Dylan", 2);

        std::cout << Keny << std::endl;
        std::cout << Dylan << std::endl;

        std::cout << "-----------Decrementation/Incremention----------" << std::endl;

        Keny.decrementGrade();
        Dylan.incrementGrade();

        std::cout << Keny << std::endl;
        std::cout << Dylan << std::endl;

        Keny = Dylan;
        std::cout << Keny << std::endl;
    }
    catch(...){
        exceptions();
    }

    std::cout << "-----------TooLow exception----------" << std::endl;
    try{
        Bureaucrat Keny("Keny", 25);
        
        std::cout << Keny << std::endl;
        
        Bureaucrat Dylan("Dylan", 0);

        std::cout << Dylan << std::endl;
    }
    catch(...){
        exceptions();
    }

    std::cout << "-----------TooHigh exception----------" << std::endl;
    try{
        Bureaucrat Keny("Keny", 151);

        std::cout << Keny << std::endl;
    }
    catch(...){
        exceptions();
    }

    std::cout << "-----------Incremention - Too High----------" << std::endl;
    try{
        Bureaucrat Keny("Keny", 1);

        std::cout << Keny << std::endl;

        Keny.incrementGrade();

        std::cout << Keny << std::endl;
    }
    catch(...){
        exceptions();
    }

    std::cout << "-----------Incremention - Too Low----------" << std::endl;
    try{
        Bureaucrat Dylan("Dylan", 150);

        std::cout << Dylan << std::endl;

        Dylan.decrementGrade();

        std::cout << Dylan << std::endl;
    }
    catch(...){
        exceptions();
    }

    std::cout << "-----------Constructur with negative----------" << std::endl;
    try{
        Bureaucrat Keny("Keny", -1);

        std::cout << Keny << std::endl;
    }
    catch(...){
        exceptions();
    }

    std::cout << "-----------Constructur with overflow----------" << std::endl;
    try{
        Bureaucrat Dylan("Dylan", 514515156);

        std::cout << Dylan << std::endl;
    }
    catch(...){
        exceptions();
    }
}