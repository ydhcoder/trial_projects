#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {
	int x,y,i;	
	cout<< "Enter different numbers you want to cube: "<<endl;
	cout<< "n"<< "	|	"<< "x"<< "	|	"<< "y"<<endl;
	do{
		cin>>i;
		y = i*i*i;
		cout<< "	|	"<< i<< "	|	"<< y;
	}while(true); 
	/*	
	for(;;) {
		cin>>i;
		y = i*i*i;
		cout<< i<< "	|	"<< i<< "	|	"<< y<<endl;
	}
	*/
    return 0;
}
