# IOT_Communication_System
Using Yocto project for Raspberry-pi4 and Qemu 
##Part 1: Unicast TCP Socket Application
##Server Side (Raspberry Pi 4)
#1. Task:
  o Create a TCP socket server that listens on a specified port for client connections.

#2. Functionality:
  o Accept client connections from QEMU.
  o Receive messages from the client and respond with an acknowledgment + current
    temperature.
  
#3. Sample Output:
  o Server: "Client connected from IP: [X.X.X.X]."
  o Server: "Received message: [Hello, Server!]"
  o Server: "Sending acknowledgment. Current Temperature is 39 ⁰C "

##Client Side (QEMU)
#1. Task:
  Create a TCP socket client that connects to the server on Raspberry Pi 4.

#2. Functionality:
  o Connect to the server.
  o Send a message and receive a response.

#3. Sample Output:
  o Client: "Connected to Server."
  o Client: "Sending message: [Hello, Server!]"
  o Client: "Received acknowledgment: [Message received.]"
