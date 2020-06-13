// This program uses a pointer to display the contents
// of an integer array. It illustrates the comparison of
// pointers.
#include <iostream>
using namespace std;
int main()
{
    const int SIZE = 8;
    int set[ ] = {5, 10, 15, 20, 25, 30, 35, 40};
    int *nums = set; // Make nums point to set

    cout << "The numbers in set are:\n";
    cout << *nums << " "; // Display first element
    while (nums < &set[SIZE-1])
    {
        nums++;
        cout << *nums << " ";
    }
    cout << "\nThe numbers in set backwards are:\n";
    cout << *nums << " "; // Display last element
    
    while (nums > set)
    {
        nums--;
        cout << *nums << " ";
    }
    return 0;
}
