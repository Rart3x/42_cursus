#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm {

    private:
        std::string target;
    public:

        ShrubberyCreationForm(std::string const name, std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);

        ~ShrubberyCreationForm();

        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &src);

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

std::ostream&   operator<<(std::ostream &out, ShrubberyCreationForm const &src);