/* GPA calculator*/

#include <iostream>

using namespace std;

int main() {
	float subjectMark;
	do {
		cout<< "Enter your subject mark: ";
		cin>> subjectMark;
	} while (subjectMark > 100 || subjectMark < 0);
	
	cout<< "Your scored  ";
	if (subjectMark >= 90) 
		cout<< "A";
	else if(subjectMark >= 75 && subjectMark < 90) 
		cout<< "B";
	else if(subjectMark >= 60 && subjectMark < 75) 
		cout<< "C";
	else if(subjectMark >= 45 && subjectMark < 60) 
		cout<< "D";
	else
		cout<< "F";
	return 0;
}
