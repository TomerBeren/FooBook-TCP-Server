# Advanced Programming Project: Bloom Filter Component

## Getting Started

This guide will walk you through the steps required to compile and run the Bloom Filter component of the Advanced Programming Project using Docker. Follow these instructions to get a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

Before you begin, ensure you have Docker installed on your system. If Docker is not installed, follow the installation instructions for your operating system on the [Docker Official Website](https://docs.docker.com/get-docker/).

### Installation

Clone the repository to your local machine:

```bash
git clone https://github.com/TomerBeren/FooBook-TCP-Server-Public
cd FooBook-TCP-Server-Public
```
### Build the Docker Image

Build the Docker image using the following command:

```bash
docker build -t advancedprogproject .
```
This command reads the Dockerfile in the current directory and builds an image named advancedprogproject.

### Run the Docker Container

To run the project in a Docker container, execute:

```bash
docker run -it advancedprogproject
```
### Alternative Method
If the Docker build fails, you can use the provided Makefile as an alternative method:

```bash
make
./my_program
```
By following these steps, you should be able to compile and run the Bloom Filter component of the Advanced Programming Project successfully. If you encounter any issues, please refer to the repository's documentation or reach out for support.

