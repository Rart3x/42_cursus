#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade){
    
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();

}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade){
}

Bureaucrat::~Bureaucrat(void){}

const std::string Bureaucrat::getName(void)const{
    return (this->name);
}

int Bureaucrat::getGrade(void)const{
    return (this->grade);
}

void Bureaucrat::decrementGrade(void){

    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade++;
}

void Bureaucrat::incrementGrade(void){

    if (this->grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade--;
}

void    Bureaucrat::signForm(AForm &src)const{

    if ((this->getGrade() <= src.getRequiredGrade())){
        std::cout << this->name << " signed " << src.getName() << std::endl;
        src.beSigned(*this);
    }
    else
        std::cout << this->name << " couldn't sign " << src.getName() << " because he don't have the required grade." << std::endl;
}

void Bureaucrat::executeForm(const AForm &form)const{

    if (this->getGrade() <= form.getRequiredExe() && form.getSign() == true){
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
        form.execute(*this);
    }
    else if (this->getGrade() > form.getRequiredExe()){
        throw Bureaucrat::GradeTooLowException();
    }
    else if (form.getSign() == false)
        throw Bureaucrat::NotSigned();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src){
    
    if (this != &src){
        this->grade = src.getGrade();
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &src){

    out << src.getName() << ", bureaucrat grade " << src.getGrade();
    return (out);
}

const char* Bureaucrat::GradeTooLowException::what()const throw(){
    return ("Grade too low");
}

const char* Bureaucrat::GradeTooHighException::what()const throw(){
    return ("Grade too high");
}

const char* Bureaucrat::NotSigned::what()const throw(){
    return ("Not signed");
}