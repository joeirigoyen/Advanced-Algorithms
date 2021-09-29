#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include "graph.h"

using namespace std;

graph readFromFile(string &filename) {
    // Initialize file
    ifstream File(filename);
    // Divide pairs of values into two separate vectors
    vector<int> v;
    vector<int> t;
    // Initalize file reading variables
    string s;
    regex e("\\(([^,]+),([^\\)]+)\\)");
    getline(File, s);
    // Start lookup
    int max = -1;
    sregex_iterator currMatch(s.begin(), s.end(), e);
    sregex_iterator lastMatch;
    while (currMatch != lastMatch) {
        for (unsigned i = 1; i < currMatch -> size(); ++i) {
            int num = stoi((*currMatch)[i]);
            if (num > max) {
                max = num;
            }
            if (i % 2 != 0) {
                v.push_back(num);
            } else {
                t.push_back(num);
            }
        }
        ++currMatch;
    }
    max++;
    // Initialize graph
    graph g(max);
    for (int i = 0; i < v.size(); i++) {
        g.connect(v[i], t[i]);
    }
    return g;
}