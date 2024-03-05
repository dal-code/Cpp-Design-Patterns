#ifndef PROTOTYPE_HPP
#define PROTOTYPE_HPP
#include <iostream>
#include <string>

// 原型基类
class Prototype {
public:
    virtual Prototype* clone() = 0;
    virtual void setInfo(const std::string& info) = 0;
    virtual void printInfo() const = 0;
};

// 具体原型类 A
class ConcretePrototypeA : public Prototype {
private:
    std::string* info; // 使用指针进行深拷贝

public:
    ConcretePrototypeA();
    ConcretePrototypeA(const ConcretePrototypeA& other);
    ~ConcretePrototypeA();
    Prototype* clone() override;
    void setInfo(const std::string& info) override;
    void printInfo() const override;
};

// 具体原型类 B
class ConcretePrototypeB : public Prototype {
private:
    std::string* info; // 使用指针进行深拷贝

public:
    ConcretePrototypeB();
    ConcretePrototypeB(const ConcretePrototypeB& other);
    ~ConcretePrototypeB();
    Prototype* clone() override;
    void setInfo(const std::string& info) override;
    void printInfo() const override;
};
#endif // PROTOTYPE_HPP