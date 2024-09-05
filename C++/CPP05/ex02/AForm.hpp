#pragma once

# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

    protected:
        const std::string name;
        bool sign;
        const int requiredExe;
        const int requiredGrade;

    public:
        AForm(std::string const name, const int requiredExe, const int requiredGrade);
        AForm(const AForm &src);

        ~AForm();

        AForm& operator=(const AForm &src);

        const std::string getName()const;
        bool getSign()const;
        int getRequiredExe()const;
        int getRequiredGrade()const;

        void beSigned(const Bureaucrat &src);
        virtual void execute(Bureaucrat const &executor)const = 0;

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream &out, AForm const &src);