# Base image to use GCC
FROM gcc:latest

# Set the working directory inside the Docker container
WORKDIR /usr/src/advancedprogproject

# Install any necessary dependencies and clean up
RUN apt-get update && apt-get install -y cmake make && rm -rf /var/lib/apt/lists/*

# Expose the necessary port
EXPOSE 5542

# Copy only C++ source and header files into the Docker image
COPY src/ ./src/
COPY include/ ./include/

# Compile the C++ program
RUN g++ -std=c++11 -Wall -Iinclude src/*.cpp -o my_program

# Run the program by default when the container starts
CMD ["./my_program"]
