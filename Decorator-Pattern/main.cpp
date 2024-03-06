#include "Espresso.hpp"
#include "Mocha.hpp"
#include "HouseBlend.hpp"

#include <iostream>

int main() {
    // 一个实际的饮料：浓咖啡，用基类指针指向
    std::unique_ptr<Beverage> b2 = std::make_unique<Espresso>(); 
    // 一个实际的装饰类，动态地添加、修改或删除对象的功能。对对象浓咖啡进行修饰，添加东西
    b2 = std::make_unique<Mocha>(std::move(b2));
    // 输出饮料和价格
    std::cout << b2->getDescription() << " $" << b2->cost() << std::endl;

    std::unique_ptr<Beverage> b3 = std::make_unique<HouseBlend>(); 
    b3 = std::make_unique<Mocha>(std::move(b3));
    std::cout << b3->getDescription() << " $" << b3->cost() << std::endl;
}