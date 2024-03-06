#include <iostream>
// Adaptee 类表示原有的、不兼容的接口
class Adaptee {
public:
    void specificRequest() {
        std::cout << "Adaptee's specific request" << std::endl;
    }
};
// Target 类表示目标接口
class Target {
public:
    virtual void request() = 0;
};
// 类适配器
class AdapterClass : public Target, private Adaptee {
public:
    void request() override {
        std::cout << "AdapterClass's request" << std::endl;
        specificRequest();
    }
};
/*对象适配器*/
// Adapter 类继承自 Target 类，并将 Adaptee 对象作为成员变量，以实现对 Adaptee 接口的适配
class AdapterObject : public Target {
private:
    Adaptee* adaptee;

public:
    AdapterObject(Adaptee* adaptee) {
        this->adaptee = adaptee;
    }

    void request() override {
        std::cout << "AdapterObject's request" << std::endl;
        adaptee->specificRequest();
    }
};

int main() {
    // 类适配器示例
    Target* adapterClass = new AdapterClass();
    adapterClass->request();

    std::cout << std::endl;

    // 对象适配器示例
    Adaptee* adaptee = new Adaptee();
    Target* adapterObject = new AdapterObject(adaptee);
    adapterObject->request();

    delete adapterClass;
    delete adaptee;
    delete adapterObject;

    return 0;
}