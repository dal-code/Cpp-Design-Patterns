#include <iostream>
#include <string>

// 抽象产品类
class Pizza {
public:
    virtual void prepare() = 0;
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
};

// 具体产品类
class CheesePizza : public Pizza {
public:
    void prepare() override {
        std::cout << "Preparing Cheese Pizza" << std::endl;
    }

    void bake() override {
        std::cout << "Baking Cheese Pizza" << std::endl;
    }

    void cut() override {
        std::cout << "Cutting Cheese Pizza" << std::endl;
    }

    void box() override {
        std::cout << "Boxing Cheese Pizza" << std::endl;
    }
};

class PepperoniPizza : public Pizza {
public:
    void prepare() override {
        std::cout << "Preparing Pepperoni Pizza" << std::endl;
    }

    void bake() override {
        std::cout << "Baking Pepperoni Pizza" << std::endl;
    }

    void cut() override {
        std::cout << "Cutting Pepperoni Pizza" << std::endl;
    }

    void box() override {
        std::cout << "Boxing Pepperoni Pizza" << std::endl;
    }
};

// 简单工厂类
class SimplePizzaFactory {
public:
    Pizza* createPizza(const std::string& type) {
        if (type == "cheese") {
            return new CheesePizza();
        } else if (type == "pepperoni") {
            return new PepperoniPizza();
        }

        return nullptr;
    }
};

// 客户端代码
int main() {
    // 创建简单工厂对象
    SimplePizzaFactory factory;

    // 使用简单工厂对象创建具体产品对象
    Pizza* cheesePizza = factory.createPizza("cheese");
    if (cheesePizza) {
        cheesePizza->prepare();
        cheesePizza->bake();
        cheesePizza->cut();
        cheesePizza->box();
        delete cheesePizza;
    }

    Pizza* pepperoniPizza = factory.createPizza("pepperoni");
    if (pepperoniPizza) {
        pepperoniPizza->prepare();
        pepperoniPizza->bake();
        pepperoniPizza->cut();
        pepperoniPizza->box();
        delete pepperoniPizza;
    }

    return 0;
}