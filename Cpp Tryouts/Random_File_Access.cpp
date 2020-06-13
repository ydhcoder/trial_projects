#include<iostream>
#include<fstream>

using namespace std;

struct stud_info{
	int id;
	char name[20];
	char fname[20];
	float CGPA;
} student;

int main() {
	char filename[15];
	ofstream outdata;
	cout<<"\nenter file name : "; // Like C:\\files\\kole.txt

	cin>>filename;
	outdata.open(filename,ios::out);

	if(outdata.fail())
	{
		cout <<"\nError opening "<<filename;
		exit(1);
	}
	
	//stud_info student;
	//accept data here
	cout<<"\nEnter student id : ";
	cin>>student.id;
	cin.ignore();
	
	cout<<"\nEnter student name : ";
	cin>>student.name;
	
	cout<<"\nEnter student father name : ";
	cin>>student.fname;
	cout<<"\nEnter student CGPA : ";
	cin>>student.CGPA;
	//now write to the file
	outdata.seekp(((student.id)-1) * sizeof(student));
	outdata.write((char*) &student, sizeof(student));
	outdata.close();
	cout<<"\nData has been saved";
	return 0;
}
