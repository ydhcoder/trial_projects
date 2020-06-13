/* GPA calculator*/

#include <iostream>

using namespace std;

int main() {
	int subjectMark;
	do {
		cout<< "Enter your subject mark: ";
		cin>> subjectMark;
	} while (subjectMark > 100 || subjectMark < 0);
	
	
	int markInt = subjectMark / 10;
	cout<< "You scored  ";
	switch(markInt) {
		case 10:
		case 9: 
			cout<< "A";
			break;
		case 8:
			cout<< "B";
			break;
		case 7:
			cout<< "B";
			break;
		case 6:
			cout<< "C";
			break;
		case 5:
			cout<< "D";
			break;
		case 4:	
			cout<< "F";
		case 3:
		case 2:
		case 1:
		case 0:
		default:
			cout<< "F";
	}
	/*
	int markInt = subjectMark / 15;
	cout<< "You scored  ";
	switch(markInt) {
		case 6:
			cout<< "A";
			break;
		case 5:
			cout<< "B";
			break;
		case 4:
			cout<< "C";
			break;
		case 3:
			cout<< "D";
			break;
		case 2:
			cout<< "F";
			break;
		case 1:	
		case 0:
		default:
			cout<< "F";
	}
	*/
	return 0;
}
