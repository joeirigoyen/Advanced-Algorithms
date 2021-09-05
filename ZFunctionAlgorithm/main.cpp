#include <iostream>
#include <string>

using namespace std;

/* Get Z array given a string combining the pattern and the original string separated by a special character */
void getZ(string &s) {
    // Define left and right bounds for z-boxes as well as the matching index
    int l = 0, r = 0, m = 0;
    // Start lookup from second element in z-array
    for (int i = 1; i < s.size(); i++) {
        // If there is no match currently
        if (i > r) {
            
        }
    }
}

/* Find a pattern within a given string using the Z algorithm */
void findPattern(const string &s, const string &p) {
    // Create new string
    string newStr = p + "$" + s;
    // Find pattern within string
} 

int main() {
    findPattern("aabcabcaabca", "abcaa");
}