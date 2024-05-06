#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main() {
    const char *ip_address = "127.0.0.1";
    const int port_no = 5541;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("Error connecting to server");
        close(sock);
        return 1;
    }

    string input_command;
    char buffer[4096];

    while (true) {
        // Read the command from user input via cin
        getline(cin, input_command);

        // Check if the user wants to exit
        if (input_command == "exit") {
            break;
        }

        // Send the command to the server
        int data_len = input_command.length();
        int sent_bytes = send(sock, input_command.c_str(), data_len, 0);
        if (sent_bytes < 0) {
            perror("Error sending data");
            close(sock);
            return 1;
        }

        // Receive the response from the server
        memset(buffer, 0, sizeof(buffer));
        int read_bytes = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (read_bytes == 0) {
            cout << "Connection closed by server" << endl;
            break;
        } else if (read_bytes < 0) {
            perror("Error receiving data");
            break;    
        }else if (buffer[0] == ' '){
            continue;
        } else {
            buffer[read_bytes] = '\0';
            cout << buffer;
        }
    }

    close(sock);
    return 0;
}
