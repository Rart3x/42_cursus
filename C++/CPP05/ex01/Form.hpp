#pragma once

# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    private:
        const std::string name;
        bool sign;
        const int requiredExe;
        const int requiredGrade;

    public:
        Form(std::string const name, const int requiredExe, const int requiredGrade);
        Form(const Form &src);

        ~Form();

        Form& operator=(const Form &src);

        const std::string getName()const;
        int getRequiredExe()const;
        int getRequiredGrade()const;
        bool getSign()const;

        void beSigned(const Bureaucrat &src);

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream &out, Form const &src);