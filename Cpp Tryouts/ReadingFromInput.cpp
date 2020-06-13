#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
	ifstream indata;
	indata.open("myfile.txt", ios::in);
	
	if(indata.fail()) 
		cout << "Sorry: Unable to access file";
	while(!indata.eof()) {
		cout << indata.getLine();
	}
	
	return 0;
}
