/*******************************************************
* author: Zhang, Bob
* date: 2020-03-27
* description: The usage of duration class.
*******************************************************/
#include <iostream>
#include <chrono>
#include <typeinfo>

int main()
{
	typedef std::chrono::duration<int, std::ratio<60>> my_minute;
	my_minute one_minute(1);
	std::cout << "one_minute object has " << one_minute.count() << " " 
	<< my_minute::period::num << "/" << my_minute::period::den << " seconds." << std::endl;

    std::cout << "type: " << typeid(my_minute::rep).name() << std::endl;
    std::cout << "type: " << typeid(int).name() << std::endl;
}
