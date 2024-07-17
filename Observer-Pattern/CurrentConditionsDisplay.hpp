#ifndef CURRENTCONDITIONSDISPLAY_HPP
#define CURRENTCONDITIONSDISPLAY_HPP

#include "Observer.hpp"
#include "DisplayElement.hpp"

#include <iostream>
#include <memory>

/*对被观察者的内容进行展示， 这个类就是观察者，只是做了展示*/
class CurrentConditionsDisplay : public Observer, public DisplayElement {
private:
    /*基本的数据：温度、湿度、天气数据的指针*/
    float temperature;
    float humidity;
    std::shared_ptr<Subject> weatherData;
public:
    /*有参构造函数，传入一个被观察者的指针*/
    CurrentConditionsDisplay(std::shared_ptr<Subject> w) : 
        temperature(0.0f), humidity(0.0f), weatherData(std::move(w)) {
    }

    void registerObserver() {
        weatherData->registerObserver(this);
    }
    /*析构的时候移除观察者*/
    ~CurrentConditionsDisplay() {
        weatherData->removeObserver(this);
    }

    void update(float t, float h, float p) {
        temperature = t;
        humidity = h;
        display();
    }

    void display() {
        std::cout << "Current condidions: " << temperature << "F degrees and " 
            << humidity << "% humidity" << std::endl;
    }
};

#endif
