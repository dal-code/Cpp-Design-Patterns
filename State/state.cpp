#include <iostream>

// 前向声明状态类
class State;

// 上下文类
class Context {
private:
    State* currentState;  // 当前状态

public:
    Context();

    // 设置当前状态
    void setCurrentState(State* state);

    // 执行操作
    void executeOperation();
};

// 状态基类
class State {
protected:
    Context* context;  // 上下文对象

public:
    virtual ~State() {}

    // 设置上下文对象
    void setContext(Context* ctx) {
        context = ctx;
    }

    // 定义具体的操作
    virtual void operation() = 0;
};

// 具体状态类 A
class ConcreteStateA : public State {
public:
    void operation() override {
        std::cout << "执行具体状态 A 的操作" << std::endl;
        // 切换到下一个状态
        context->setCurrentState(new ConcreteStateB());
    }
};

// 具体状态类 B
class ConcreteStateB : public State {
public:
    void operation() override {
        std::cout << "执行具体状态 B 的操作" << std::endl;
        // 切换到下一个状态
        context->setCurrentState(new ConcreteStateC());
    }
};

// 具体状态类 C
class ConcreteStateC : public State {
public:
    void operation() override {
        std::cout << "执行具体状态 C 的操作" << std::endl;
        // 切换到下一个状态
        context->setCurrentState(new ConcreteStateA());
    }
};

Context::Context() {
    // 初始状态为具体状态 A
    currentState = new ConcreteStateA();
    currentState->setContext(this);
}

void Context::setCurrentState(State* state) {
    currentState = state;
    currentState->setContext(this);
}

void Context::executeOperation() {
    currentState->operation();
}

int main() {
    Context context;

    // 执行一系列操作，触发状态切换
    context.executeOperation();
    context.executeOperation();
    context.executeOperation();
    context.executeOperation();

    return 0;
}