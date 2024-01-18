#ifndef HOUSEBLEND_HPP
#define HOUSEBLEND_HPP

#include "Beverage.hpp"
//继承饮料，自己调配的一种咖啡
class HouseBlend : public Beverage {
public:
    std::string getDescription() {
        return "House Blend Coffee";
    }

    double cost() {
        return .89;
    }
};

#endif