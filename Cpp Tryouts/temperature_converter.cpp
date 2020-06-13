#include <iostream>
using namespace std;

double cel2Far(float);
double far2Cel(float);

double cel2Far(float t) {
    return 9/5*t + 32;
}

double far2Cel(float t) {
    return (0.555555555 )* (t - 32);
}


int main() {
        cout<<"98.6 degree celsius is "<<cel2Far(98.6)<<" degree farhenheit."<<endl;
        cout<<"37 degree farheneit is "<<far2Cel(37.0)<<" degree celsius.";
        return 0;
}


