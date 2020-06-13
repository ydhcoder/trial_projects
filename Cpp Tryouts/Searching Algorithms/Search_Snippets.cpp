#include <iostream>

using namespace std;
int searchList(int [], int, int);
int binarySearch(int [], int, int);

const int SIZE = 20;

// Linear Search Algorithm
int searchList(int list[], int numElems, int value)
{
	int index = 0; // Used as a subscript to search array
	int position = -1; // Used to record position of search value
	bool found = false; // Flag to indicate if the value was found
	
	while (index < numElems && !found)
	{
		if (list[index] == value) // If the value is found
		{
			found = true; // Set the flag
			position = index; // Record the value's subscript
		}
		
		index++; // Go to the next element
	}
	
	return position; // Return the position, or -1
}

int binarySearch(int array[], int numElems, int value)
{
	int first = 0, // First array element
	last = numElems - 1, // Last array element
	middle, // Midpoint of search
	position = -1; // Position of search value
	bool found = false; // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2; // Calculate midpoint
		if (array[middle] == value) // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1; // If value is in upper half
	}
	return position;
}

/* int main() {
	int tests[SIZE] = {87, 75, 98, 100, 82};
	int results;
	
	results = searchList(tests, SIZE, 100);
	if(results == -1) 
		cout << "You didn't earn 100 points on any test.\n";
	else {
		cout << "You earned 100 points on test ";
		cout << (results + 1) << ".\n";
	}
	return 0;	
} */

// This program performs a binary search on an integer array
// whose elements are in ascending order.
// Function prototype

int main()
{
	int tests[SIZE] = {101, 142, 147, 189, 199, 207, 222, 234, 289, 296, 310, 319, 388, 394, 417, 429, 447, 521, 536, 600};
	int results, empID;

	cout << "Enter the employee ID you wish to search for: ";
	cin >> empID;

	results = binarySearch(tests, SIZE, empID);

	if (results == -1)
		cout << "That number does not exist in the array.\n";
	else
	{
		cout << "That ID is found at element " << results + 1;
		cout << " in the array.\n";
	}
	return 0;
}

