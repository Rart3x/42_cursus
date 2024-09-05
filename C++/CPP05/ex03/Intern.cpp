#include "Intern.hpp"

Intern::Intern(void){}

Intern::~Intern(void){}

Intern::Intern(const Intern &src){
    
    if (this != &src)
        *this = src;
}

PresidentialPardonForm& Intern::President(std::string formName, std::string targetForm) {
    PresidentialPardonForm *president = new PresidentialPardonForm(formName, targetForm);
    return *president;
}

RobotomyRequestForm& Intern::Robotomy(std::string formName, std::string targetForm) {
    RobotomyRequestForm *robotomy = new RobotomyRequestForm(formName, targetForm);
    return *robotomy;
}

ShrubberyCreationForm& Intern::Shrubbery(std::string formName, std::string targetForm) {
    ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm(formName, targetForm);
    return *shrubbery;
}

AForm* Intern::makeForm(std::string formName, std::string targetForm) {
    
    AForm* createdForm = NULL;
    size_t i = 0;

    std::string formsNames[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

    for (i = 0; i < 3; i++) {
        if (!formsNames[i].compare(formName))
            break;
    }

    switch (i) {
        case 0:
            createdForm = &President(formName, targetForm);
            break;
        case 1:
            createdForm = &Robotomy(formName, targetForm);
            break;
        case 2:
            createdForm = &Shrubbery(formName, targetForm);
            break;
    }
    i++;

    if (!createdForm)
        throw Intern::FormNameInexistant();
    std::cout << "Intern creates " << formName << std::endl;
    return createdForm;
}

/*-----------------------------Overloaded------------------------*/

Intern& Intern::operator=(const Intern &src){
    
    if (this != &src)
        return *this;
    return *this;
}

const char* Intern::FormNameInexistant::what()const throw(){
    return ("Form name doesn't exist");
}