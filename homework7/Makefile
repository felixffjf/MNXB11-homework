# Compiler and flags
CXX := g++
CXXWARNINGS := -Wall -Wextra -Werror
CXXOPT := -O3
CXXSTD := -std=c++17

# Project directories
BUILD_DIR := build
SRC_DIR := src
EXTERNAL_INCLUDE_DIR := external/include

# Include directories
INCLUDES := -I $(EXTERNAL_INCLUDE_DIR) 

# CXXFLAGS includes compiler warnings, standard, optimization, and includes
CXXFLAGS := $(CXXWARNINGS) $(CXXSTD) $(CXXOPT) $(INCLUDES)

# LDFLAGS includes ROOT libraries (glibs)
LDFLAGS := $(ROOTLIBS)

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cxx) main.cxx
OBJS := $(patsubst %.cxx,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))

# Phony targets
.PHONY: all clean

# Build the executable
all: $(BUILD_DIR) $(BUILD_DIR)/main

# Ensure the build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link the final executable
$(BUILD_DIR)/main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile each source file into an object file in the build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cxx | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile main.cxx directly into the build directory
$(BUILD_DIR)/main.o: main.cxx | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/main

