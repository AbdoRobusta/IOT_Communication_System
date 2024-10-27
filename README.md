# IOT_Communication_System
Using Yocto project for Raspberry-pi4 and Qemu 
## Part 1: Unicast TCP Socket Application
## Server Side (Raspberry Pi 4)
### 1. Task:
    o Create a TCP socket server that listens on a specified port for client connections.

### 2. Functionality:
    o Accept client connections from QEMU.
    o Receive messages from the client and respond with an acknowledgment + current
    temperature.
  
### 3. Sample Output:
    o Server: "Client connected from IP: [X.X.X.X]."
    o Server: "Received message: [Hello, Server!]"
    o Server: "Sending acknowledgment. Current Temperature is 39 ⁰C "

## Client Side (QEMU)
### 1. Task:
    Create a TCP socket client that connects to the server on Raspberry Pi 4.

### 2. Functionality:
    o Connect to the server.
    o Send a message and receive a response.

### 3. Sample Output:
    o Client: "Connected to Server."
    o Client: "Sending message: [Hello, Server!]"
    o Client: "Received acknowledgment: [Message received.]"

## Part 2: Multicast UDP Socket Application
## Server Side (Raspberry Pi 4)
### 1. Task:
    Create a UDP multicast server that sends data to multiple clients.
### 2. Functionality:
    o Broadcast data to clients using multicast UDP.
    o Server can send periodic updates to all connected clients.
### 3. Sample Output:
    o Server: "Sending multicast message: [System update at 10:00 AM]."
## Client 1 and Client 2 (QEMU)
### 1. Task:
    Create two separate UDP clients on QEMU that listen to multicast messages.
### 2. Functionality:
    o Each client listens for multicast messages and displays them.
### 3. Sample Output (Client 1 & Client 2):
    o Client X: "Received multicast message: [System update at 10:00 AM]."