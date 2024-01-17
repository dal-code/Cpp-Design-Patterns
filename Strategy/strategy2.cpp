#include<memory>
#include <iostream>

// Context 类定义实现算法策略的参数
class Context {
    // ...
};

//抽象strategy
class TaxStrategy{
public:
    virtual double Calculate(const Context& context)=0;
    virtual ~TaxStrategy(){}
};

//ConcreteStrategy
class CNTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};

class USTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};

class DETax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};


class FRTax : public TaxStrategy{
public:
	virtual double Calculate(const Context& context){
		//.........
	}
};

// 简单工厂类
class StrategyFactory {
public:
    static std::unique_ptr<TaxStrategy> NewStrategy(char condition) {
        if (condition == 'A') {
            return std::make_unique<CNTax>();
        } else if (condition == 'B') {
            return std::make_unique<USTax>();
        } else {
            throw std::runtime_error("Invalid condition");
        }
    }
};



//策略模式与简单工厂结合，
class SalesOrder{
private:
    //让客户端代码不用实例化对象，而是在策略工厂中实例化
    std::unique_ptr<TaxStrategy> strategy;

public:
    SalesOrder(StrategyFactory* strategyFactory, char condition){
        this->strategy = strategyFactory->NewStrategy(condition);
    }

    double CalculateTax(){
        //...
        Context context;
        
        double val = strategy->Calculate(context); //多态调用
    }
    
};


