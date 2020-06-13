// Program that displays the sum of two integers
#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string stdName;
	string idNum;
	int age;
	float CGPA;
	
	cout<<"Enter Student Information: "<< endl;
	cout<<"Full Name: ";
	cin>>stdName;
	cout<<"Id Number:";
	cin>>idNum;
	cout<<endl;
	cout<<"Age: ";
	cin>>age;
	cout<<endl;
	cout<<"Cumulative GPA:";
	cin>>CGPA;
	
	cout<<stdName + ", ";
	cout<<"your information has been updated successfully!";
	return 0;
}
