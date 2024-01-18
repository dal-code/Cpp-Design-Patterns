#ifndef ESPRESSO_HPP
#define ESPRESSO_HPP

#include "Beverage.hpp"
//继承饮料，浓咖啡
class Espresso : public Beverage {
public:
    std::string getDescription() {
        return "Espresso";
    }

    double cost() {
        return 1.99;
    }
};

#endif