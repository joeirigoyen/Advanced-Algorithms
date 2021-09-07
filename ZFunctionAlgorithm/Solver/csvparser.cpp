#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string getStringFromFile(char* &path) {
    // Initalize empty string
    string result = "";
    // Initialize file
    string line, word, temp;
    fstream fin(path);
    // Read file
    getline(fin, temp);
    stringstream s(temp);
    while (getline(s, word, ',')) {
        result += word;
    }
    return result;
}