# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++14

# Executable name
EXECUTABLE = main

# Source files
SOURCES = main.cpp Camera.cpp Image.cpp Misc.cpp Shapes.cpp

# Default target
all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)

# Clean target
clean:
	rm -f $(EXECUTABLE)

# Phony targets
.PHONY: all clean
