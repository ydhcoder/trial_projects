// Program that displays the sum of two integers
#include <iostream>
using namespace std;

int main() {
	
	int x,y,sum;
	
	cout<< "Enter two numbers:\n"; //Or
	/*cout<< "Enter two numbers:"<< endl;*/
	cin>> x >> y;
	
	/*Ways to get inputs;
		cin>> input1>>input2>> .... >>inputn;
		
		or
		
		cin>>input1;
		cin>>input2;
		.
		.
		cin>>inputn;
	*/

	sum = x + y;
	
	cout<< "Sum = " << sum;
	return 0;
}
