#ifndef BUILDER_HPP
#define BUILDER_HPP

#include <string>

// 产品类
class Product {
public:
    void setPartA(const std::string& partA);
    void setPartB(const std::string& partB);
    void setPartC(const std::string& partC);

    void show() const;

private:
    std::string m_partA;
    std::string m_partB;
    std::string m_partC;
};

// 抽象建造者类
class Builder {
public:
    virtual ~Builder() {}

    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;

    virtual Product* getResult() = 0;
};

// 具体建造者类A
class ConcreteBuilderA : public Builder {
public:
    void buildPartA() override;
    void buildPartB() override;
    void buildPartC() override;

    Product* getResult() override;

private:
    Product m_product;
};

// 具体建造者类B
class ConcreteBuilderB : public Builder {
public:
    void buildPartA() override;
    void buildPartB() override;
    void buildPartC() override;

    Product* getResult() override;

private:
    Product m_product;
};

// 指挥者类
class Director {
public:
    // 选择一个建造者
    void setBuilder(Builder* builder);
    Product* construct();

private:
    Builder* m_builder;
};

#endif  // BUILDER_HPP