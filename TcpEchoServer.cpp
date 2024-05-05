#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <thread>

using namespace std;

void handleClient(int client_sock) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            cout << "Connection closed by client" << endl;
            break;
        } else if (read_bytes < 0) {
            perror("error receiving data");
            break;
        }
        cout << "Received: " << buffer << endl;

        int sent_bytes = send(client_sock, buffer, read_bytes, 0);
        if (sent_bytes < 0) {
            perror("error sending data");
            break;
        }
    }
    close(client_sock);
}

int main() {
    const int server_port = 5556;
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

    cout << "Server listening on port " << server_port << endl;

    while (true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
            continue;
        }

        cout << "New connection accepted" << endl;

        // Start a new thread to handle this client
        thread client_thread(handleClient, client_sock);
        client_thread.detach(); // Detach the thread to allow it to run independently
    }

    close(sock);
    return 0;
}
