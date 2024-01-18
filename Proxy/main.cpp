#include <iostream>

// Subject（主题）接口
class Subject {
public:
    virtual void request() = 0;
};

// RealSubject（真实主题）
class RealSubject : public Subject {
public:
    void request() override {
        std::cout << "RealSubject: Handling request." << std::endl;
    }
};

// Proxy（代理）
class Proxy : public Subject {
private:
    RealSubject* realSubject;

public:
    void request() override {
        // 在访问真实主题之前或之后可以添加额外的逻辑
        if (realSubject == nullptr) {
            realSubject = new RealSubject();
        }

        // 调用真实主题的方法
        realSubject->request();
    }
};

// 客户端代码
int main() {
    // 创建代理对象
    Proxy proxy;

    // 通过代理对象访问真实主题
    proxy.request();

    return 0;
}