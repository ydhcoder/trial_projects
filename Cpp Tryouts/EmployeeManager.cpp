// A program that organizes employees information
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

struct employee {
	char id[11];
	char name[31];
	int age;
	char gender[9];
	double salary;
	char hobby[30][2];
};

int main() {
	ofstream outFile;

    int numOfEmployee;
	cout << "How many employees do you want to manage? ";
	cin >> numOfEmployee;
	cout << "Enter " << numOfEmployee << " employee information.";
	cout << "\n";
	cout << "---------------------------------------------------";
	cout << "\n";
	employee Employee[numOfEmployee];
	
	for(int i = 0; i < numOfEmployee; i++) {
		cout << "Id: ";
		cin >> Employee[i].id;
		cout << "\n";
		cin.ignore();
		cout << "Name: ";
		cin.getline(Employee[i].name, 30);
        cout << "\n";
		cout << "Age: ";
		cin >> Employee[i].age ;
        cout << "\n";
        cin.ignore();
		cout << "Gender: ";
		cin.getline(Employee[i].gender, 8);
        cout << "\n";
		cout << "Salary: ";
		cin >> Employee[i].salary ;
        cout << "\n";
        cin.ignore();
		cout << "Hobbies: ";
		cin.getline(Employee[i].hobby[1], 30);
        cin.getline(Employee[i].hobby[2], 30);
        cout << "\n";

	}

	outFile.open("Employee Information", ios::app);

	if(outFile.fail()) {
		cout<< "\nError Opening File!";
		exit(1);
	}

	if(outFile.is_open()) {
		for(int i = 0; i < numOfEmployee; i++) {
			
			// Outputting to File
			outFile << "Id: ";
			outFile << Employee[i].id << endl;
			outFile << "Name: ";
			outFile << Employee[i].name << endl;
			outFile << "Age: ";
			outFile << Employee[i].age << endl;
			outFile << "Gender: ";
			outFile << Employee[i].gender << endl;
			outFile << "Salary: ";
			outFile << "$" << Employee[i].salary << endl;
			outFile << "Hobbies: ";
			outFile << Employee[i].hobby[1] << ", " << Employee[i].hobby[2] << endl;
			outFile << "---------------------------------------" << endl; 
			
		}
	}

	return 0;
}

