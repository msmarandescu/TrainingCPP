#include <iostream>
#include <memory>
using namespace std;

class Vehicle
{
public:
    virtual ~Vehicle() {}  // Provide a virtual destructor definition
    virtual void START_ENGINE() = 0;
    virtual void GET_READY() = 0;
};

class Aircraft : public Vehicle
{
public:
    void START_ENGINE() override { cout << "Aircraft Engine Started" << endl; }
    void GET_READY() override { cout << "Aircraft is ready for operation" << endl; }
};

class Drone : public Vehicle
{
public:
    void START_ENGINE() override { cout << "Drone Engine Started" << endl; }
    void GET_READY() override { cout << "Drone is ready for operation" << endl; }
};

class Car : public Vehicle
{
public:
    void START_ENGINE() override { cout << "Car Engine Started" << endl; }
    void GET_READY() override { cout << "Car is ready for operation" << endl; }
};

class Truck : public Vehicle
{
public:
    void START_ENGINE() override { cout << "Truck Engine Started" << endl; }
    void GET_READY() override { cout << "Truck is ready for operation" << endl; }
};


template <typename Type>
class VehicleFactory : public Vehicle
{
public:
    static Vehicle *create_vehicle()
    {
        return new Type;
    }

    void START_ENGINE() override {}
    void GET_READY() override {}
};

int main()
{
    VehicleFactory<Aircraft> aircraftFactory;
    Vehicle *aircraft = aircraftFactory.create_vehicle();
    aircraft->START_ENGINE();
    aircraft->GET_READY();

    cout << endl;

    VehicleFactory<Drone> droneFactory;
    Vehicle *drone = droneFactory.create_vehicle();
    drone->START_ENGINE();
    drone->GET_READY();

    cout << endl;

    VehicleFactory<Car> carFactory;
    Vehicle *car = carFactory.create_vehicle();
    car->START_ENGINE();
    car->GET_READY();
    
    cout << endl;

    VehicleFactory<Truck> truckFactory;
    Vehicle *truck = truckFactory.create_vehicle();
    truck->START_ENGINE();
    truck->GET_READY();

    delete aircraft;
    delete drone;
    delete car;
    delete truck;

    return 0;
}