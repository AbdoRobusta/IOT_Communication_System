# Part 2 Makefile: Multicast UDP Socket Application

# Compiler
CC = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Executable names
SERVER_EXEC = ./Server/Server
CLIENT1_EXEC = ./Cliant_1/Cliant1
CLIENT2_EXEC = ./Cliant_2/Cliant2

# Source files
SERVER_SRC = ./Server/Server.cpp
CLIENT1_SRC = ./Cliant_1/Cliant_1.cpp 
CLIENT2_SRC = ./Cliant_2/Cliant_2.cpp

# Targets
all: $(SERVER_EXEC) $(CLIENT1_EXEC) $(CLIENT2_EXEC)

# Compile multicast server
$(SERVER_EXEC): $(SERVER_SRC)
	$(CC) $(CXXFLAGS) -o $(SERVER_EXEC) $(SERVER_SRC)

# Compile Client 1
$(CLIENT1_EXEC): $(CLIENT1_SRC)
	$(CC) $(CXXFLAGS) -o $(CLIENT1_EXEC) ./Cliant_1/Cliant_1.cpp

# Compile Client 2
$(CLIENT2_EXEC): $(CLIENT2_SRC)
	$(CC) $(CXXFLAGS) -o $(CLIENT2_EXEC) ./Cliant_2/Cliant_2.cpp

# Clean up build files
clean:
	rm -f $(SERVER_EXEC) $(CLIENT1_EXEC) $(CLIENT2_EXEC)
