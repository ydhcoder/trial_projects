#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
	fstream infile;
	infile.open("myfile.txt", ios::out);
	
	if(infile.fail()) {
		cout<< "\nError Opening File!";
		exit(1);
	}
	
	if(infile.is_open()) {
		infile << "Name: Yeabsra Debebe" << endl;
		infile << "Email: yeabsdebe@gmail.com"<< endl;
		infile << "Phone Number: +251 967303866"<< endl;
		infile << "Address: Addis Ababa, Ethiopia"<< endl;
	}
	
	infile.close();
	return 0;
}
