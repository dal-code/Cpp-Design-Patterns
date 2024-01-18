#ifndef NYSTYLECHEESEPIZZA_HPP
#define NYSTYLECHEESEPIZZA_HPP

#include "Pizza.hpp"
//继承产品的抽象基类，然后对基类的属性进行更改
class NYStyleCheesePizza : public Pizza {
public:
    NYStyleCheesePizza()
    {
        name = "NY Style sauce and cheese pizza";
        dough = "Thin crust dough";
        sauce = "Marinara sauce";
        toppings.push_back("Gratted reggiano cheese");
    }
};

#endif