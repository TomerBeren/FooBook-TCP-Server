# Makefile for your C++ project

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
TARGET = my_program

# List of source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# List of object files
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Dependency files
DEPS = $(OBJECTS:.o=.d)

# Default target
all: $(TARGET)

# Build the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for creating object files from source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -MMD -MP -c $< -o $@

# Include dependency files
-include $(DEPS)

# Clean up
clean:
	rm -f $(BUILD_DIR)/.o $(BUILD_DIR)/.d $(TARGET)

# PHONY targets (targets that don't correspond to actual files)
.PHONY: all clean

# Prevent Make from treating dependencies as targets
.PRECIOUS: $(BUILD_DIR)/%.d

# Compiler-generated dependency files
%.d: ;
.PRECIOUS: %.d

# Ensure that the build directory exists
$(shell mkdir -p $(BUILD_DIR))