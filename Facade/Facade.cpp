#include <iostream>

// 子系统A
class SubsystemA {
public:
    void operationA() const {
        std::cout << "SubsystemA operation." << std::endl;
    }
};

// 子系统B
class SubsystemB {
public:
    void operationB() const {
        std::cout << "SubsystemB operation." << std::endl;
    }
};

// 门面类
class Facade {
public:
    Facade() {
        subsystemA_ = new SubsystemA();
        subsystemB_ = new SubsystemB();
    }

    ~Facade() {
        delete subsystemA_;
        delete subsystemB_;
    }

    void operation() const {
        subsystemA_->operationA();
        subsystemB_->operationB();
    }

private:
    SubsystemA* subsystemA_;
    SubsystemB* subsystemB_;
};

int main() {
    Facade facade;
    facade.operation();

    return 0;
}