#include <iostream>
#include <string>

using namespace std;

/* Get Z array given a string combining the pattern and the original string separated by a special character */
void findPattern(const string &p, const string &s) {
    // Create new string
    string newStr = p + "$" + s;
    // Define current z-box range to 0
    size_t l = 0, r = 0;
    // Set initial matching characters count
    int count = 0;
    // Set current lookup index
    size_t index = 1;
    // Start lookup (z-naive approach)
    for (int i = 1; i < newStr.size(); i++) {
        // If there is no particular match
        if (i > r) {
            
        }
    }
} 

int main() {
    findPattern("aabcabcaabca", "abcaa");
}