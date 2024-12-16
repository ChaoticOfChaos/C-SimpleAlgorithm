#ifndef RANDOMINT_HPP
#define RANDOMINT_HPP

#include <random>

int randomINT(int min, int max) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(generator);
}

#endif