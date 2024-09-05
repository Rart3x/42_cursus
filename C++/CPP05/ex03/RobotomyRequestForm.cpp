#include "RobotomyRequestForm.hpp"

/*-----------------------------Constructors------------------------*/

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target) : AForm(name, 45, 72){

    this->target = target;
    this->sign = false;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src.name, 45, 72){
    
    this->target = src.getTarget();
    this->sign = src.sign;
}

/*-----------------------------Destructors------------------------*/

RobotomyRequestForm::~RobotomyRequestForm(){
}

void RobotomyRequestForm::beSigned(const Bureaucrat &src){

    if (src.getGrade() <= this->requiredGrade)
    {
        this->sign = true;
    }
    else
        throw AForm::GradeTooLowException();
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)const{
 
    if (executor.getGrade() > this->getRequiredExe()){
        throw Bureaucrat::GradeTooLowException();
    }
    else if (this->getSign() == false)
        throw Bureaucrat::NotSigned();
    else
    {
        unsigned int i = std::rand() % 2;

        std::cout << "[DRILL NOISES] : ";
        if (i == 0)
        {
           std::cout << "Robotomisation failed" << std::endl; 
        }
        else
            std::cout << "Robotomisation successfull" << std::endl;
    }
}

/*-----------------------------Getters------------------------*/

const std::string RobotomyRequestForm::getName(void)const{

    return (this->name);
}

int RobotomyRequestForm::getRequiredExe(void)const{

    return (this->requiredExe);
}

int RobotomyRequestForm::getRequiredGrade(void)const{

    return (this->requiredGrade);
}

bool RobotomyRequestForm::getSign(void)const{
    
    return (this->sign);
}

std::string RobotomyRequestForm::getTarget(void)const{

    return (this->target);
}

/*-----------------------------Overloaded------------------------*/

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src){
    
    if (this != &src)
    {
        this->target = src.getTarget();
        return *this;
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const RobotomyRequestForm &src){

    out << src.getName() << ", required to execute : " << src.getRequiredExe() << ", required grade : " << src.getRequiredGrade() << ", sign : " << src.getSign() << ", target : " << src.getTarget();
    return (out);
}

const char* RobotomyRequestForm::GradeTooLowException::what()const throw(){
    return ("[Class RobotomyRequestForm] Grade too low");
}

const char* RobotomyRequestForm::GradeTooHighException::what()const throw(){
    return ("[Class RobotomyRequestForm] Grade too high");
}