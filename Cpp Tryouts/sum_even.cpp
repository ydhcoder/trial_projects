#include <iostream>

using namespace std;

int main() {

	int sum = 0;
	cout<< "The sum of the first 50 even integers is ";
   	/*for(int i = 1; i < 26; i++) {
		sum += 2 * i;
	} */
	
	for(int i = 2; i <= 100; i += 2) {
		sum += i;
	}
	
	cout<<sum<<".";
	return 0;
}
