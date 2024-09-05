#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm {

    private:
        std::string target;
    public:

        PresidentialPardonForm(std::string const name, std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &src);

        ~PresidentialPardonForm();

        PresidentialPardonForm& operator=(const PresidentialPardonForm &src);

        const std::string   getName()const;
        int                 getRequiredExe()const;
        int                 getRequiredGrade()const;
        bool                getSign()const;
        std::string         getTarget()const;

        void beSigned(const Bureaucrat &src);
        void execute(Bureaucrat const &executor)const;

        class GradeTooLowException : public std::exception{
            public :
                virtual const char * what() const throw();
        };
        class GradeTooHighException : public std::exception{
            public :
                virtual const char * what() const throw();
        };

};

std::ostream&   operator<<(std::ostream &out, PresidentialPardonForm const &src);