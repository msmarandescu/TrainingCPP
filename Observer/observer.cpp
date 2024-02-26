#include <iostream>
#include <string>
#include <boost/signals2.hpp>
using namespace boost;
using namespace boost::signals2;


template <typename T> struct Observable
{
    signal<void(T&, const std::string&)> field_changed;
};


class Person : public Observable<Person>
{
    std::string name = "";
    int age = 0;
public:
    void setName(std::string name) { 
        if(this->name == name) { return; }
        this->name = name; 
        this->field_changed(*this, "Name");
    }
    void setAge(int age) { 
        if(this->age == age) { return; }
        this->age = age; 
        this->field_changed(*this, "Age");
    }
    std::string getName() { return this->name; }
    int getAge(){ return this->age; }
};


int main()
{
    Person p;
    auto conn = p.field_changed.connect(
        [](Person& p, const std::string& field_name )
        {
            std::cout << field_name << " has changed!" << std::endl;
        }
    );
    p.setName("Marius");
    p.setAge(33);

    conn.disconnect();

    return 0;
}