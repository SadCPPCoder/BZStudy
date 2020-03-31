/********************************************
* Author: Zhang, Bob
* Date:2020-03-30
* Description: This is a recipe for making soup.
**********************************************/

#include "SoupRecipe.h"
#include <iostream>

SoupRecipe::~SoupRecipe()
{
}

void SoupRecipe::MakeSoup()
{
    AddWater();
    BoilWater();
    AddFood();
    BoilFoodAndWater();
    KeepBoilingFor10Minutes();
    MakeSoupFinished();
}

void SoupRecipe::BoilWater()
{
    std::cout << "\tBoil Water...\n";
}

void SoupRecipe::BoilFoodAndWater()
{
    std::cout << "\tBoil the food...\n";
}

void SoupRecipe::KeepBoilingFor10Minutes()
{
    std::cout << "\tKeep the food boiled ten minutes.\n";
}

void SoupRecipe::MakeSoupFinished()
{
    std::cout << "\tPlease enjoy your soup!\n";
}
