#include <iostream>
#include <vector>
#include <fstream>
#include "dijkstras.h"

using namespace std;

int main() {
    Graph G;
    file_to_graph("./src/medium.txt", G);  

    int source = 0;

    vector<int> previous(G.numVertices, -1);

    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    for (int destination = 0; destination < G.numVertices; ++destination) {
        if (distances[destination] != INF) {
            vector<int> path = extract_shortest_path(distances, previous, destination);
            print_path(path, distances[destination]);
        }
    }

    return 0;
}
