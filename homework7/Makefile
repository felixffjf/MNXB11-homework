# Define the compiler and flags
CXX = g++
CXXFLAGS = -I./external/include -std=c++11 -Werror -Wall -Wextra

# Define directories
SRC_DIR = src
BUILD_DIR = build
EXTERNAL_DIR = external
LIB_DIR = $(EXTERNAL_DIR)/lib
INCLUDE_DIR = $(EXTERNAL_DIR)/include

# Define source files and the target executable
SRC_FILES = $(wildcard $(SRC_DIR)/*.cxx)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cxx=$(BUILD_DIR)/%.o)
TARGET = main

# Default rule
all: $(TARGET)

# Rule for creating the target executable
$(TARGET): $(OBJ_FILES)
$(CXX) -o $@ $^ -L$(LIB_DIR) -lcli11

# Rule for object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cxx
@mkdir -p $(BUILD_DIR)
$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
rm -rf $(BUILD_DIR)/*.o $(TARGET)

# Phony targets
.PHONY: all clean