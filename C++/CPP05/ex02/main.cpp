#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void    exceptions_F(){

    try{
        throw;
    }
    catch (AForm::GradeTooHighException &e){
        std::cout << e.what() << std::endl;
    }
    catch (AForm::GradeTooLowException &e){
        std::cout << e.what() << std::endl;
    }
    catch(...){
        std::cout << "Unknown exceptions for Form" << std::endl;
    }
}

static void    exceptions_B(){

    try{
        throw;
    }
    catch (Bureaucrat::GradeTooHighException &e){
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e){
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::NotSigned &e){
        std::cout << e.what() << std::endl;
    }
    catch(...){
        exceptions_F();
    }
}

int main(void){

    std::srand(std::time(NULL));

    std::cout << "/*---------------Shrubbery-------------*/" << std::endl;
    try{
        Bureaucrat Keny("Keny", 135);
        Bureaucrat Dylan("Dylan", 1);
        Bureaucrat Kath("Kath", 150);
        ShrubberyCreationForm Tree("Tree", Keny.getName());

        std::cout << Keny << std::endl;
        std::cout << Tree << std::endl;

        Keny.signForm(Tree);
        Tree.execute(Keny);
        Dylan.executeForm(Tree);
        Kath.executeForm(Tree);
    }
    catch(...){
        exceptions_B();
    }
    std::cout << "/*---------------Robotomy-------------*/" << std::endl;
    try{
        Bureaucrat Keny("Keny", 70);
        Bureaucrat Dylan("Dylan", 1);
        Bureaucrat Kath("Kath", 150);
        RobotomyRequestForm Drill("Drill", Keny.getName());

        std::cout << Keny << std::endl;
        std::cout << Dylan << std::endl;
        std::cout << Drill << std::endl;

        Keny.signForm(Drill);
        Drill.execute(Dylan);
        Dylan.executeForm(Drill);
        Drill.execute(Dylan);
        Dylan.executeForm(Drill);
        Drill.execute(Dylan);
        Dylan.executeForm(Drill);
        Keny.executeForm(Drill);
    }
    catch(...){
        exceptions_B();
    }
    std::cout << "/*---------------Presidential-------------*/" << std::endl;
    try{
        // AForm error("ERROR", 25, 25);
        Bureaucrat Keny("Keny", 8);
        Bureaucrat Dylan("Dylan", 1);
        PresidentialPardonForm Macron("Macron", "Brigitte");

        std::cout << Keny << std::endl;
        std::cout << Dylan << std::endl;
        std::cout << Macron << std::endl;

        Keny.signForm(Macron);
        Macron.execute(Dylan);
        Keny.executeForm(Macron);
    }
    catch(...){
        exceptions_B();
    }
}