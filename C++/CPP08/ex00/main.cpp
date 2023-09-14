#include "easyfind.hpp"

int main(void){

    std::vector<int> vec;

    easyfind(vec, 0);

    for (std::size_t i = 0; i < 5; i++)
        vec.push_back(i);

    for (std::size_t k = 0; k < 10; k++)
        easyfind(vec, k);

    vec.push_back(-50);

    easyfind(vec, -50);

    return (0);
}
