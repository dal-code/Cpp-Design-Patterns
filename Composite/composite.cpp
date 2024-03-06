#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// 抽象组件类
class Component {
public:
    virtual void operation() const = 0;
    virtual void add(Component* component) {}
    virtual void remove(Component* component) {}
    virtual Component* getChild(int index) const {
        return nullptr;
    }
};

// 叶子组件类
class Leaf : public Component {
public:
    explicit Leaf(const std::string& name) : name_(name) {}

    void operation() const override {
        std::cout << "Leaf: " << name_ << " operation." << std::endl;
    }

private:
    std::string name_;
};

// 复合组件类
class Composite : public Component {
public:
    void operation() const override {
        std::cout << "Composite operation:" << std::endl;
        for (const auto& component : components_) {
            component->operation();
        }
    }

    void add(Component* component) override {
        components_.push_back(component);
    }

    void remove(Component* component) override {
        auto it = std::find(components_.begin(), components_.end(), component);
        if (it != components_.end()) {
            components_.erase(it);
        }
    }

    Component* getChild(int index) const override {
        if (index >= 0 && index < components_.size()) {
            return components_[index];
        }
        return nullptr;
    }

private:
    std::vector<Component*> components_;
};

int main() {
    // 创建叶子节点
    Component* leaf1 = new Leaf("Leaf 1");
    Component* leaf2 = new Leaf("Leaf 2");
    Component* leaf3 = new Leaf("Leaf 3");

    // 创建复合节点
    Composite* composite1 = new Composite();
    Composite* composite2 = new Composite();

    // 组合构造树形结构
    composite1->add(leaf1);
    composite1->add(leaf2);
    composite2->add(leaf3);
    composite1->add(composite2);

    // 调用操作方法
    composite1->operation();

    // 释放资源
    delete composite1;

    return 0;
}