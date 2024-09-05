#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm {

    private:
        std::string target;
    public:

        RobotomyRequestForm(std::string const name, std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &src);

        ~RobotomyRequestForm();

        RobotomyRequestForm& operator=(const RobotomyRequestForm &src);

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

std::ostream&   operator<<(std::ostream &out, RobotomyRequestForm const &src);