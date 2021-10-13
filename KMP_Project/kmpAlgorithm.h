#include <iostream>
#include <vector>

#pragma once

using namespace std;

void findPrefix(string &pattern, int &m, vector<int> &prefArray);
void kmpPattSearch(string &mainString, string &pattern, vector<int> &locArray, size_t &loc);
