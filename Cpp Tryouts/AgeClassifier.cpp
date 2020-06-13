/*Program to Classify Ages of people*/

#include <iostream>
using namespace std;

int main() {
	
	int age;
	
	/*cout<<"Enter your age: ";
	cin>>age;
	while (true) {
		if (age > 0  && age <= 13) {
			cout<< "You're classified as kid.";
			break;
		}
		else if (age > 13 && age <= 18) {
			cout<< "You're classified as Young.";
			break;
		}
		else if (age > 18 && age <= 45) {
			cout<< "You're classified as an Adult.";
			break;
		}
		else if (age > 45 && age <= 150) {
			cout<< "You're classified as Old.";
			break;
		}
		else {
			cout<<"Enter a valid value: ";
			cin>>age;
		} */
		
		do {
			cout<<"Enter your age: ";
			cin>>age;
			if (age > 0  && age <= 13) {
				cout<< "You're classified as kid.";
				break;
			}
			else if (age > 13 && age <= 18) {
				cout<< "You're classified as Young.";
				break;
			}
			else if (age > 18 && age <= 45) {
				cout<< "You're classified as an Adult.";
				break;
			}
			else if (age > 45 && age <= 150) {
				cout<< "You're classified as Old.";
				break;
			}
			else {
				cout<<"Enter a valid value: ";
			}
		}while (false);
}
