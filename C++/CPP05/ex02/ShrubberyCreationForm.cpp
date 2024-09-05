#include "ShrubberyCreationForm.hpp"

/*-----------------------------Constructors------------------------*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) : AForm(name, 137, 145){

    this->target = target;
    this->sign = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src.name, 137, 145){
    
    this->target = src.getTarget();
    this->sign = src.sign;
}

/*-----------------------------Constructors------------------------*/

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::beSigned(const Bureaucrat &src){

    if (src.getGrade() <= this->requiredGrade)
    {
        this->sign = true;
    }
    else
        throw AForm::GradeTooLowException();
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)const{
 
    if (executor.getGrade() > this->getRequiredExe()){
        throw Bureaucrat::GradeTooLowException();
    }
    else if (this->getSign() == false)
        throw Bureaucrat::NotSigned();
    else
    {
        std::ofstream outfile(this->getTarget().append("_shrubbery").c_str());

        outfile << "       ###" << std::endl;
        outfile << "      #o###" << std::endl;
        outfile << "    #####o###" << std::endl;
        outfile << "   #o###|#/###" << std::endl;
        outfile << "    ####|/#o#" << std::endl;
        outfile << "     # }|{  #" << std::endl;
        outfile << "       }|{" << std::endl;
        outfile << std::endl;

        std::cout << "ASCII Tree successfully created !" << std::endl;
        outfile.close();
    }
}

/*-----------------------------Getters------------------------*/

const std::string ShrubberyCreationForm::getName(void)const{
    return (this->name);
}

int ShrubberyCreationForm::getRequiredExe(void)const{
    return (this->requiredExe);
}

int ShrubberyCreationForm::getRequiredGrade(void)const{
    return (this->requiredGrade);
}

bool ShrubberyCreationForm::getSign(void)const{
    return (this->sign);
}

std::string ShrubberyCreationForm::getTarget(void)const{
    return (this->target);
}

/*-----------------------------Overloaded------------------------*/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src){
    
    if (this != &src)
    {
        this->target = src.getTarget();
        return *this;
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm &src){

    out << src.getName() << ", required to execute : " << src.getRequiredExe() << ", required grade  : " << src.getRequiredGrade() << ", sign : " << src.getSign() << ", target : " << src.getTarget();
    return (out);
}

const char* ShrubberyCreationForm::GradeTooLowException::what()const throw(){
    return ("[Class ShrubberyCreationForm] Grade too low");
}

const char* ShrubberyCreationForm::GradeTooHighException::what()const throw(){
    return ("[Class ShrubberyCreationForm] Grade too high");
}