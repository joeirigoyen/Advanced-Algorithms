#include <iostream>
#include <vector>

using namespace std;

/* Get Z array given a string combining the pattern and the original string separated by a special character */
void getZ(char* &s) {
    // Get size of string
    const size_t stringSize = sizeof(s) / sizeof(s[0]);
    // Create an empty array with the size of the string
    int zArr[stringSize];
    // Declare left and right pointers
    size_t l = 0;
    size_t r = 0;
    // Start lookup
    for (int i = 0; i < stringSize; i++) {
        if (i > r) {
            r = i;
            l = r;
            while (true) {
                if (r >= stringSize || s[r] != s[r - l]) {
                    break;
                } else {
                    r++;
                }
            }
            zArr[i] = r - l;
                r--;
        }
    }
}

/* Find a pattern within a given string using the Z algorithm*/
void findPattern(char* &s, char* &p) {
    // Get sizes of both the string and the pattern
    const size_t sSize = sizeof(s) / sizeof(s[0]);
    const size_t pSize = sizeof(p) / sizeof(p[0]);
    // Create new string using pattern, the original string and a special character '$'
    const size_t newSize = sSize + pSize + 1;
    char newStr[newSize];
    // Add special character
    newStr[sSize] = '$';
    // Add pattern characters
    for (int i = 0; i < pSize; i++) {
        newStr[i] = p[i];
    }
    // Add string characters
    for (int i = sSize + 1; i < newSize; i++) {
        newStr[i] = s[i];
    }
    // Print new string
    for (char c: newStr) {
        cout << c;
    }
} 

int main() {
    findPattern();
}