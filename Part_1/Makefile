# Part 1 Makefile: Unicast TCP Socket Application

# Compiler
CC = g++

# Compiler flags
CCFLAGS = -Wall -std=c++11

# Executable names
SERVER_EXEC = ./Server/Server
CLIENT_EXEC = ./Client/Client

# Source files
SERVER_SRC = ./Server/Server.cpp ./TCP_Socket/TCP_Server.h
CLIENT_SRC = ./Client/Client.cpp ./TCP_Socket/TCP.h

# Targets
all: $(SERVER_EXEC) $(CLIENT_EXEC)

# Compile server
$(SERVER_EXEC): $(SERVER_SRC)
	$(CC) $(CXXFLAGS) -o $(SERVER_EXEC) ./Server/Server.cpp

# Compile client
$(CLIENT_EXEC): $(CLIENT_SRC)
	$(CC) $(CXXFLAGS) -o $(CLIENT_EXEC) ./Client/Client.cpp

# Clean up build files
clean:
	rm -f $(SERVER_EXEC) $(CLIENT_EXEC)

