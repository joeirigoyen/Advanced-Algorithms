#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int countNodes(string &filename) {
    // Initialize file
    ifstream file(filename);
    // Initialize strings
    string line;
    string elems;
    // Initialize counting variables
    int count = 0;
    getline(file, line, ';');
    stringstream lineElems(line);
    // Start counting adjacency rows
    while (getline(lineElems, elems, ',')) {
        count++;
    }
    return count;
}

vector<vector<int>> initAdjMatrix(string &filename, size_t &n) {
    // Initialize matrix
    vector<int> row(n, 0);
    vector<vector<int>> matrix(n, row);
    // Initialize file
    ifstream file(filename);
    // Initialize lookup variables
    string line;
    size_t i = 0, j = 0;
    // Start lookup
    while (getline(file, line, ';')) {
        string num;
        stringstream ss(line);
        j = 0;
        while (ss.good()) {
            getline(ss, num, ',');
            int n = stoi(num);
            matrix[i][j] = n;
            j++;
        }
        i++;
    }
    return matrix;
}