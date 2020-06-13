#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

int main() {
	long long x, y, n;	
	cout<< "n"<< "	|	"<< "x"<< "	|	"<< "y"<<endl;
	n = 1;
	
	while (n < 11, n < 12) {
		x = n;
		y = pow(n,3);
		cout<< n<< "	|	"<< x<< "	|	"<< y<<endl;
		n++;
	}
	
	return 0;
}
