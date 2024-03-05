#include "NYPizzaStore.hpp"
#include "ChicagoPizzaStore.hpp"
#include "PizzaStore.hpp"
#include "Pizza.hpp"

int main()
{   
    // 两个pizza店铺，具体的工厂类
    auto nyStore = new NYPizzaStore();
    auto chicagoStore = new ChicagoPizzaStore();
    // 调用不同具体工厂类的创建对象实现
    auto nyCheese = nyStore->orderPizza("cheese");
    auto chicagoCheese = chicagoStore->orderPizza("cheese");

    return 0;
}
