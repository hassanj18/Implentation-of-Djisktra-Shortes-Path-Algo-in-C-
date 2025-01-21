# Implentation-of-Djisktra-Shortes-Path-Algo-in-C-
Implementation of Djikstra Shortest Path Algo using Custom made Minheap Modelled as Hospital Routing System 
# Dijkstra's Shortest Path Algorithm Implementation

This repository contains an implementation of Dijkstra's Shortest Path Algorithm in C++. The algorithm is designed to find the shortest path from a starting node to all other nodes in a weighted graph represented using an adjacency list.

## Table of Contents

- [Features](#features)
- [Classes](#classes)
  - [Info](#info)
  - [MinHeap](#minheap)
- [Functions](#functions)
  - [ReadData](#readdata)
  - [PrintData](#printdata)
- [Usage](#usage)
- [Compilation and Execution](#compilation-and-execution)
- [Contributing](#contributing)
- [License](#license)

## Features

- Efficiently finds the shortest path in a graph using a priority queue (min-heap).
- Supports dynamic resizing of the min-heap.
- Reads graph data from a specified file format.
- Prints the shortest path information for each node.

## Classes

### Info

The `Info` class represents a node in the graph with the following attributes:
- `ID`: A string that identifies the node.
- `Time`: An integer representing the weight or cost associated with reaching this node.

#### Methods
- `print()`: Outputs the ID and Time of the node.
- Constructors and Destructor: Default and parameterized constructors, along with a destructor.

### MinHeap

The `MinHeap` class implements a min-heap to efficiently manage the nodes based on their weights. It provides methods to insert nodes, delete the minimum node, and decrease the weight of a node.

#### Methods
- `insert(int TIME, string ID)`: Inserts a new node into the heap.
- `getMin()`: Returns the node with the minimum weight.
- `DeleteMin()`: Removes the node with the minimum weight from the heap.
- `DecreaseTime(string id, int NewTime)`: Updates the weight of a node and maintains the heap property.
- `is_Empty()`: Checks if the heap is empty.
- `print()`: Prints all elements in the heap.
- `ReturnAtIndex(string id)`: Returns the `Info` object at the specified index.

## Functions

### ReadData

```cpp
void ReadData(string filename, vector<list<Info>>& Data);
```

Reads the graph data from a file. The file should contain:
1. The number of nodes.
2. Each subsequent line representing a node and its edges in the format: `NodeID: (NeighborID1, Weight1) (NeighborID2, Weight2) ...`.

### PrintData

```cpp
void PrintData(vector<list<Info>>& data);
```

Prints the graph data stored in the provided vector of lists.

## Usage

To use this implementation, ensure you have a properly formatted input file containing the graph data. Modify the main function (not shown in this snippet) to call `ReadData` with the filename and then execute the Dijkstra algorithm using the populated data structure.

## Compilation and Execution

To compile and run the program, follow these steps:

1. Ensure you have a C++ compiler installed (like `g++`).
2. Compile the code:
   ```bash
   g++ -o dijkstra dijkstra.cpp
   ```
3. Run the executable:
   ```bash
   ./dijkstra
   ```

## Contributing

Contributions are welcome! If you have suggestions for improvements or additional features, please open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

---

Feel free to modify this README to better fit your project's specific needs!
