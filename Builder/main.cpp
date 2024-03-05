#include "builder.hpp"

int main() {
    // 创建具体建造者对象
    ConcreteBuilderA builder;

    // 创建指挥者对象，并设置具体建造者
    Director director;
    director.setBuilder(&builder);

    // 构建产品
    Product* product = director.construct();

    // 使用产品
    product->show();

    delete product;

    return 0;
}