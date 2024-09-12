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
    ./Project6

### Prerequisites
- C++ compiler (e.g., `g++`)
- A terminal or command-line interface

### How to use the project
After running the program, you can input commands to manipulate the island network. Below are some of the commands you can use:

* t <int1> <int2>: Finds the shortest path between island <int1> and <int2>.
* r <int>: Resizes the island network to hold <int> islands.
* i <int1> <int2>: Inserts a ferry connection between island <int1> and <int2>.
* d <int1> <int2>: Deletes a ferry connection between island <int1> and <int2>.
* l: Lists all ferry connections.
* f <filename>: Reads commands from a file and processes them.
* q: Quits the program.

### Example Usage

    t 1 3      # Finds the shortest path from island 1 to island 3
    r 20       # Resizes the network to 20 islands
    i 1 5      # Inserts a ferry connection between island 1 and 5
    l          # Lists all current ferry connections

### File Structure

    Archipelago Expedition
    │
    ├── makefile          # Makefile to compile the project
    ├── Proj6main.cpp     # Main program file containing the command loop and logic
    ├── Island.cpp        # Island class implementation
    ├── header.h          # Header file with class definitions
    └── README.md         # This documentation file

## Class Descriptions

### `ArchipelagoExpedition`
- Manages the entire archipelago, including the adjacency list for ferry rides and the search algorithms.
- Handles user commands through the `processCommandLoop()` function.
- Uses `Island`, `IslandQueue`, and `IslandStack` to represent the islands and manage operations.

### `Island`
- Represents each island in the archipelago.
- Contains a linked list of ferry connections to other islands.
- Methods include:
  - `setValue(int val)`: Sets a value for the island.
  - `getValue()`: Retrieves the value of the island.
  - `insert(int val)`: Adds a ferry connection to another island.
  - `remove(int val)`: Removes a ferry connection.
  - `exists(int val)`: Checks if a ferry connection exists.
  - `clear()`: Clears all ferry connections.
  - `printList()`: Prints the list of ferry connections.

### `IslandQueue`
- A queue implementation used in the breadth-first search algorithm.
- Handles queue operations such as:
  - `enqueue(int val)`: Adds a value to the queue.
  - `dequeue()`: Removes a value from the queue.
  - `peak()`: Gets the value at the front of the queue.
  - `is_empty()`: Checks if the queue is empty.

### `IslandStack`
- A stack implementation used to store the path from one island to another.
- Handles stack operations such as:
  - `push(int val)`: Pushes a value onto the stack.
  - `pop()`: Pops a value from the stack.
  - `top()`: Gets the value at the top of the stack.
  - `is_empty()`: Checks if the stack is empty.

  
