#include "PresidentialPardonForm.hpp"

/*-----------------------------Constructors------------------------*/

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target) : AForm(name, 5, 25){

    this->target = target;
    this->sign = false;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src.name, 5, 25){
    
    this->target = src.getTarget();
    this->sign = src.sign;
}

/*-----------------------------Destructors------------------------*/

PresidentialPardonForm::~PresidentialPardonForm(){

}

void PresidentialPardonForm::beSigned(const Bureaucrat &src){

    if (src.getGrade() <= this->requiredGrade)
    {
        this->sign = true;
    }
    else
        throw AForm::GradeTooLowException();
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)const{
 
    if (executor.getGrade() > this->getRequiredExe()){
        throw Bureaucrat::GradeTooLowException();
    }
    else if (this->getSign() == false)
        throw Bureaucrat::NotSigned();
    else
    {
        std::cout << this->getTarget() << " is forgiven by Zaphod Beeblebrox" << std::endl;
    }
}

/*-----------------------------Getters------------------------*/

const std::string PresidentialPardonForm::getName(void)const{
    return (this->name);
}

int PresidentialPardonForm::getRequiredExe(void)const{
    return (this->requiredExe);
}

int PresidentialPardonForm::getRequiredGrade(void)const{
    return (this->requiredGrade);
}

bool PresidentialPardonForm::getSign(void)const{
    return (this->sign);
}

std::string PresidentialPardonForm::getTarget(void)const{
    return (this->target);
}

/*-----------------------------Overloaded------------------------*/

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src){
    
    if (this != &src)
    {
        this->target = src.getTarget();
        return *this;
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const PresidentialPardonForm &src){

    out << src.getName() << ", required to execute : " << src.getRequiredExe() << ", required grade : " << src.getRequiredGrade() << ", sign : " << src.getSign() << ", target : " << src.getTarget();
    return (out);
}

const char* PresidentialPardonForm::GradeTooLowException::what()const throw(){
    return ("[Class PresidentialPardonForm] Grade too low");
}

const char* PresidentialPardonForm::GradeTooHighException::what()const throw(){
    return ("[Class PresidentialPardonForm] Grade too high");
}