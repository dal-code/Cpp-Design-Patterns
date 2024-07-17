#ifndef SUBJECT_HPP
#define SUBJECT_HPP

class Observer;

/*主题的 被观察者 的抽象接口*/
class Subject {
public:
    /*被观察者最基本的接口：注册观察者、移除观察者、记录观察者*/
    virtual ~Subject() = default;
    virtual void registerObserver(Observer*) = 0;
    virtual void removeObserver(Observer*) = 0;
    virtual void notifyObservers() = 0;
};

#endif