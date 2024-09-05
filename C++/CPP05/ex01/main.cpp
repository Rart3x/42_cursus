#include "Bureaucrat.hpp"

static void    exceptions_F(){

    try{
        throw;
    }
    catch (Form::GradeTooHighException &e){
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException &e){
        std::cout << e.what() << std::endl;
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
    catch(...){
      exceptions_F();
    }
}

int main(void){

    std::cout << "-----------GoodGrade----------" << std::endl;
    try{
        Bureaucrat Keny("Keny", 1);
        Form myForm("My Form", 20, 20);
        Form myOtherForm("My Form", 20, 20);

        std::cout << Keny << std::endl;
        std::cout << myForm << std::endl;

        std::cout << myForm.getSign() << std::endl;
        myForm.beSigned(Keny);
        std::cout << myForm.getSign() << std::endl;
        std::cout << myOtherForm.getSign() << std::endl;
        myOtherForm.beSigned(Keny);
        std::cout << myOtherForm.getSign() << std::endl;
    }
    catch(...){
        exceptions_B();
    }
    std::cout << "-----------GradeTooLow - signForm----------" << std::endl;
    try{
        Bureaucrat Keny("Keny", 25);
        Form Form("Form", 20, 20);

        std::cout << Keny << std::endl;
        std::cout << Form << std::endl;

        Keny.signForm(Form);
    }
    catch(...){
        exceptions_B();
    }
    std::cout << "-----------GradeTooLow - beSigned----------" << std::endl;
    try{
        Bureaucrat Keny("Keny", 25);
        Form Form("Form", 20, 20);

        std::cout << Keny << std::endl;
        std::cout << Form << std::endl;

        Form.beSigned(Keny);
    }
    catch(...){
        exceptions_B();
    }
    std::cout << "-----------FormException----------" << std::endl;
    try{
        Bureaucrat Keny("Keny", 10);
        Form Form("Form", 1, 151);

        Keny.signForm(Form);
    }
    catch(...){
        exceptions_B();
    }
    std::cout << "-----------Negative Form----------" << std::endl;
    try{
        Form Form("Form", -1, 151);
    }
    catch(...){
        exceptions_B();
    }
}