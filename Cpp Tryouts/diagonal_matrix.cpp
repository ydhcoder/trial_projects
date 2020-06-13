/*Print a Diamond of numbers*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	/*
	for(int i= 1; i < 6; i++) {
		for (int j = 1; j <= i; j++) {
			cout<<i<<" ";
		}
		cout<<endl;
 	}*/
 	
 	for(int i = 1; i < 5; i++) {
 		for(int j = 0; j <= (4 - i); j++)
 			cout<<" ";
 		for(int k = 0; k < i; k++)
 			cout<<i<<" ";
 		cout<<endl;
	 }
 	
 	for(int i = 3; i > 0; i--) {
 		for(int k = 1; k <= (5 - i); k++)
 			cout<<" ";
		 for(int j = 0; j < i; j++)
 			cout<<i<<" ";
 		cout<<endl;
	 }
	return 0;
}
