# Minitalk

Minitalk is a client-server application in C that demonstrates inter-process communication using signals (`SIGUSR1` and `SIGUSR2`). The project involves a server that waits for messages from clients and sends back an acknowledgment message once a message is received.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Example](#example)

## Introduction

Minitalk implements a simple communication protocol between a server and multiple clients using signals. The server generates a Process ID (PID) and waits for messages from clients. Clients send messages to the server using the server's PID, and upon receiving a message, the server sends an acknowledgment back to the client.

## Features

- **Client-Server Architecture**: Uses two separate programs: a server and one or more clients.
- **Signal-based Communication**: Utilizes `SIGUSR1` and `SIGUSR2` signals for message transmission and acknowledgment.
- **PID-based Communication**: Clients identify the server using its PID.
- **Reliable Communication**: Includes acknowledgment mechanism to ensure reliable message delivery.

## Installation

To compile the Minitalk program, follow these steps:

1. Clone this repository and navigate to the project directory.

   ```bash
   git clone https://github.com/ChristosDurro/minitalk.git
   cd minitalk
   ```

2. Compile both the server (`server.c`) and client (`client.c`) programs using the provided Makefile:

   ```bash
   make
   ```

3. Enter a message in the client's terminal and press Enter to send it to the server.

4. The server will receive the message, display it, and send an acknowledgment message back to the client.

5. Repeat steps 3-4 to send more messages.

6. To terminate the server or client, use Ctrl+C.

## Example

Here's an example of how to use Minitalk:

1. Start the server:

   ```bash
   ./server
   Output: Server PID: 12345
   ```
   
2. Start a client with the server's PID:

   ```bash
   ./client 12345 "Hello World!"
   ```
   
3. In the client's terminal, enter a message (e.g., "Hello, server!") and press Enter.

4. The server will display the received message and send an acknowledgment back to the client.

5. Continue sending messages between the client and server as needed.
