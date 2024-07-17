#ifndef DISPLAYELEMENT_HPP
#define DISPLAYELEMENT_HPP

/*事件展示的抽象接口*/
class DisplayElement {
public:
    virtual ~DisplayElement() = default;
    virtual void display() = 0;
};

#endif