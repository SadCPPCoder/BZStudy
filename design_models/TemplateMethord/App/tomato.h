// Test code fo Template Method model
#ifndef TOMATO_H
#define TOMATO_H

#include "SoupRecipe.h"

class TomatoSoup: public SoupRecipe
{
public:
    void AddWater();
    void AddFood();
};

#endif /*TOMATO_H*/
