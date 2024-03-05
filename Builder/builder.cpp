#include "builder.hpp"
#include <iostream>

// Product类的成员函数定义
void Product::setPartA(const std::string& partA) {
    m_partA = partA;
}

void Product::setPartB(const std::string& partB) {
    m_partB = partB;
}

void Product::setPartC(const std::string& partC) {
    m_partC = partC;
}

void Product::show() const {
    std::cout << "Part A: " << m_partA << std::endl;
    std::cout << "Part B: " << m_partB << std::endl;
    std::cout << "Part C: " << m_partC << std::endl;
}

// ConcreteBuilderA类的成员函数定义
void ConcreteBuilderA::buildPartA() {
    m_product.setPartA("Part A - Builder A");
}

void ConcreteBuilderA::buildPartB() {
    m_product.setPartB("Part B - Builder A");
}

void ConcreteBuilderA::buildPartC() {
    m_product.setPartC("Part C - Builder A");
}

Product* ConcreteBuilderA::getResult() {
    return &m_product;
}

// ConcreteBuilderB类的成员函数定义
void ConcreteBuilderB::buildPartA() {
    m_product.setPartA("Part A - Builder B");
}

void ConcreteBuilderB::buildPartB() {
    m_product.setPartB("Part B - Builder B");
}

void ConcreteBuilderB::buildPartC() {
    m_product.setPartC("Part C - Builder B");
}

Product* ConcreteBuilderB::getResult() {
    return &m_product;
}

// Director类的成员函数定义
void Director::setBuilder(Builder* builder) {
    m_builder = builder;
}

Product* Director::construct() {
    m_builder->buildPartA();
    m_builder->buildPartB();
    m_builder->buildPartC();
    return m_builder->getResult();
}