#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

int main() {
	int x, y, n;	
	cout<< "n"<< "	|	"<< "x"<< "	|	"<< "y"<<endl;
	n = 1;
	
	do{
		x = n;
		y = pow(n,3);
		cout<< n<< "	|	"<< x<< "	|	"<< y<<endl;
		n++;
	}
	while (n < 11);
	
	return 0;
}
