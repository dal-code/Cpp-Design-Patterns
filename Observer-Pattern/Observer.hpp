#ifndef OBSERVER_HPP
#define OBSERVER_HPP

/*观察者的抽象接口，功能主要是更新观察者的数据*/
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(float temp, float humidity, float pressure) = 0;
};

#endif
