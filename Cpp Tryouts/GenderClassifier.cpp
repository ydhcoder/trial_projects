#include <iostream>

using namespace std;

int main() {
	
	char sex;
	cout<< "Enter your sex (M/F or m/f): ";
	cin>>sex;
	
	switch (sex) {
		case 'M':
			cout<<"You're a male.";
			break;
		case 'm':
			cout<<"You're a male.";
			break;
		case 'F':
			cout<<"You're a female.";
			break;
		case 'f':
			cout<<"You're a female.";
			break;
		default:
			cout<<"Enter a valid value! Thank you.";
	}
	
	return 0;
}
