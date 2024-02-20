#include <iostream>
#include <cstring>
#include <future>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fstream>

class SocketCommunication
{
private:
    std::mutex _mtx;
    SocketCommunication(){}
public:
    SocketCommunication(SocketCommunication const&) = delete;
    void operator=(SocketCommunication const&) = delete;

    static SocketCommunication& getInstance()
    {
        static SocketCommunication instance;
        return instance;
    }

    int createSocket() {
        int sockfd;
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
            std::cout << "Socket creation error" << std::endl;
            exit(EXIT_FAILURE);
        }
        return sockfd;
    }   

    void bindSocket(int sockfd, int port) {
        struct sockaddr_in address;
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(port);

        // Setarea opțiunii SO_REUSEADDR (cad rulez aplicatia imediat dupa ce a fost inchisa, portul este încă rezervat de procesul anterior)
        int opt = 1;
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
            std::cout << "Setsockopt failed" << std::endl;
            exit(EXIT_FAILURE);
        }

        if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
            std::cout << "Bind failed" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void listenSocket(int sockfd, int backlog) {
        if (listen(sockfd, backlog) < 0) {
            std::cout << "Listen failed" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    int acceptConnection(int sockfd) {
        int new_socket;
        struct sockaddr_in address;
        int addrlen = sizeof(address);
        if ((new_socket = accept(sockfd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            std::cout << "Acceptance failed" << std::endl;
            exit(EXIT_FAILURE);
        }
        return new_socket;
    }

    void sendData(int sockfd, const std::string& data) {
        send(sockfd, data.c_str(), data.length(), 0);
    }

    std::string receiveData(int sockfd) {
        char buffer[1024] = {0};
        int valread = read(sockfd, buffer, 1024);
        return std::string(buffer);
    }

    std::string getCurrentDateTime() {
        time_t now = time(0);
        struct tm* localTime = localtime(&now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
        return std::string(buffer);
    }

    void saveToLog(std::string fileName, std::string mes)
    {
        std::lock_guard<std::mutex> lock(_mtx);
        std::ofstream os(fileName, std::ios::app); //open in append mode
        if(!os.is_open())
        {
            std::cout << "Eroare la deschiderea fisierului: " << fileName << std::endl;
            return;
        }
        os << getCurrentDateTime() + ":" + mes;
        os.close();
    }
};

#define socketInstance SocketCommunication::getInstance()

void server(const std::string& ipAddress, int port, const std::string& logFileName)
{
    int serverSocket = socketInstance.createSocket();
    socketInstance.bindSocket(serverSocket, port);
    socketInstance.listenSocket(serverSocket, 3);

    socketInstance.saveToLog(logFileName, "Server started! Waiting for client request...\n");

    int clientSocket = socketInstance.acceptConnection(serverSocket);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::string clientMessage = socketInstance.receiveData(clientSocket);
    socketInstance.saveToLog(logFileName, "Server received message from client: " + clientMessage + "\n");

    if (clientMessage == "what's the date?") {
        std::string dateResponse = socketInstance.getCurrentDateTime();
        socketInstance.sendData(clientSocket, dateResponse);
        socketInstance.saveToLog(logFileName, "Server sent response to client: " + dateResponse + "\n");
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));

    close(clientSocket);
    close(serverSocket);
    socketInstance.saveToLog(logFileName, "Server closing!\n");
}

void client(const std::string& ipAddress, int port, const std::string& logFileName)
{
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Delay for synchronization

    int clientSocket = socketInstance.createSocket();

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, ipAddress.c_str(), &serv_addr.sin_addr) <= 0) {
        std::cout << "Invalid address/ Address not supported" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (connect(clientSocket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Connection Failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string message = "what's the date?";
    socketInstance.sendData(clientSocket, message);
    socketInstance.saveToLog(logFileName, "Client writes to server: " + message + "\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::string serverResponse = socketInstance.receiveData(clientSocket);
    socketInstance.saveToLog(logFileName, "Client received response from server: " + serverResponse + "\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));

    close(clientSocket);
    socketInstance.saveToLog(logFileName, "Client closing!\n");
}

int main() {
    std::string ipAddress = "127.0.0.1";
    int port = 9080;
    std::string serverLogFileName = "serverLogFile.log";
    std::string clientLogFileName = "clientLogFile.log";

    std::future<void> serverTask = std::async(std::launch::async , server, ipAddress, port, serverLogFileName);
    std::future<void> clientTask = std::async(std::launch::async , client, ipAddress, port, clientLogFileName);

    serverTask.get();
    clientTask.get();

    return 0;
}
