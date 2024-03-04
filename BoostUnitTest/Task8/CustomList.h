#include <iostream>
#include <list>
#include <mutex>

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
