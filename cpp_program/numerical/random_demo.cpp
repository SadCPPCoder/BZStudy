/**********************************************************
* author: Zhang, Bob
* date: 2020.03.25
* description: practice the random engine and distribution.
***********************************************************/

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int main()
{
    // use default random engine to generate random number,
    // and distribute the number to our target number by
    // uniform int distribution.
    // each time run the program, the result will be same,
    // because we do not assign a seed to the engine.
    std::default_random_engine dre;
    std::uniform_int_distribution<int> dis(50, 100);
    for(int i=0;i<10;++i)
        std::cout<<dis(dre)<<" ";
    std::cout<<std::endl;

    // C++11 provide a shuffle standard function to shuffle
    // the item in the containers.
    std::vector<std::string> vecName = {"Bob", "Aglaia", "Paul", "Min", "Hang"};
    std::shuffle(vecName.begin(), vecName.end(), // range
                 dre);                           // source of randomness
    std::for_each(vecName.begin(), vecName.end(), [](std::string &name){
        std::cout << name << " ";});
    std::cout << std::endl;

    // Use current system clock as the seed to genarate 10 float
    using namespace std::chrono;
    auto time_count = duration_cast<milliseconds>(
                        system_clock::now().time_since_epoch()).count();
    std::default_random_engine dre1(time_count);
    std::uniform_real_distribution<float> disf(0, 100);
    for(int i=0; i<10; ++i)
    {
        // std::cout << disf(dre) << ' ';
        std::cout << disf(dre1) << ' ';
    }
    std::cout << std::endl;
}
