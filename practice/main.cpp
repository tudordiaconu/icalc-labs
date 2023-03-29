#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <boost/random.hpp>

int main() {
    // Method 1: Using the rand() function
    std::srand(std::time(nullptr));
    int randomNumber1 = std::rand() % 100 + 1;

    std::cout << "Method 1: Random number generated using rand(): " << randomNumber1 << std::endl;

    // Method 2: Using random_device and mt19937 engine from <random> library
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int randomNumber2 = dis(gen);

    std::cout << "Method 2: Random number generated using random_device and mt19937: " << randomNumber2 << std::endl;

    // Method 3: Using default_random_engine and uniform_int_distribution from <random> library
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 100);
    int randomNumber3 = distribution(generator);

    std::cout << "Method 3: Random number generated using default_random_engine and uniform_int_distribution: " << randomNumber3 << std::endl;

    // Method 4: Using the Boost C++ Libraries' random number generator
    boost::random::mt19937 boostGen(std::time(nullptr));
    boost::random::uniform_int_distribution<> boostDist(1, 100);
    int randomNumber4 = boostDist(boostGen);

    std::cout << "Method 4: Random number generated using Boost C++ Libraries: " << randomNumber4 << std::endl;

    // Method 5: Using C++11 random number generator
    std::random_device cpp11rd;
    std::mt19937 cpp11Gen(cpp11rd());
    std::uniform_int_distribution<> cpp11Dis(1, 100);
    int randomNumber5 = cpp11Dis(cpp11Gen);

    std::cout << "Method 5: Random number generated using C++11 random number generator: " << randomNumber5 << std::endl;

    return 0;
}