#include <atomic>
#include <mutex>
#include <iostream>
//C++ 11版本之后的跨平台实现 (volatile)
class Singleton {
private:
    //存储单例对象的指针
    static std::atomic<Singleton*> m_instance;
    // 互斥锁
    static std::mutex m_mutex;

    Singleton() {}

public:

    static Singleton* getInstance() {
        // 获取当前的单例对象指针
        Singleton* tmp = m_instance.load(std::memory_order_relaxed);
        //获取内存fence,确保前面的读操作在后续的逻辑中不会被重新排序
        std::atomic_thread_fence(std::memory_order_acquire);
        if (tmp == nullptr) {
            std::lock_guard<std::mutex> lock(m_mutex);
            tmp = m_instance.load(std::memory_order_relaxed);
            if (tmp == nullptr) {
                tmp = new Singleton;
                //释放内存fence
                std::atomic_thread_fence(std::memory_order_release);
                // 将新创建的对象指针存储到 m_instance 中。
                m_instance.store(tmp, std::memory_order_relaxed);
            }
        }
        return tmp;
    }
    
    void showMessage() {
        std::cout << "Hello, I am a singleton object." << std::endl;
    }
};




