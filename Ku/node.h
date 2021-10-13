#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Node {
    public:
        int val;
        vector<int> adjList;
        Node(int n) {
            val = n;
        }
        Node() {
            val = 0;
        }
};