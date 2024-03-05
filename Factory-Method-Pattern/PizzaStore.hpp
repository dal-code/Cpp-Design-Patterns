#ifndef PIZZASTORE_HPP
#define PIZZASTORE_HPP

#include "Pizza.hpp"

#include <memory>
//抽象工厂基类
class PizzaStore {
public:
    std::unique_ptr<Pizza> orderPizza(std::string type) {
        auto pizza = createPizza(type);
        if(pizza != nullptr)
        {
            std::cout << "\n--- Making a " + pizza->getName() + " ---\n \n";
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
        }
        return pizza;
    }
    // 创建产品对象的抽象方法，具体的产品类继承并实现，解耦了对象的创建和使用，符合开闭原则
    virtual std::unique_ptr<Pizza> createPizza(std::string type) = 0;
};

#endif