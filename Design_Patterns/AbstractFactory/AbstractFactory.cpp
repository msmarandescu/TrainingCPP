#include <iostream>
#include <memory>

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
    void START_ENGINE() override { std::cout << "Aircraft Engine Started" << std::endl; }
    void GET_READY() override { std::cout << "Aircraft is ready for operation" << std::endl; }
};

class Drone : public Vehicle
{
public:
    void START_ENGINE() override { std::cout << "Drone Engine Started" << std::endl; }
    void GET_READY() override { std::cout << "Drone is ready for operation" << std::endl; }
};

class Car : public Vehicle
{
public:
    void START_ENGINE() override { std::cout << "Car Engine Started" << std::endl; }
    void GET_READY() override { std::cout << "Car is ready for operation" << std::endl; }
};

class Truck : public Vehicle
{
public:
    void START_ENGINE() override { std::cout << "Truck Engine Started" << std::endl; }
    void GET_READY() override { std::cout << "Truck is ready for operation" << std::endl; }
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

    VehicleFactory<Drone> droneFactory;
    Vehicle *drone = droneFactory.create_vehicle();
    drone->START_ENGINE();
    drone->GET_READY();

    VehicleFactory<Car> carFactory;
    Vehicle *car = carFactory.create_vehicle();
    car->START_ENGINE();
    car->GET_READY();

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
