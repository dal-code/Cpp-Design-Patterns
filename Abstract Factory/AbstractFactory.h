// 抽象产品A
class AbstractProductA {
public:
    virtual void operationA() = 0;
};

// 具体产品A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void operationA() override;
};

// 具体产品A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void operationA() override;
};

// 抽象产品B
class AbstractProductB {
public:
    virtual void operationB() = 0;
};

// 具体产品B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void operationB() override;
};

// 具体产品B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void operationB() override;
};

// 抽象工厂
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};