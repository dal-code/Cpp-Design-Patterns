#include "Prototype.hpp"

int main() {
    // 创建具体原型对象
    ConcretePrototypeA* prototypeA = new ConcretePrototypeA();
    prototypeA->setInfo("Prototype A Object");

    ConcretePrototypeB* prototypeB = new ConcretePrototypeB();
    prototypeB->setInfo("Prototype B Object");

    // 克隆原型对象
    Prototype* clonedPrototypeA = prototypeA->clone();
    Prototype* clonedPrototypeB = prototypeB->clone();

    // 输出原型对象信息
    prototypeA->printInfo();
    clonedPrototypeA->printInfo();

    prototypeB->printInfo();
    clonedPrototypeB->printInfo();

    // 释放内存
    delete prototypeA;
    delete prototypeB;
    delete clonedPrototypeA;
    delete clonedPrototypeB;

    return 0;
}