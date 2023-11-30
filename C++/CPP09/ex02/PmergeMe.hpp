#pragma once

#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

class PmergeMe{

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);

        ~PmergeMe();

        PmergeMe& operator=(const PmergeMe &src);

        void    displayFooter(void)const;
        void    displayIntDeque(std::deque<int> deque)const;
        void    displayIntVector(std::vector<int> vec)const;

        void    fillContainers(int ac, char **av);
        void    nbArgs(int ac)const;
        void    program(int ac, char **av);
        bool    testIfSort();

        void    createDuos(void);
        void    recursiveSort(std::vector<std::pair<int, int> >);

        int     binarySearch(int value);
        int     binarySearchDeque(int value);
        size_t  jacobsthalSuite(size_t iter);

        void    createDuosDeque(void);
        void    recursiveSortDeque(std::deque<std::pair<int, int> > vec);

        void    exceptions(void)const;

        class InvalidChar : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class InvalidNbArgs : public std::exception{
            public:
                virtual const char* what() const throw();
        };

    private:
        double vectorDuration;
        double dequeDuration;

        std::vector<std::pair<int, int> >   duos;
        std::deque<std::pair<int, int> >    duosDeque;

        std::vector<int>    values;
        std::deque<int>     valuesDeque;

        std::vector<int> valuesSorted;
        std::deque<int>  valuesSortedDeque;
};