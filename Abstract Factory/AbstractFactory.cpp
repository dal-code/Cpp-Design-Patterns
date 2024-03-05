#include "AbstractFactory.h"
#include <iostream>
// 具体产品的实现
void ConcreteProductA1::operationA() {
    std::cout << "ConcreteProductA1 operationA" << std::endl;
}

void ConcreteProductA2::operationA() {
    std::cout << "ConcreteProductA2 operationA" << std::endl;
}

void ConcreteProductB1::operationB() {
    std::cout << "ConcreteProductB1 operationB" << std::endl;
}

void ConcreteProductB2::operationB() {
    std::cout << "ConcreteProductB2 operationB" << std::endl;
}

// 具体工厂1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

// 具体工厂2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};
/*每个产品是一个族，一个产品有一个系列*/
int main() {
    // 使用具体工厂1创建产品
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();
    productA1->operationA();
    productB1->operationB();

    // 使用具体工厂2创建产品
    AbstractFactory* factory2 = new ConcreteFactory2();
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB2 = factory2->createProductB();
    productA2->operationA();
    productB2->operationB();

    delete factory1;
    delete factory2;
    delete productA1;
    delete productB1;
    delete productA2;
    delete productB2;

    return 0;
}