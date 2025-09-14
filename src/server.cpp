//
// Created by Uchechukwu Emmanuel on 14/09/2025.
//
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sstream>

int main(int argc, char **argv) {
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    std::cerr << "Failed to create server socket\n";
    return 1;
  }

  int reuse = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
    std::cerr << "setsockopt failed\n";
    return 1;
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(4221);

  if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) != 0) {
    std::cerr << "Failed to bind to port 4221\n";
    return 1;
  }

  if (listen(server_fd, 5) != 0) {
    std::cerr << "listen failed\n";
    return 1;
  }

  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);

  std::cout << "Waiting for a client to connect...\n";

  while (true) {
    int client_sock = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_len);
    if (client_sock < 0) {
      std::cerr << "accept failed\n";
      return 1;
    }
    std::cout << "Client connected\n";

    // Read request from client
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    ssize_t bytes_received = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
      std::cerr << "recv failed\n";
      close(client_sock);
      close(server_fd);
      return 1;
    }

    std::string request(buffer);
    std::cout << "Received request:\n" << request << "\n";

    // Extract the first line (request line)
    size_t pos = request.find("\r\n");
    std::string request_line = request.substr(0, pos);
    std::cout << "Request line: " << request_line << "\n";

    // Parse method, path, and version
    std::string method, path, version;
    {
      std::istringstream iss(request_line);
      iss >> method >> path >> version;
    }

    std::cout << "Method: " << method << ", Path: " << path << ", Version: " << version << "\n";


    // Step 4: Send response
    if (path == "/") {
      send(client_sock, "HTTP/1.1 200 OK\r\n\r\n", 19, 0);
    } else {
      send(client_sock, "HTTP/1.1 404 Not Found\r\n\r\n", 26, 0);
    }

    close(client_sock);
  }
  close(server_fd);

  return 0;
}