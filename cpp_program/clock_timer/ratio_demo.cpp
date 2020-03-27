/*************************************************
* author: Zhang, Bob
* date: 2020-03-27
* description: Practice the usage of ratio.
* 分数，编译时类型，包含num（分子），den（分母）。
************************************************/

#include <iostream>
#include <ratio>

int main()
{
    typedef std::ratio<1,3> one_third;
    typedef std::ratio<2,4> two_fourths;
    
    std::cout << "one_third= " << one_third::num << "/" << one_third::den << std::endl;
    std::cout << "two_fourths= " << two_fourths::num << "/" << two_fourths::den << std::endl;

    typedef std::ratio_add<one_third, two_fourths> sum;

    std::cout << "sum= " << sum::num << "/" << sum::den;
    std::cout << " ( whick is: " << ( double(sum::num) / sum::den ) << ")" << std::endl;

    std::cout << "1 kilogram has " << ( std::kilo::num / std::kilo::den ) << "grams";
    std::cout << std::endl;

    return 0;
}

