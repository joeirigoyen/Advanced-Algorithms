#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "csvparser.cpp"

using namespace std;
using namespace std::chrono;

// Print z-array
template <typename T>
void printArray(vector<T> arr) {
    cout << "Z array is: " << endl;
    cout << "{";
    for (int i = 0; i < arr.size(); i++) {
        if (i < arr.size() - 1) {
            cout << arr[i] << ", ";
        } else {
            cout << arr[i];
        }
    }
    cout << "}" << endl;
}

/* Get Z array given a string combining the pattern and the original string separated by a special character */
vector<int> findPattern(const string &s, const string &p) {
    // Create new string
    string newStr = p + "$" + s;
    size_t n = newStr.size();
    // Create empty z-array
    vector<int> z = vector<int>(n, 0);
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
                cout << "Found " << p << " in index " << i  << endl;
            }
            z[i] = count;
            count = 0;
        }
    }
    cout << "Found " << prefCount << " exact matches." << endl;
    return z; 
} 

int main(int argc, char** argv) {
    // Initialize string
    string text = getStringFromFile(argv[1]);
    // Look for pattern in text
    /* ---- Runtime test ---- */
    auto start = high_resolution_clock::now();
    vector<int> zarr = findPattern(text, argv[2]);
    auto stop = high_resolution_clock::now();
    auto runtime = duration_cast<microseconds>(stop - start);
    auto secs = runtime.count() / 10e5;
    printArray(zarr);
    cout << "Found in " << secs << " seconds" << endl;
}
