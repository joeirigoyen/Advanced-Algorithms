#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void printVector(vector<int> &vec) {
    /* Print every element in a vector */
    cout << '{';
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << " ";
        }
    }
    cout << '}' << endl;
}

string getVector(vector<int> &vec) {
    string s = "{";
    /* Add ever vector element to string*/
    for (int i = 0; i < vec.size(); i++) {
        if (i < vec.size() - 1) {
            s += to_string(vec[i]) + ",";
        } else {
            s += to_string(vec[i]) + "}";
        }
    }
    return s;
}

void printMatrix(vector<vector<int>> &m) {
    /* Print every vector inside a matrix */
    for (int i = 0; i < m.size(); i++) {
        if (i < m.size()) {
            printVector(m[i]);
        }
    }
}

void printMatrix(vector<vector<int>> &m, string &path) {
    /* Initialize file */
    ofstream file(path);
    string line;
    /* Print every vector inside a matrix */
    for (int i = 0; i < m.size(); i++) {
        if (i < m.size()) {
            file << getVector(m[i]) + "\n";
        }
    }
}

const int count(string &path) {
    fstream file;
    string line;
    int c = 0;
    while(getline(file, line)) {
        c++;
    }
    return c;
}

vector<vector<int>> initMatrixFromFile(char* &path) {
    /* Initialize matrix by opening file and counting its files */
    // Create empty matrix
    vector<vector<int>> matrix;
    // Create file and line streams
    fstream file;
    string line;
    // Open file from the given path in the functions' arguments
    file.open(path);
    // Read file line by line until iterator reaches end of file
    while (!file.eof()) {
        // Create temporary vector
        vector<int> temp;
        // Get whole line from file
        getline(file, line);
        // Create a sstream based on current line
        stringstream ss(line);
        // Iterate through sstream
        while (ss.good()) {
            // Create a string to store each number that's separated by a comma
            string num;
            // Get every number
            getline(ss, num, ',');
            // If number is not empty, add it to the temporary vector
            if (num != "\0") {
                temp.push_back(stoi(num));
            }
        }
        // If the temporary vector is not empty, push it to the matrix and clear the temporary vector
        if (temp.size() > 0) {
            matrix.push_back(temp);
            temp.clear();
        }
    }
    // Return new matrix
    return matrix;
}
