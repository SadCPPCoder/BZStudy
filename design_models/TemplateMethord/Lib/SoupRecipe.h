/***************************************************
* Author:Zhang, Bob
* Date: 2020-03-30
* Description: This is a recipe for making a soup.
***************************************************/

#ifndef _SOUP_RECIPE_H
#define _SOUP_RECIPE_H

class SoupRecipe
{
public:
    void MakeSoup();
    virtual ~SoupRecipe();
// changes
protected:
    virtual void AddWater()=0;
    virtual void AddFood()=0;
private:
    void BoilWater();
    void BoilFoodAndWater();
    void KeepBoilingFor10Minutes();
    void MakeSoupFinished();
};

#endif /*_SOUP_RECIPE_H*/
