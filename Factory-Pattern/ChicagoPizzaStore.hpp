#ifndef CHICAGOPIZZASTORE_HPP
#define CHICAGOPIZZASTORE_HPP

#include "PizzaStore.hpp"
#include "ChicagoStyleCheesePizza.hpp"
#include "ChicagoStylePepperoniPizza.hpp"
//继承抽象基类，并对纯虚函数进行重载
class ChicagoPizzaStore : public PizzaStore {
public:
    std::unique_ptr<Pizza> createPizza(std::string type) {
        std::unique_ptr<Pizza> pizza = nullptr;

        if (type == "cheese")
        {
            //工厂具体类，需要产品具体类  来创建对象
            pizza = std::make_unique<ChicagoStyleCheesePizza>();
        }
        else if (type == "pepperoni")
        {
            pizza = std::make_unique<ChicagoStylePepperoniPizza>();
        }
        return pizza;
    }
};

#endif