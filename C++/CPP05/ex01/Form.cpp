#include "Form.hpp"

Form::Form(std::string name, const int requiredExe, const int requiredGrade) : name(name), requiredExe(requiredExe), requiredGrade(requiredGrade){

    if (requiredExe < 1 || requiredGrade < 1)
        throw Form::GradeTooHighException();
    if (requiredExe > 150 || requiredGrade > 150)
        throw Form::GradeTooLowException();
    this->sign = false;   
}

Form::Form(const Form &src) : name(src.name), sign(src.sign), requiredExe(src.requiredExe), requiredGrade(src.requiredGrade){}

Form::~Form(void){}

const std::string Form::getName(void)const{
    return (this->name);
}

bool Form::getSign(void)const{
    return (this->sign);
}

int Form::getRequiredExe(void)const{
    return (this->requiredExe);
}

int Form::getRequiredGrade(void)const{
    return (this->requiredGrade);
}

void Form::beSigned(const Bureaucrat &src){

    if (src.getGrade() <= this->requiredGrade)
    {
        this->sign = true;
    }
    else
        throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form &src){
    
    if (this != &src){
        this->sign = src.sign;
        return *this;
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Form &src){

    out << src.getName() << ", required to execute : " << src.getRequiredExe() << ", required grade  : " << src.getRequiredGrade();
    return (out);
}

const char* Form::GradeTooLowException::what()const throw(){
    return ("[Class Form] Grade too low");
}

const char* Form::GradeTooHighException::what()const throw(){
    return ("[Class Form] Grade too high");
}