# Use official GCC image
FROM gcc:14

# Set working directory
WORKDIR /app

# Copy source code into container
COPY mtg-lifetracker.cpp .

# Compile the program
RUN g++ -std=c++17 -o mtg-lifetracker mtg-lifetracker.cpp

# Run the executable
CMD ["./mtg-lifetracker"]