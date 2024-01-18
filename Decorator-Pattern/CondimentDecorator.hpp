#ifndef CONDIMENTDECORATOR_HPP
#define CONDIMENTDECORATOR_HPP

#include "Beverage.hpp"

#include <memory>
//继承饮料，对饮料进行装饰的抽象类
class CondimentDecorator : public Beverage {
protected:
    std::unique_ptr<Beverage> beverage;
public:
    CondimentDecorator(std::unique_ptr<Beverage> b) : beverage(std::move(b)) {}
    virtual ~CondimentDecorator() = default;
};

#endif
