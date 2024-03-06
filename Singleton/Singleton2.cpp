#include <iostream>
#include <mutex>
class Singleton{
private:
    // 私有的构造函数，防止外部创建对象
    Singleton();
    Singleton(const Singleton& other);
public:
    Singleton& operator=(const Singleton&) = delete; // 禁用赋值运算符
    // 公有的静态成员函数，用于获取单例对象
    static Singleton* getInstance();
    static Singleton* m_instance;
    // #ifdef _GLIBCXX_HAS_GTHREADS 有问题是因为这个版本的wingw不支持thread
    static std::mutex mutex;
};

Singleton* Singleton::m_instance = nullptr;

//线程非安全版本
Singleton* Singleton::getInstance() {
    // 懒汉式单例模式，在第一次调用时创建对象
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}


//线程安全版本，但锁的代价过高
Singleton* Singleton::getInstance() {
    // 这将自动在函数结束时释放锁
    std::lock_guard<std::mutex> lock(mutex); // 加锁
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}

//双检查锁，但由于内存读写reorder不安全
Singleton* Singleton::getInstance() {
    
    if(m_instance==nullptr){
        std::lock_guard<std::mutex> lock(mutex); // 加锁
        if (m_instance == nullptr) {
            m_instance = new Singleton();
        }
    }
    return m_instance;
}
// 局部静态变量,在cpp11之后就是线程安全的了
class single{
private:
    single(){}
    ~single(){}

public:
    static single* getinstance();
};

single* single::getinstance(){
    //如果不是cpp11就对obj进行加锁
    static single obj;
    return &obj;
}


// 饿汉模式   静态非局部的实例对象初始化顺序不定
class Singleton {
private:
    static Singleton* instance;

    Singleton() {}
    ~Singleton() {}

public:
    Singleton(const Singleton&) = delete; // 禁用拷贝构造函数
    Singleton& operator=(const Singleton&) = delete; // 禁用赋值运算符

    static Singleton* getInstance() {
        return instance;
    }

    void showMessage() {
        std::cout << "Hello, I am a singleton object." << std::endl;
    }
};
// 程序运行就定义了对象，并对其初始化
Singleton* Singleton::instance = new Singleton(); // 在类外部初始化单例对象

int main() {
    Singleton* singleton = Singleton::getInstance();
    singleton->showMessage();

    return 0;
}