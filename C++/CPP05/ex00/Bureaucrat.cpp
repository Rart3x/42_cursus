#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade){
    
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src){
    if (this != &src)
        *this = src;
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

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src){
    
    if (this != &src){
        this->grade = src.grade;
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