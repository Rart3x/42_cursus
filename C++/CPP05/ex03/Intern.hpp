#pragma once

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{

    public:
        Intern();
        Intern(const Intern &src);

        ~Intern();

        Intern& operator=(const Intern &src);

        PresidentialPardonForm& President(std::string formName, std::string targetForm);
        RobotomyRequestForm& Robotomy(std::string formName, std::string targetForm);
        ShrubberyCreationForm& Shrubbery(std::string formName, std::string targetForm);

        AForm* makeForm(std::string formName, std::string targetForm);

        class FormNameInexistant : public std::exception{
            public :
                virtual const char * what() const throw();
        };

    private :

};

