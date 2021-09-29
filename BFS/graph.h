#include <iostream>
#include <vector>

using namespace std;

#pragma once

class graph {
    // Create adjacency list
    vector<int> *adjlist;
    bool* visited;
    int vertices;
    // Public methods
    public:
        // Create constructor
        graph() {
            this -> vertices = 1;
            adjlist = new vector<int>[1];
        }

        graph(int n) {
            this -> vertices = n;
            adjlist = new vector<int>[vertices];
        }
        // Add edge
        void connect(int s, int t);
        void display();
        void bfs(int s);
        void showVisited();
}; 