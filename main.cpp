//include statemments
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cfloat>
#include <algorithm>
#include <set>

const double INF = DBL_MAX; //infinity constant for unvisited nodes

//structure to represent an edge
struct Edge {
    int dest;
    double weight;
};

//function prototypes
std::vector<int> dijkstra(const std::vector<std::vector<Edge>>& graph, int source, int destination, std::vector<double>& pathWeights);

//main function
int main() {
    // define the graph using adjacency list
    // I have labeled each node on the map with both a letter and an integer. 
    // Node A, the source node, is also Node 0. Node B, the destination node, is also Node 15
    std::unordered_map<char, int> nodeIndex = {
        {'A', 0}, {'P', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6},
        {'H', 7}, {'I', 8}, {'J', 9}, {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13},
        {'O', 14}, {'B', 15}
    };

    //adjacency list for the representation of the weighted graph
    //it is represented as an undirected graph 
    std::vector<std::vector<Edge>> graph(16);
    graph[0] = {{1, 0.32}, {2, 0.4}}; //node A
    graph[1] = {{0, 0.32}, {4, 0.4}}; //node P
    graph[2] = {{0, 0.4}, {3, 0.1}, {7, 0.2}}; //node C
    graph[3] = {{2, 0.1}, {4, 0.08}, {6, 0.2}}; //node D
    graph[4] = {{1, 0.4}, {3, 0.08}, {5, 0.2}}; //node E
    graph[5] = {{4, 0.2}, {6, 0.05}, {9, 0.35}}; //node F
    graph[6] = {{3, 0.2}, {5, 0.05}, {7, 0.1}, {8, 0.15}}; //node G
    graph[7] = {{2, 0.2}, {6, 0.1}, {8, 0.28}}; //node H
    graph[8] = {{6, 0.15}, {7, 0.28}, {9, 0.25}}; //node I
    graph[9] = {{5, 0.35}, {8, 0.25}, {10, 0.2}, {11, 0.3}, {12, 0.3}}; //node J
    graph[10] = {{9, 0.2}, {11, 0.2}}; //node K
    graph[11] = {{9, 0.3}, {10, 0.2}, {13, 0.05}, {14, 0.28}}; //node L
    graph[12] = {{9, 0.3}, {13, 0.45}}; //node M
    graph[13] = {{11, 0.05}, {12, 0.45}, {15, 0.3}}; //node N
    graph[14] = {{11, 0.28}, {15, 0.2}}; //node O
    graph[15] = {{13, 0.3}, {14, 0.2}}; //node B

    //define source and destination as characters, ask user for input
    std::cout << "Please enter the starting point: ";
    char source;
    std::cin >> source;
    std::cout << std::endl;

    std::cout << "Please enter the destination point: ";
    char destination;
    std::cin >> destination;
    std::cout << std::endl;

    std::vector<double> pathWeights; //to hold the weight of each edge along the path
    std::vector<int> path = dijkstra(graph, nodeIndex[source], nodeIndex[destination], pathWeights); //run Dijkstra's algorithm

    //output the result
    if (path.empty()) {
        std::cout << "No path exists from " << source << " to " << destination << "." << std::endl;
    } else {
        std::cout << "Shortest path from " << source << " to " << destination << ": ";
        for (size_t i = 0; i < path.size(); ++i) {
            for (const auto& entry : nodeIndex) {
                if (entry.second == path[i]) {
                    std::cout << entry.first;
                    if (i < path.size() - 1) {
                        std::cout << " ->" << "(" << pathWeights[i] << ") ";
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    return 0;
}


//Dijkstra's algorithm 
std::vector<int> dijkstra(const std::vector<std::vector<Edge>>& graph, int source, int destination, std::vector<double>& pathWeights) {
    int n = graph.size();
    std::vector<double> distances(n, INF); //vector for tentative distances
    std::vector<int> parent(n, -1); //to reconstruct the path
    std::set<int> unvisited; // to hold the set of unvisited nodes

    //initialize distances and unvisited set
    distances[source] = 0;
    for (int i = 0; i < n; ++i) {
        unvisited.insert(i);
    }

    int current = source; //start at the source node

    while (!unvisited.empty()) {
        //consider all unvisited neighbors
        for (const Edge& edge : graph[current]) {
            if (unvisited.find(edge.dest) != unvisited.end()) {
                double newDistance = distances[current] + edge.weight;
                if (newDistance < distances[edge.dest]) {
                    distances[edge.dest] = newDistance;
                    parent[edge.dest] = current;
                }
            }
        }

        //mark current node as visited
        unvisited.erase(current);

        //stop if destination is visited or no connection remains
        if (current == destination || distances[current] == INF) {
            break;
        }

        //select the unvisited node with the smallest distance
        double smallestDistance = INF;
        for (int node : unvisited) {
            if (distances[node] < smallestDistance) {
                smallestDistance = distances[node];
                current = node;
            }
        }
    }

    //reconstruct the path from source to destination
    std::vector<int> path;
    for (int at = destination; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());

    //if the first node in the path isn't the source, there's no valid path
    if (path.front() != source) {
        path.clear();
    }

    //calculate weights for each edge in the path to print later
    pathWeights.clear();
    for (size_t i = 1; i < path.size(); ++i) {
        int u = path[i - 1], v = path[i];
        for (const Edge& edge : graph[u]) {
            if (edge.dest == v) {
                pathWeights.push_back(edge.weight);
                break;
            }
        }
    }

    return path;
}