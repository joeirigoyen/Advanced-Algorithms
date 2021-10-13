#include <iostream>
#include <vector>
using namespace std;

void findPrefix(string &pattern, int &m, vector<int> &prefArray);
//void kmpPattSearch(string mainString, string pattern, int *locArray, int &loc);
void kmpPattSearch(string &mainString, string &pattern, vector<int> &locArray, size_t &loc);
