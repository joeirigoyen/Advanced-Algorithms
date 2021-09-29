#include <queue>
#include <string>
#include "graph.h"
#include "reader.cpp"

using namespace std;

void print_queue(queue<int> q) {
    if (q.empty()) {
        cout << "-";
    } else {
        while(!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
    }
    cout << endl;
}

void graph::connect(int s, int t) {
    if (true) {
        adjlist[s].push_back(t);
    }
}

void graph::display() {
    for (int i = 0; i < vertices; i++) {
        cout << "Adjacency list for node " << i << endl;
        for (auto it : adjlist[i]) {
            cout << it << endl;
        }
    }
    cout << endl;
}

void graph::showVisited() {
    for (int i = 0; i < vertices; i++) {
        if (visited[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void graph::bfs(int s) {
    // Initialize visited vertices list
    visited = new bool[vertices];
    for (int i = 1; i < vertices; i++) {
        visited[i] = false;
    }
    // Initialize pivot queue
    queue<int> q;
    q.push(s);
    vector<int>::iterator i;
    // Start search
    while (!q.empty()) {
        s = q.front();
        visited[s] = true;
        q.pop();
        cout << "Current pivot: " << s << endl;
        cout << "Remaining pivots: ";
        print_queue(q);
        cout << "Visited vertices: ";
        showVisited();
        for (i = adjlist[s].begin(); i != adjlist[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
        cout << endl;
    }
}

int main() {
    // Read file
    string filename = "D:\\irigx\\Documents\\School\\5to\\ADA\\Advanced-Algorithms\\BFS\\texts\\test.txt";
    graph g;
    g = readFromFile(filename);
    g.display();
    g.bfs(1);
}