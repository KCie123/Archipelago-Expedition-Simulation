# Archipelago Expedition Simulation

This project is a simulation of an archipelago expedition with the ability to manage islands and ferry connections. The project uses a command-based input system to manipulate and traverse the island network. Key features include adding, deleting, and finding paths between islands, simulating how an expedition could navigate through a series of islands.

## Project Description
The program allows the user to manage a network of islands, where each island can have ferry connections to other islands. The user can add, delete, and list ferry connections, as well as find the shortest path between two islands using a breadth-first search algorithm. The simulation is command-driven and can read commands from standard input or from a file.

### Key Features:
- **Island Network:** The user can manage islands and ferry connections in a directed graph structure.
- **Breadth-First Search:** Finds the shortest path between two islands if a path exists.
- **Island Manipulation:** Add and remove islands and ferry connections dynamically.
- **Command Interface:** Provides a series of commands to manipulate and explore the island network, such as travel (`t`), resize (`r`), and list connections (`l`).

## Technologies Used:
- **C++:** Main programming language used for the implementation.
- **Makefile:** Used to compile the project.

## How to Install and Run the Project

### Prerequisites
- C++ compiler (e.g., `g++`)
- A terminal or command-line interface

### Steps
1. Clone the Repository:
   ```bash
   git clone https://github.com/yourusername/archipelago-expedition.git
   cd archipelago-expedition

2. Build the project using the provided makefile:
    ```bash
    make

3. Run the compiled program:
    ```bash
    ./archipelago
