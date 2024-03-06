#include <iostream>

// 抽象主题类
class Subject {
public:
    virtual void request() const = 0;
};

// 具体主题类
class RealSubject : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject: Handling request." << std::endl;
    }
};

// 代理类
class Proxy : public Subject {
public:
    Proxy(Subject* realSubject) : realSubject_(realSubject) {}

    void request() const override {
        // 在调用真实主题对象之前可以执行一些额外的操作
        std::cout << "Proxy: Logging request." << std::endl;

        // 调用真实主题对象的请求方法
        realSubject_->request();

        // 在调用真实主题对象之后可以执行一些额外的操作
        std::cout << "Proxy: Post-processing request." << std::endl;
    }

private:
    Subject* realSubject_;
};

int main() {
    // 创建真实主题对象
    RealSubject realSubject;

    // 创建代理对象，并将真实主题对象传递给代理对象
    Proxy proxy(&realSubject);

    // 通过代理对象调用请求方法
    proxy.request();

    return 0;
}