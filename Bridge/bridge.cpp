#include <iostream>

// 实现的接口
class Implementor {
public:
    virtual void operationImpl() = 0;
};

// 具体实现类A
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() override {
        std::cout << "Concrete Implementor A operation" << std::endl;
    }
};

// 具体实现类B
class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() override {
        std::cout << "Concrete Implementor B operation" << std::endl;
    }
};

// 抽象类
class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* imp) : implementor(imp) {}

    virtual void operation() = 0;
};

// 扩展抽象类A
class RefinedAbstractionA : public Abstraction {
public:
    RefinedAbstractionA(Implementor* imp) : Abstraction(imp) {}

    void operation() override {
        std::cout << "Refined Abstraction A operation" << std::endl;
        implementor->operationImpl();
    }
};

// 扩展抽象类B
class RefinedAbstractionB : public Abstraction {
public:
    RefinedAbstractionB(Implementor* imp) : Abstraction(imp) {}

    void operation() override {
        std::cout << "Refined Abstraction B operation" << std::endl;
        implementor->operationImpl();
    }
};

int main() {
    /*接口实现*/
    Implementor* implementorA = new ConcreteImplementorA();
    /*抽象类*/
    Abstraction* abstractionA = new RefinedAbstractionA(implementorA);
    abstractionA->operation();

    std::cout << std::endl;

    Implementor* implementorB = new ConcreteImplementorB();
    Abstraction* abstractionB = new RefinedAbstractionB(implementorB);
    abstractionB->operation();

    delete implementorA;
    delete abstractionA;
    delete implementorB;
    delete abstractionB;

    return 0;
}