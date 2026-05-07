# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall

# Executable name
TARGET = mtg-lifetracker

# Source file
SRC = mtg-lifetracker.cpp

# Default target
all: $(TARGET)

# Build executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Run program
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -f $(TARGET)

# Build Docker image
docker-build:
	docker build -t mtg-lifetracker .

# Run Docker container
docker-run:
	docker run -it --rm mtg-lifetracker