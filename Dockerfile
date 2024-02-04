# Using the GCC image as the base
FROM gcc:latest

# Seting the working directory inside the Docker container
WORKDIR /usr/src/advancedsysprogproject

# Installing any necessary dependencies
RUN apt-get update && rm -rf /var/lib/apt/lists/*

# Coping source and header files into the Docker image
COPY src/*.cpp ./src/
COPY include/*.hpp ./include/

# Compilig the C++ program
# -I flag adds the include directory to the header search paths
# -o specifies the output file name
RUN g++ -std=c++11 -Wall -Iinclude src/*.cpp -o my_program

# Runing the program by default when the container starts
CMD ["./my_program"]