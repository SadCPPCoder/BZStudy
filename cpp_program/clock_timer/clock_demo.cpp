/******************************************
* author: Zhang, Bob
* date: 2020.03.26
* description: colock related function practice.
******************************************/

#include <iostream>
#include <chrono>
#include <ctime>

int main()
{
    using namespace std::chrono;

    std::cout << "now: " << duration_cast<milliseconds>(
    system_clock::now().time_since_epoch()).count() << std::endl;

    std::cout << "now: " << system_clock::to_time_t(system_clock::now()) << std::endl;
}
