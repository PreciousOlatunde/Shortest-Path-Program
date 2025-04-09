# Shortest-Path-Program
This program uses Dijkstra's algorithm to find the shortest path from a chosen Node X to a chosen Node Y given a graph map symbolizing a road network. 
Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a weighted graph; in this program the weights correspond to the distance between the nodes

How to execute/run the shortestPath program

Files needed:
1. main.cpp
2. labeled_graph_map.jpg (to make sense of the result)

Execution:
1. Both of the aforementioned files should be in the same folder
2. The folder where the files are should be your present working directory
3. To compile the program correctly on the Terminal, type and enter the command: g++ -std=c++11 -o shortestPath main.cpp
4. To run the program, type and enter the command: ./shortestPath
5. The program then prompts you for a starting point (any upper-case character from A to P), and ending point (any upper-case character from A to P)

Making sense of the result:
1. The program simply prints the shortest path from the chosen starting node to chosen ending node, as long as both nodes are present in the graph map in labeled_graph_map.jpg
2. My labeled_graph_map.jpg file is a graph map where I labeled all the nodes in the image with integers as well as names.
4. Node A is also Node 0, and Node B is also Node 15. The numbers and letters corresponding to each node is shown/detailed in my labeled_graph_map.jpg image
5. The main function in my main.cpp file also has a nodeIndex unordered map showing which Node letter corresponds to which Node number
6. In the result of running my code, as well as the Node letters, the corresponding weight of each edge in the path is also printed (in parentheses) for the sake of convenience and better understanding.
    e.g if an edge on the path goes from Node F to Node J (which has a weight("distance") of 0.35), it would print as: F ->(0.35) J

Other notes:
1. make sure when compiling the program, that the "-std=c++11" flag is in the command as my code may not properly compile with older compilers without the specified flag.
