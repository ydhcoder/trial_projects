#include <iostream>
using namespace std;
void compare(float, float);

void compare() {
	float x, y;
	cin>>x;
	cin>>y;
	if(x < y)
		cout<<x<<" is the smaller number";
	else if(x > y)
		cout<<y<<" is the smaller number";
	else
		cout<<"Both are equal";
}

float compareNum(float,float);
float compareNum(float x, float y) {
	if (x > y)
		return y;
	else if (x < y)
		return x;
}

int main() {
	float num1,num2;
	cin>>num1>>num2;
	cout<<compareNum(num1, num2)<<" is the smaller number";
	//compare();
    return 0;
}
 

