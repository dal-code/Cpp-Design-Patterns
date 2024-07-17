#ifndef WEATHERDATA_HPP
#define WEATHERDATA_HPP

#include "Subject.hpp"
#include "Observer.hpp"

#include <unordered_set>

/*天气数据是被观察者*/
class WeatherData : public Subject {
private:
    /*记录观察者*/
    std::unordered_set<Observer*> observers;
    /*天气数据*/
    float temperature; // 温度
    float humidity; // 湿度
    float pressure; // 压力
public:
    /*观察者注册*/
    void registerObserver(Observer* o) {
        observers.insert(o);
    }
    /*移除观察者*/
    void removeObserver(Observer* o) {
        observers.erase(o);
    }
    /*通知观察者*/
    void notifyObservers() {
        for(auto o : observers) {
            o->update(temperature, humidity, pressure);
        }
    }
    /*测量之后改变天气的数据*/
    void measurementsChanged() {
        notifyObservers();
    }
    /*测量之后设置数据 并 通知观察者*/
    void setMeasurements(float t, float h, float p) {
        temperature = t;
        humidity = h;
        pressure = p;
        measurementsChanged();
    }
};

#endif