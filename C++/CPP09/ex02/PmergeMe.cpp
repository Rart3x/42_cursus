#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void){}

PmergeMe::PmergeMe(const PmergeMe &src){
    if (this != &src)
        *this = src;
}

PmergeMe::~PmergeMe(void){}

PmergeMe&   PmergeMe::operator=(const PmergeMe &src){
    if (this != &src)
        return (*this);
    return (*this);
}

int    PmergeMe::binarySearch(int value){
    int L;
    int R;
    int m;

    L = 0;
    R = this->valuesSorted.size() - 1;
    while (L <= R) {
        m = L + (R - L) / 2;
        if (value > this->valuesSorted[m]) {
            L = m + 1;
        }
        else if (value < this->valuesSorted[m]) {
            R = m - 1;
        }
        else {
            return m + 1;
        }
    }
    return (L);
}

int    PmergeMe::binarySearchDeque(int value){
    int L;
    int R;
    int m;

    L = 0;
    R = this->valuesSortedDeque.size() - 1;
    while (L <= R) {
        m = L + (R - L) / 2;
        if (value > this->valuesSortedDeque[m]) {
            L = m + 1;
        }
        else if (value < this->valuesSortedDeque[m]) {
            R = m - 1;
        }
        else {
            return m + 1;
        }
    }
    return (L);
}

void    PmergeMe::createDuos(void){
    
    this->duos.resize((this->values.size() / 2));

    std::vector<std::pair<int, int> >::iterator iterator = this->duos.begin();

    for (size_t i = 0; i < this->values.size() - 1; i+=2){
        (*iterator) = std::make_pair(
            std::max(this->values[i], this->values[i + 1]),
            std::min(this->values[i], this->values[i + 1]));
        iterator++;
    }
}

void    PmergeMe::displayFooter(void)const{

    std::cout << "before [Vector] : ";
    displayIntVector(this->values);
    std::cout << "after [Vector] : ";
    displayIntVector(this->valuesSorted);
    std::cout << "before [Deque]: ";
    displayIntDeque(this->valuesDeque);
    std::cout << "after [Deque]: ";
    displayIntDeque(this->valuesSortedDeque);
    std::cout << "time to process a range of " << this->values.size()
        << " elements with std::vector : " << this->vectorDuration << " µs" << std::endl;
    std::cout << "time to process a range of " << this->valuesDeque.size()
        << " elements with std::deque  : " << this->dequeDuration << " µs" << std::endl;
}

void    PmergeMe::displayIntVector(std::vector<int> vec)const{

    std::vector<int>::iterator iterator = vec.begin();
    while (iterator != vec.end()){
        std::cout << (*iterator) << " ";
        iterator++;
    }
    std::cout << std::endl;
}

void    PmergeMe::fillContainers(int ac, char **av){

    for (size_t i = 1; i < (size_t)ac; i++){
        for(size_t j = 0; j < strlen(av[i]) - 1; j++){
            if (!isdigit(av[i][j]))
                throw InvalidChar();
        }
        this->values.push_back(atoi(av[i]));
        this->valuesDeque.push_back(atoi(av[i]));
    }
}

void    PmergeMe::nbArgs(int ac)const{
    
    if (ac < 2)
        throw PmergeMe::InvalidNbArgs();
}

bool    PmergeMe::testIfSort(){
    std::vector<int> copy(this->values);

    std::sort(copy.begin(), copy.end());
    for (size_t i = 0; i < copy.size(); i++){
        if (copy[i] != this->valuesSorted[i])
        {
            std::cout << "error: array is unsorted" << std::endl;
            return false;
        }
    }
    return true;
}

void    PmergeMe::program(int ac, char **av){

    clock_t timeVector;

    int indexInsert;

    bool odd = false;

    try {
        this->nbArgs(ac);
        this->fillContainers(ac, av);
    }
    catch(...) {
        exceptions();
        return;
    }

    try
    {
        timeVector = clock();

        this->createDuos();

        if (this->duos.size() == 0) {
            std::cout << "error: array is already sorted" << std::endl;
            return ;
        }

        this->recursiveSort(this->duos);

        std::vector<std::pair<int, int > >::iterator last;

        if (this->duos.size() % 2 != 0 && this->duos.size() != 1) {
            last = --this->duos.end();

            this->duos.erase(this->duos.end() - 1);
            odd = true;
        }

        std::vector<std::pair<int, int> >::iterator iterator = this->duos.begin();

        while (iterator != this->duos.end() && this->duos.size() != 1) {
            indexInsert = this->binarySearch((*iterator).second);
            this->valuesSorted.insert(this->valuesSorted.begin() + indexInsert,(*iterator).second);
            iterator++;
        }

        if (odd) {
            indexInsert = this->binarySearch((*last).first);
            this->valuesSorted.insert(this->valuesSorted.begin() + indexInsert, (*last).first);
            indexInsert = this->binarySearch((*last).second);
            this->valuesSorted.insert(this->valuesSorted.begin() + indexInsert, (*last).second);
        }

        if (this->values.size() % 2 != 0) {
            indexInsert = this->binarySearch(*(this->values.end() - 1));
            this->valuesSorted.insert(this->valuesSorted.begin() + indexInsert, *(--this->values.end()));
        }

        this->vectorDuration = ((double)timeVector / CLOCKS_PER_SEC) * 1000000;
    }
    catch(...)
    {
        exceptions();
    }

    clock_t timeDeque;

    int indexInsertDeque;

    bool oddDeque = false;
    
    try
    {
        timeDeque = clock();

        this->createDuosDeque();

        if (this->duosDeque.size() == 0) {
            std::cout << "error: array is already sorted" << std::endl;
            return ;
        }

        this->recursiveSortDeque(this->duosDeque);

        std::deque<std::pair<int, int > >::iterator lastDeque;

        if (this->duosDeque.size() % 2 != 0 && this->duosDeque.size() != 1) {
            lastDeque = --this->duosDeque.end();

            this->duosDeque.erase(this->duosDeque.end() - 1);
            oddDeque = true;
        }

        std::deque<std::pair<int, int> >::iterator iteratorDeque = this->duosDeque.begin();

        while (iteratorDeque != this->duosDeque.end() && this->duosDeque.size() != 1) {
            indexInsertDeque = this->binarySearchDeque((*iteratorDeque).second);
            this->valuesSortedDeque.insert(this->valuesSortedDeque.begin() + indexInsertDeque,(*iteratorDeque).second);
            iteratorDeque++;
        }

        if (oddDeque) {
            indexInsertDeque = this->binarySearchDeque((*lastDeque).first);
            this->valuesSortedDeque.insert(this->valuesSortedDeque.begin() + indexInsertDeque, (*lastDeque).first);
            indexInsertDeque = this->binarySearchDeque((*lastDeque).second);
            this->valuesSortedDeque.insert(this->valuesSortedDeque.begin() + indexInsertDeque, (*lastDeque).second);
        }

        if (this->valuesDeque.size() % 2 != 0) {
            indexInsertDeque = this->binarySearchDeque(*(this->valuesDeque.end() - 1));
            this->valuesSortedDeque.insert(this->valuesSortedDeque.begin() + indexInsertDeque, *(--this->valuesDeque.end()));
        }

        this->dequeDuration = ((double)timeDeque / CLOCKS_PER_SEC) * 1000000;
        this->displayFooter();
    }
    catch(...)
    {
        exceptions();
    }
}

size_t PmergeMe::jacobsthalSuite(size_t iter){
    size_t i;
    size_t prev;
    size_t prev_prev;

    i = 0;
    prev = 2;
    prev_prev = 0;
    while (i < iter) {
        if (i == 0 || i == 1) {
            prev_prev = prev;
            i++;
            continue;
        }
        prev = prev_prev * 2 + prev;
        prev_prev = prev - (prev_prev * 2);
        i++;
    }
    return (prev);
}

void    PmergeMe::recursiveSort(std::vector<std::pair<int, int> > vec){

    std::vector<std::pair<int, int> > newVec;

    std::vector<std::pair<int, int > >::iterator last;
    std::vector<std::pair<int, int> >::iterator iterator;

    bool odd = false;

    int indexInsert;
    int indexMax;

    if (vec.size() == 1)
    {
        this->valuesSorted.insert(this->valuesSorted.begin() , (vec.begin()->first));
        this->valuesSorted.insert(this->valuesSorted.begin() , (vec.begin()->second));
        return ;
    }

    newVec.resize((vec.size() / 2));
    iterator = newVec.begin();
    for (size_t i = 0; i < vec.size() - 1; i+=2){
        (*iterator) = std::make_pair(std::max(vec[i].first, vec[i + 1].first), std::min(vec[i].first, vec[i + 1].first));
        iterator++;
    }

    if (newVec.size() != 1)
    {
        this->recursiveSort(newVec);
        iterator = newVec.begin();
        if (newVec.size() % 2 != 0){
            last = --newVec.end();
            newVec.erase(newVec.end() - 1);
            odd = true;
        }

        //look for minimum paired with the minimum of the maximums (this->valueSorted)
        for (size_t i = 0; i < newVec.size(); i++){
            if (*this->valuesSorted.begin() == newVec[i].first){
                indexMax = i;
            }
        }

        this->valuesSorted.insert(this->valuesSorted.begin(), newVec[indexMax].second);
        newVec.erase(newVec.begin() + indexMax);
        int k = 0;

        size_t nbGroups = this->jacobsthalSuite(k);

        if (nbGroups > newVec.size())
            nbGroups = newVec.size();

        while (newVec.size() != 0){
            if (nbGroups == 0){
                nbGroups = this->jacobsthalSuite(k++);
                if (nbGroups > newVec.size())
                    nbGroups = newVec.size();
            }

            indexInsert = this->binarySearch(newVec[nbGroups - 1].second);
            this->valuesSorted.insert(this->valuesSorted.begin() + indexInsert, newVec[nbGroups - 1].second);

            newVec.erase(newVec.begin() + nbGroups - 1);
            nbGroups--;
        }

        if (odd) {
            indexInsert = this->binarySearch((*last).first);
            this->valuesSorted.insert(this->valuesSorted.begin() + indexInsert, (*last).first);
            indexInsert = this->binarySearch((*last).second);
            this->valuesSorted.insert(this->valuesSorted.begin() + indexInsert, (*last).second);
        }
    }
    else
    {
        this->valuesSorted.insert(this->valuesSorted.begin() , (newVec.begin()->first));
        this->valuesSorted.insert(this->valuesSorted.begin() , (newVec.begin()->second));
    }
}

/*-----------------------------------------------------DEQUE-----------------------------------------------------*/

void    PmergeMe::createDuosDeque(void){
    
    this->duosDeque.resize((this->valuesDeque.size() / 2));

    std::deque<std::pair<int, int> >::iterator iterator = this->duosDeque.begin();

    for (size_t i = 0; i < this->valuesDeque.size() - 1; i+=2){
        (*iterator) = std::make_pair(
            std::max(this->valuesDeque[i], this->valuesDeque[i + 1]),
            std::min(this->valuesDeque[i], this->valuesDeque[i + 1]));
        iterator++;
    }
}

void    PmergeMe::displayIntDeque(std::deque<int> deque)const{

    std::deque<int>::iterator iterator = deque.begin();
    while (iterator != deque.end()){
        std::cout << (*iterator) << " ";
        iterator++;
    }
    std::cout << std::endl;
}

void    PmergeMe::recursiveSortDeque(std::deque<std::pair<int, int> > deque){

    std::deque<std::pair<int, int> > newDeque;

    std::deque<std::pair<int, int > >::iterator last;
    std::deque<std::pair<int, int> >::iterator iterator;

    bool odd = false;

    int indexInsert;
    int indexMax;

    if (deque.size() == 1)
    {
        this->valuesSortedDeque.insert(this->valuesSortedDeque.begin() , (deque.begin()->first));
        this->valuesSortedDeque.insert(this->valuesSortedDeque.begin() , (deque.begin()->second));
        return ;
    }

    newDeque.resize((deque.size() / 2));
    iterator = newDeque.begin();
    for (size_t i = 0; i < deque.size() - 1; i+=2){
        (*iterator) = std::make_pair(std::max(deque[i].first, deque[i + 1].first), std::min(deque[i].first, deque[i + 1].first));
        iterator++;
    }

    if (newDeque.size() != 1)
    {
        this->recursiveSortDeque(newDeque);
        iterator = newDeque.begin();
        if (newDeque.size() % 2 != 0){
            last = --newDeque.end();
            newDeque.erase(newDeque.end() - 1);
            odd = true;
        }

        //look for minimum paired with the minimum of the maximums (this->valueSorted)
        for (size_t i = 0; i < newDeque.size(); i++){
            if (*this->valuesSortedDeque.begin() == newDeque[i].first){
                indexMax = i;
            }
        }

        this->valuesSortedDeque.insert(this->valuesSortedDeque.begin(), newDeque[indexMax].second);
        newDeque.erase(newDeque.begin() + indexMax);
        int k = 0;

        size_t nbGroups = this->jacobsthalSuite(k);

        if (nbGroups > newDeque.size())
            nbGroups = newDeque.size();

        while (newDeque.size() != 0){
            if (nbGroups == 0){
                nbGroups = this->jacobsthalSuite(k++);
                if (nbGroups > newDeque.size())
                    nbGroups = newDeque.size();
            }

            indexInsert = this->binarySearchDeque(newDeque[nbGroups - 1].second);
            this->valuesSortedDeque.insert(this->valuesSortedDeque.begin() + indexInsert, newDeque[nbGroups - 1].second);

            newDeque.erase(newDeque.begin() + nbGroups - 1);
            nbGroups--;
        }

        if (odd) {
            indexInsert = this->binarySearchDeque((*last).first);
            this->valuesSortedDeque.insert(this->valuesSortedDeque.begin() + indexInsert, (*last).first);
            indexInsert = this->binarySearchDeque((*last).second);
            this->valuesSortedDeque.insert(this->valuesSortedDeque.begin() + indexInsert, (*last).second);
        }
    }
    else
    {
        this->valuesSortedDeque.insert(this->valuesSortedDeque.begin() , (newDeque.begin()->first));
        this->valuesSortedDeque.insert(this->valuesSortedDeque.begin() , (newDeque.begin()->second));
    }
}

void    PmergeMe::exceptions(void)const{

    try
    {
        throw;
    }
    catch(PmergeMe::InvalidChar &e){
        std::cout << e.what() << std::endl;
    }
    catch(PmergeMe::InvalidNbArgs &e){
        std::cout << e.what() << std::endl;
    }
}

const char* PmergeMe::InvalidChar::what() const throw(){
    return ("error: invalid character");
}

const char* PmergeMe::InvalidNbArgs::what() const throw(){
    return ("error: invalid number of arguments");
}