#include<iostream>
#include <fstream>
#include<string>
#include <vector>
#include "kmpAlgorithm.h"
using namespace std;

int main() {
	ifstream mcodefile1("txt_files/mcode1.txt");
	ifstream file("txt_files/transmission.txt");
	string transmission;
	string mcode1;
	getline(mcodefile1, mcode1);
	getline(file, transmission);
    int trans_size = transmission.size();
    int pref_size = mcode1.size();
	vector<int> locationArray = vector<int>(trans_size, 0); 
	size_t index;
	
	kmpPattSearch(transmission, mcode1, locationArray, index);
	if(index > 0){
		for(auto i = 0; i < index; i++){
			cout << locationArray[i];
			if(i < index - 1){
				cout << ", ";
			}
		}
		cout << endl;
	} else{
		cout << "False" << endl;
	}
}
