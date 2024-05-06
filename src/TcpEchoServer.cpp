#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <thread>
#include "CommandInitializer.hpp"
#include "InputValidator.hpp"
#include "FalsePositiveChecker.hpp"
#include "ConsoleMenu.hpp"

// Global command initializer and App instance
static CommandInitializer initializer;
static IMenu *menu = new ConsoleMenu();
static App myApp(menu, initializer.commands);

void handleClient(int client_sock) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
   
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            std::cout << "Connection closed by client" << std::endl;
            break;
        } else if (read_bytes < 0) {
            perror("error receiving data");
            break;
        }
        std::cout << "Received: " << buffer << std::endl;
        // Prepare input and output streams for command processing
        std::string input(buffer);
        std::stringstream output_stream;

        myApp.run(input, output_stream);

        // Prepare the response to the client
        std::string response = output_stream.str();
        if (response.empty()) {
            response = " ";
        }

        // Send response back to client
        send(client_sock, response.c_str(), response.length(), 0);
    }
    close(client_sock);
}

int main() {
    if(initializer.commands.empty()){
        std::cout << "yes" << std::endl;
    }
    
    const int server_port = 5541;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return 1;
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        return 1;
    }

    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        return 1;
    }

    std::cout << "Server listening on port " << server_port << std::endl;

    while (true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
            continue;
        }

        std::cout << "New connection accepted" << std::endl;

        // Start a new thread to handle this client
        std::thread client_thread(handleClient, client_sock);
        client_thread.detach(); // Detach the thread to allow it to run independently
    }

    close(sock);
    return 0;
}