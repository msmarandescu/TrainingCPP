#include <iostream>
#include <fstream>
#include <thread>
#include <future>
#include <chrono>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
using namespace boost::interprocess;

// structura pentru datele partajate:
struct SharedData {
    char message[256];
};

void Client(shared_memory_object& shm, std::mutex& mtx) {
    std::ofstream file("client.txt", std::ios::out | std::ios::app);
    if (!file.is_open()) {
        std::cout << "Eroare: Nu s-a putut deschide server.txt pentru scriere!" << std::endl;
        return;
    }
    mapped_region region(shm, read_write);
    {
        std::lock_guard<std::mutex> lock(mtx);
        SharedData* data = static_cast<SharedData*>(region.get_address());
        std::cout << "Client:Mesaj primit: " << data->message << std::endl;
        file << "Mesaj primit: " << data->message << std::endl;
    }
}

void Server(shared_memory_object& shm, std::mutex& mtx) {
    std::ofstream file("server.txt", std::ios::out | std::ios::app);
    if (!file.is_open()) {
        std::cout << "Eroare: Nu s-a putut deschide client.txt pentru scriere!" << std::endl;
        return;
    }

    // alocarea și mapparea regiunii de memorie partajată
    mapped_region region(shm, read_write);
    {
        std::lock_guard<std::mutex> lock(mtx);
        SharedData* data = static_cast<SharedData*>(region.get_address());
        std::strcpy(data->message, "Hello from server!");
        std::cout << "Server:Mesaj trimis: " << data->message << std::endl;
        file << "Mesaj trimis: " << data->message << std::endl;
    }
}

int main() {
    // Numele memoriei partajate și al mutex-ului
    const char* shared_memory_name = "shared_memory";
    const char* mutex_name = "mutex";

    // Creăm memoria partajată și mutex-ul
    shared_memory_object shm(open_or_create, shared_memory_name, read_write);
    shm.truncate(sizeof(SharedData));
    std::mutex mtx;

    std::future<void> serverTask = std::async(std::launch::async, Server, std::ref(shm), std::ref(mtx));
    std::future<void> clientTask = std::async(std::launch::async, Client, std::ref(shm), std::ref(mtx));

    serverTask.get();
    clientTask.get();

    // Eliberăm resursele
    shared_memory_object::remove(shared_memory_name);
    named_mutex::remove(mutex_name);

    return 0;
}
