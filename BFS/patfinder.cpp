#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* Get Z array given a string combining the pattern and the original string separated by a special character */
vector<int> findPattern(const string &s, const string &p) {
    // Create new string
    string newStr = p + "$" + s;
    size_t n = newStr.size();
    // Create empty z-array
    vector<string> z = vector<int>();
    // Define current z-box range to 0
    size_t l = 0, r = 0;
    // Set initial matching characters and exact matches count
    int count = 0, prefCount = 0;
    // Set current lookup index
    size_t index = 1;
    // Start lookup (z-naive approach)
    for (size_t i = 1; i < n; i++) {
        // If there is a particular match
        if (newStr[i] == newStr[l]) {
            r = i;
            while (newStr[r] == newStr[l] && r < n) {
                count++;
                r++;
                l++;
            }
            l = 0;
            if (count == p.size()) {
                prefCount++;
                z.push_back(i);
            }
            z[i] = count;
            count = 0;
        }
    }
    return z; 
} 
