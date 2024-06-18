# Compiler and compiler flags
CC = g++
CFLAGS = -Wall -Wextra -ggdb -std=c++17 -I ./include

# Linker flags (libraries)
LDFLAGS = -lm -l GLFW -l GLEW -framework OpenGL

# Source and object directories
SRC_DIR = src
OBJ_DIR = obj

# Find all source files in the src directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Generate object files from the source files
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Main source file
MAIN_SRC = main.cpp
MAIN_OBJ = $(OBJ_DIR)/main.o

# Output executable
EXEC = program

# Default target
all: $(EXEC)

# Linking the executable
$(EXEC): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compiling main.c
$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Compiling all source files in the src directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Rebuild everything
rebuild: clean all

# Ensure the object directory exists before compiling
$(OBJS) $(MAIN_OBJ): | $(OBJ_DIR)

.PHONY: all clean rebuild
