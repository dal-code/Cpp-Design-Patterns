#include <iostream>
#include <vector>

// 前向声明被访问对象的基类
class Element;

// 访问者基类
class Visitor {
public:
    virtual ~Visitor() {}

    // 定义访问不同类型被访问对象的方法
    virtual void visit(Element& element) = 0;
};

// 具体访问者类 A
class ConcreteVisitorA : public Visitor {
public:
    void visit(Element& element) override {
        std::cout << "具体访问者 A 访问 " << element.getName() << std::endl;
    }
};

// 具体访问者类 B
class ConcreteVisitorB : public Visitor {
public:
    void visit(Element& element) override {
        std::cout << "具体访问者 B 访问 " << element.getName() << std::endl;
    }
};

// 被访问对象的基类
class Element {
public:
    virtual ~Element() {}

    // 定义接收访问者的方法
    virtual void accept(Visitor& visitor) = 0;

    // 获取元素名称
    virtual std::string getName() = 0;
};

// 具体被访问对象类 A
class ConcreteElementA : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }

    std::string getName() override {
        return "具体元素 A";
    }
};

// 具体被访问对象类 B
class ConcreteElementB : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }

    std::string getName() override {
        return "具体元素 B";
    }
};

// 对象结构类
class ObjectStructure {
private:
    std::vector<Element*> elements;

public:
    ~ObjectStructure() {
        for (Element* element : elements) {
            delete element;
        }
    }

    // 添加元素
    void addElement(Element* element) {
        elements.push_back(element);
    }

    // 执行访问操作
    void performVisit(Visitor& visitor) {
        for (Element* element : elements) {
            element->accept(visitor);
        }
    }
};

int main() {
    ObjectStructure objectStructure;

    // 添加具体被访问对象 A 和 B
    objectStructure.addElement(new ConcreteElementA());
    objectStructure.addElement(new ConcreteElementB());

    // 创建具体访问者 A 和 B
    ConcreteVisitorA visitorA;
    ConcreteVisitorB visitorB;

    // 对象结构执行访问操作
    objectStructure.performVisit(visitorA);
    objectStructure.performVisit(visitorB);

    return 0;
}