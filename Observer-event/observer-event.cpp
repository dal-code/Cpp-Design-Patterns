#include <iostream>
#include <functional>
#include <vector>

// 事件委托类型
using EventDelegate = std::function<void()>;

// 主题类（被观察者）
class Subject {
private:
    std::vector<EventDelegate> delegates;

public:
    // 注册观察者
    void addObserver(const EventDelegate& delegate) {
        delegates.push_back(delegate);
    }

    // 通知观察者
    void notifyObservers() {
        for (const auto& delegate : delegates) {
            delegate();
        }
    }
};

// 观察者类
class Observer {
public:
    void onEvent() {
        std::cout << "观察者收到事件通知" << std::endl;
    }
};

int main() {
    Subject subject;
    Observer observer;

    // 创建事件委托，将观察者的成员函数绑定到事件委托上
    EventDelegate delegate = std::bind(&Observer::onEvent, &observer);

    // 注册观察者
    subject.addObserver(delegate);

    // 触发事件，通知观察者
    subject.notifyObservers();

    return 0;
}