#include "Prototype.hpp"

// ConcretePrototypeA

ConcretePrototypeA::ConcretePrototypeA() : info(nullptr) {}

ConcretePrototypeA::ConcretePrototypeA(const ConcretePrototypeA& other) {
    if (other.info != nullptr) {
        this->info = new std::string(*other.info);
    } else {
        this->info = nullptr;
    }
}

ConcretePrototypeA::~ConcretePrototypeA() {
    delete info;
}

Prototype* ConcretePrototypeA::clone() {
    return new ConcretePrototypeA(*this);
}

void ConcretePrototypeA::setInfo(const std::string& info) {
    if (this->info == nullptr) {
        this->info = new std::string;
    }
    *this->info = info;
}

void ConcretePrototypeA::printInfo() const {
    if (info != nullptr) {
        std::cout << "ConcretePrototypeA Info: " << *info << std::endl;
    } else {
        std::cout << "ConcretePrototypeA Info: (empty)" << std::endl;
    }
}

// ConcretePrototypeB

ConcretePrototypeB::ConcretePrototypeB() : info(nullptr) {}

ConcretePrototypeB::ConcretePrototypeB(const ConcretePrototypeB& other) {
    if (other.info != nullptr) {
        this->info = new std::string(*other.info);
    } else {
        this->info = nullptr;
    }
}

ConcretePrototypeB::~ConcretePrototypeB() {
    delete info;
}

Prototype* ConcretePrototypeB::clone() {
    return new ConcretePrototypeB(*this);
}

void ConcretePrototypeB::setInfo(const std::string& info) {
    if (this->info == nullptr) {
        this->info = new std::string;
    }
    *this->info = info;
}

void ConcretePrototypeB::printInfo() const {
    if (info != nullptr) {
        std::cout << "ConcretePrototypeB Info: " << *info << std::endl;
    } else {
        std::cout << "ConcretePrototypeB Info: (empty)" << std::endl;
    }
}