#include "tomato.h"
#include "cabbage.h"
#include <iostream>

int main()
{
    std::cout << "Make a tomato soup:\n";
    TomatoSoup tsoup;
    tsoup.MakeSoup();
    
    std::cout << "\nMake a cabbage soup:\n";
    CabbageSoup csoup;
    csoup.MakeSoup();
}
