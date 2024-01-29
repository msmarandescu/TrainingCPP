#include <iostream>
#include <list>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>

template <class T>
class CustomList {

private:
    static CustomList<T>* _instance;
    std::list<T> _list;
    std::mutex _mtx;

public:
    static CustomList<T>* getInstance() {
        if (_instance == NULL) {
            _instance = new CustomList<T>();
        }
        return _instance;
    }

    void insertData(T val) {
        std::lock_guard<std::mutex> lock(_mtx);
        _list.push_back(val);
    }

    T getData() {
        T ret;
        {
            std::lock_guard<std::mutex> lock(_mtx);
            if (!_list.empty()) {
                ret = _list.front();
                _list.pop_front();
            }
        }
        return ret;
    }

    void display() {
        std::lock_guard<std::mutex> lock(_mtx);
        std::cout << "List: ";
        for (auto i = _list.begin(); i != _list.end(); i++) {
            std::cout << *i << ",";
        }
        std::cout << std::endl;
    }

    int getSize() {
        std::lock_guard<std::mutex> lock(_mtx);
        auto ret = _list.size();
        return ret;
    }
};

template <class T> CustomList<T>* CustomList<T>::_instance;
CustomList<int>* dataInstance = CustomList<int>::getInstance();

int main() {
    std::atomic<bool> running(true);
    srand(time(NULL));

    std::thread t1([&]() { /*insert values*/
        while (running) {
            int val = rand() % 10;
            dataInstance->insertData(val);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "Thread 1: insert data:" << val << std::endl;
        }
    });

    std::thread t2([&]() { /* process values from list*/
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        while (true) {
            if (dataInstance->getSize() > 0) 
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                std::cout << "                          Thread 2: data processed:" << dataInstance->getData() << std::endl;
            } 
            else 
            {
                break;
            }
        }
    });

    std::thread t3([&]() { /*timmer*/
        int t = 10;
        while (t != 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            t--;
        }
        running = false;
        std::cout << "Thread 3 stop" << std::endl;
    });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
