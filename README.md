# TCP Server and Bloom Filter Integration

## Table of Contents
- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Enhanced URL Security Features](#enhanced-url-security-features)
- [Prerequisites](#prerequisites)
- [Overview of Integration](#overview-of-integration)
- [Key Features](#key-features)
- [Setup and Configuration](#setup-and-configuration)

## Introduction
This repository includes the integration of a TCP server with a Bloom filter, aimed at enhancing the security of a web application by efficiently checking URLs for potential threats. This guide will walk you through the steps required to compile and run the Bloom Filter component and the TCP Server using Docker, ensuring seamless operation with our Node.js server and web client.

## Getting Started
Follow these instructions to get a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

Before you begin, ensure you have Docker installed on your system. If Docker is not installed, follow the installation instructions for your operating system on the [Docker Official Website](https://docs.docker.com/get-docker/).

### Installation

Clone the repository to your local machine:

```bash
git clone https://github.com/TomerBeren/FooBook-TCP-Server-Public
cd FooBook-TCP-Server-Public
```
### Launching the Dockerized TCP Server

To deploy the TCP server using Docker, follow these steps:

1. **Pull the Docker Image** Ensure Docker is installed on your system. You can download it from [Docker Hub](https://hub.docker.com/). Then, pull the Docker image using the following command:
   ```bash
   docker pull tomerberen/advancedsysprogproject:v1.0.3
   ```

2. **Run the Docker Container** Run the Docker container, ensuring that the TCP server is properly mapped to the correct ports on your local machine:
    ```bash
    docker run -i -t -p 5542:5542 tomerberen/advancedsysprogproject:v1.0.3
    ```
    This command starts the TCP server and binds it to port 5542 on your localhost, allowing the Node.js server to communicate with it.
   
### Alternative Method
If the Docker build fails, you can use the provided Makefile as an alternative method:

```bash
make
./my_program
```

## Overview of Integration
The TCP server is designed to utilize a Bloom filter to efficiently check URLs for potential security threats. This setup is aimed at improving the security measures of our web application.

## Key Features
- **Bloom Filter Integration**: Incorporates the Bloom filter to check URLs.
- **TCP Server**:  Facilitates communication between the Node.js server and the web client, ensuring that URL checks are performed swiftly and accurately.
- **Security Enhancement**:  Improves the overall security of the web platform by filtering out potentially harmful URLs before they reach the user.

## Setup and Configuration
For complete setup and configuration instructions, please refer to the project [Wiki](https://github.com/TomerBeren/FooBook-Server-Public/tree/tcp-server-main/wiki).

By following these steps, you should be able to compile and run both the Bloom Filter component and the TCP Server integration successfully. If you encounter any issues, please refer to the repository's documentation or reach out for support.

