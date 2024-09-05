#include "AForm.hpp"

AForm::AForm(std::string name, const int requiredExe, const int requiredGrade) : name(name), requiredExe(requiredExe), requiredGrade(requiredGrade){

    if (requiredExe < 1 || requiredGrade < 1)
        throw AForm::GradeTooHighException();
    if (requiredExe > 150 || requiredGrade > 150)
        throw AForm::GradeTooLowException();
    this->sign = false;   
}

AForm::AForm(const AForm &src) : name(src.name), sign(src.sign), requiredExe(src.requiredExe), requiredGrade(src.requiredGrade){
}

AForm::~AForm(void){}

const std::string AForm::getName(void)const{
    return (this->name);
}

bool AForm::getSign(void)const{
    return (this->sign);
}

int AForm::getRequiredExe(void)const{
    return (this->requiredExe);
}

int AForm::getRequiredGrade(void)const{
    return (this->requiredGrade);
}

void AForm::beSigned(const Bureaucrat &src){

    if (src.getGrade() <= this->requiredGrade)
    {
        this->sign = true;
    }
    else
        throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm &src){
    
    if (this != &src){
        this->sign = src.sign;
        return *this;
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const AForm &src){

    out << src.getName() << ", required to execute : " << src.getRequiredExe() << ", required grade  : " << src.getRequiredGrade();
    return (out);
}

const char* AForm::GradeTooLowException::what()const throw(){
    return ("[Class AForm] Grade too low");
}

const char* AForm::GradeTooHighException::what()const throw(){
    return ("[Class AForm] Grade too high");
}