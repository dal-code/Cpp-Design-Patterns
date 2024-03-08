#include <iostream>
#include <unordered_map>

// 抽象享元类
class Flyweight {
public:
    virtual void operation(const std::string& extrinsicState) const = 0;
};

// 具体享元类
class ConcreteFlyweight : public Flyweight {
public:
    ConcreteFlyweight(const std::string& intrinsicState) : intrinsicState_(intrinsicState) {}

    void operation(const std::string& extrinsicState) const override {
        std::cout << "ConcreteFlyweight with intrinsic state: " << intrinsicState_
                  << " and extrinsic state: " << extrinsicState << std::endl;
    }

private:
    std::string intrinsicState_;
};

// 不需要共享的具体享元子类
class UnsharedConcreteFlyweight : public Flyweight {
public:
    UnsharedConcreteFlyweight(const std::string& intrinsicState) : intrinsicState_(intrinsicState) {}

    void operation(const std::string& extrinsicState) const override {
        std::cout << "UnsharedConcreteFlyweight with intrinsic state: " << intrinsicState_
                  << " and extrinsic state: " << extrinsicState << std::endl;
    }

private:
    std::string intrinsicState_;
};

// 享元工厂类
class FlyweightFactory {
public:
    Flyweight* getFlyweight(const std::string& intrinsicState, bool shared) {
        if (shared) {
            if (flyweights_.find(intrinsicState) == flyweights_.end()) {
                flyweights_[intrinsicState] = new ConcreteFlyweight(intrinsicState);
                ++sharedCount_;
            }
            return flyweights_[intrinsicState];
        } else {
            ++unsharedCount_;
            return new UnsharedConcreteFlyweight(intrinsicState);
        }
    }

    int getSharedCount() const {
        return sharedCount_;
    }

    int getUnsharedCount() const {
        return unsharedCount_;
    }

    ~FlyweightFactory() {
        for (auto& pair : flyweights_) {
            delete pair.second;
        }
        flyweights_.clear();
    }

private:
    std::unordered_map<std::string, Flyweight*> flyweights_;
    int sharedCount_{0};
    int unsharedCount_{0};
};

int main() {
    // 创建享元工厂对象
    FlyweightFactory factory;

    // 获取共享享元对象,flyweight是基类，这里获得的是具体的享元对象
    Flyweight* flyweight1 = factory.getFlyweight("shared_state", true);
    Flyweight* flyweight2 = factory.getFlyweight("shared_state", true);
    Flyweight* flyweight3 = factory.getFlyweight("shared_state3", true);

    // 调用共享享元对象的操作方法，并传入外部状态
    flyweight1->operation("external_state1");
    flyweight2->operation("external_state2");
    flyweight3->operation("external_state3");

    // 获取不需要共享的享元对象
    Flyweight* unsharedFlyweight = factory.getFlyweight("unshared_state", false);

    // 调用不需要共享的享元对象的操作方法，并传入外部状态
    unsharedFlyweight->operation("external_state4");

    // 输出对象实例数量
    std::cout << "Shared flyweights count: " << factory.getSharedCount() << std::endl;
    std::cout << "Unshared flyweights count: " << factory.getUnsharedCount() << std::endl;

    // 释放不需要共享的享元对象
    delete unsharedFlyweight;

    return 0;
}