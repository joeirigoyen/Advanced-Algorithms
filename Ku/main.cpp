#include <iostream>
#include <string>
#include <vector>
#include "matrixReader.cpp"
#include "graph.h"

using namespace std;

void initializeFromMatrix(vector<vector<int>> &m, Graph &g) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            if (m[i][j] != 0) {
                g.AddWeightedEdge(i, j, m[i][j]);
            }
        }
    }
}


int main(int argc, char *argv[]) {
    // Get file
    string filename = argv[1];
    size_t size = countNodes(filename);
    vector<vector<int>> adjMat = initAdjMatrix(filename, size);
    // Fill graph
    Graph g(size);
    initializeFromMatrix(adjMat, g);
    g.kruskal();
    g.print();
    return 0;
}