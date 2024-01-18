#include <iostream>
#include <list>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
using namespace std;

template <class T>
class CustomList {

private:
    static CustomList<T>* _instance;
    list<T> _list;
    mutex _mtx;

public:
    static CustomList<T>* getInstance() {
        if (_instance == NULL) {
            _instance = new CustomList<T>();
        }
        return _instance;
    }

    void insertData(T val) {
        lock_guard<mutex> lock(_mtx);
        _list.push_back(val);
    }

    T getData() {
        T ret;
        {
            lock_guard<mutex> lock(_mtx);
            if (!_list.empty()) {
                ret = _list.front();
                _list.pop_front();
            }
        }
        return ret;
    }

    void display() {
        lock_guard<mutex> lock(_mtx);
        cout << "List: ";
        for (auto i = _list.begin(); i != _list.end(); i++) {
            cout << *i << ",";
        }
        cout << endl;
    }

    int getSize() {
        lock_guard<mutex> lock(_mtx);
        auto ret = _list.size();
        return ret;
    }
};

template <class T> CustomList<T>* CustomList<T>::_instance;
CustomList<int>* dataInstance = CustomList<int>::getInstance();

int main() {
    atomic<bool> running(true);
    srand(time(NULL));

    thread t1([&]() { /*insert values*/
        while (running) {
            int val = rand() % 10;
            dataInstance->insertData(val);
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << "Thread 1: insert data:" << val << endl;
        }
    });

    thread t2([&]() { /* process values from list*/
        this_thread::sleep_for(chrono::milliseconds(200));
        while (true) {
            if (dataInstance->getSize() > 0) 
            {
                this_thread::sleep_for(chrono::milliseconds(100));
                cout << "                          Thread 2: data processed:" << dataInstance->getData() << endl;
            } 
            else 
            {
                break;
            }
        }
    });

    thread t3([&]() { /*timmer*/
        int t = 10;
        while (t != 0) {
            this_thread::sleep_for(chrono::milliseconds(100));
            t--;
        }
        running = false;
        cout << "Thread 3 stop" << endl;
    });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}