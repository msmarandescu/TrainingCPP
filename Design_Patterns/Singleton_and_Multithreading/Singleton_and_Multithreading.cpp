#include <iostream>
#include <list>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>

template <class T>
class CustomList {

private:
    std::list<T> _list;
    std::mutex _mtx;
    CustomList(){};

public:
    CustomList(CustomList const&) = delete;
    void operator=(CustomList const&) = delete;

    static CustomList<T>& getInstance() {
        static CustomList<T> instance;
        return instance;
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
        for (auto i : _list) {
            std::cout << i << ",";
        }
        std::cout << std::endl;
    }

    int getSize() {
        std::lock_guard<std::mutex> lock(_mtx);
        auto ret = _list.size();
        return ret;
    }
};

#define listInt CustomList<int>::getInstance()

int main() {
    std::atomic<bool> running(true);
    srand(time(NULL));

    std::thread t1([&]() { /*insert values*/
        while (running) {
            int val = rand() % 10;
            listInt.insertData(val);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "Thread 1: insert data:" << val << std::endl;
        }
    });

    std::thread t2([&]() { /* process values from list*/
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        while (true) {
            if (listInt.getSize() > 0) 
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                std::cout << "                          Thread 2: data processed:" << listInt.getData() << std::endl;
            } 
            else 
            {
                break;
            }
        }
    });

    std::thread t3([&]() { /*timmer*/
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        running = false;
        std::cout << "Thread 3 stop" << std::endl;
    });

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Exit main thread!" << std::endl;
    return 0;
}
