/*Program checking if odd or even*/

#include <iostream>\

using namespace std;

int main(){
	
	int num;
	
	cout<<"Enter a number: ";
	cin>>num;
	
	num % 2 == 0 ? cout<< "even": cout<< "odd";
	return 0;
}
