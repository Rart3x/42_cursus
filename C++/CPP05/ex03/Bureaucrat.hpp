#pragma once

# include <iostream>
# include <string>

# include "AForm.hpp"

class AForm;

class Bureaucrat{

    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(const Bureaucrat &src);

        ~Bureaucrat();

        Bureaucrat& operator=(const Bureaucrat &src);

        const std::string getName()const;
        int getGrade() const;

        void    incrementGrade();
        void    decrementGrade();

        void    signForm(AForm &src)const;
        void    executeForm(const AForm &form)const;
        
        class GradeTooLowException : public std::exception{
            public :
                virtual const char * what() const throw();
        };
        class GradeTooHighException : public std::exception{
            public :
                virtual const char * what() const throw();
        };
        class NotSigned : public std::exception{
            public :
                virtual const char * what() const throw();
        };

};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &src);