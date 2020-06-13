#include <iostream>

using namespace std;

float TriangleArea(float, float);

int main() {
	float base, height;
	cout << "Calculate the area of the triange first by entering the base then the height." << endl;
	cin >> base >> height;
	cout << "The area becomes "<< TriangleArea(base, height);
	return 0;
}

float TriangleArea(float base, float height) {
	return 0.5 * base * height;
}

