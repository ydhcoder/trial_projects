#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
using namespace std;

const int NUM_COLS1 = 3;
const int NUM_COLS2 = 3;

// Matrix Addition
void addMatrix(double [][NUM_COLS1], double [][NUM_COLS1], double [][NUM_COLS1], int);
// Matrix Multiplication
void mulMatrix(double [][NUM_COLS1], double [][NUM_COLS1], double [][NUM_COLS2], int, int);
// Transpose of Matrix
void transposeOf(double [][NUM_COLS1], int);
// Determinant of Matrix
double deter(double[][NUM_COLS1], int);
// Inverse of Matrix
void inv(double[][NUM_COLS1], int);
// Check for Square Matirx
bool isSquareMatrix(int);
// Check if valid to multiply
bool isValidToMultiply(int);
// Print Matrix
void printMatrix(double [][NUM_COLS1], int);
// Create a copy Matrix
void copyMatrixValues(double [][NUM_COLS1], double [][NUM_COLS1], int);
// Assign Values to Matrix
void setValuesOfMatrix(double [][NUM_COLS1], int);

int main(int argc, char** argv) {
	char cont;
	int choice;
	int rows, rowsA, rowsB;

	cout << "Welcome to Matrix Lab! \n";
	cout << "---------------------------\n";
	do {
		do {
			cout << "Here are the possible set of tools you can use to manipulate Matrices.\n";
			cout <<  "1. Add Matrices\n";
			cout <<  "2. Multiply Matrices\n";
			cout <<  "3. Transpose Matrix\n";
			cout <<  "4. Determinant of Matrix\n";
			cout <<  "5. Inverse of Matrix\n";
			cout << "Choose one ...";
			cin >> choice;
		} while (choice < 1 || choice > 5);
		
		switch (choice) {
			case 1: 
				cout << "Please insert the number of rows for the Matrices: ";
				cin >> rows;
				cout << endl;
				
				double mtx1[rows][NUM_COLS1];
				double mtx2[rows][NUM_COLS1];
				double sum[rows][NUM_COLS1];
				
				cout << "Now insert the first matrix: \n";
				setValuesOfMatrix(mtx1, rows);
				
				cout << "Then insert values for the second matrix: \n";
				setValuesOfMatrix(mtx2, rows);	
				
				addMatrix(mtx1, mtx2, sum, rows);
				
				printMatrix(mtx1, rows); 
				cout << "+\n";
				printMatrix(mtx2, rows);
				cout << "=\n";
				printMatrix(sum, rows);	
				break;
			case 2:
				cout << "Please insert the number of rows for the first matrix: ";
				cin >> rowsA;
				cout << "Please insert the number of rows for the second matrix: ";

				cin >> rowsB;
				cout << "Making sure the Matrices are valid to be multiplied ...";
				
				while (!isValidToMultiply(rowsB)) {
					cout << "You can't multiply a "<< rowsA << " X " << NUM_COLS1 << " matrix with a " << rowsB <<  " X " << NUM_COLS2 << " matrix.\n";
					cout << "Please re-enter your values ...";
					cout << "Please insert the number of rows for the first matrix: ";
					cin >> rowsA;
					cout << "Please insert the number of rows for the second matrix: ";
					cin >> rowsB;
				}
			
				double mtxA[rowsA][NUM_COLS1];
				double mtxB[rowsB][NUM_COLS1];
				double mul[rows][NUM_COLS1];

				cout << endl;
				cout << "Now insert values to the first matrix: \n";
				setValuesOfMatrix(mtx1, rows);
				cout << "Then insert values for the second matrix: \n";
				setValuesOfMatrix(mtx2, rows);	

				mulMatrix(mtx1, mtx2, mul, rowsA, rowsB);
				printMatrix(mtx1, rows); 
				cout << "X\n";
				printMatrix(mtx2, rows);
				cout << "=\n";
				printMatrix(sum, rows);	
				break;
		}
		cout << "Do you want to continue with the program? Y / N.\n";
		cin >> cont;
	}
	while (cont == 'Y' || cont == 'y');

	return 0;
}

// Matrix Addition
void addMatrix(double a[][NUM_COLS1], double b[][NUM_COLS1], double sum[][NUM_COLS1], int numRows) {
	for (int i = 0; i < numRows; i++) {
		for(int j = 0; j < NUM_COLS1; j++)
			sum[i][j] = a[i][j] + b[i][j];
	}
}
// Matrix Multiplication
void mulMatrix(double a[][NUM_COLS1], double b[][NUM_COLS1], double mul[][NUM_COLS2], int numRowsA, int numRowsB) {
	for (int i = 0; i < numRowsA; i++) {
		for(int j = 0; j < NUM_COLS1; j++) {
			mul[i][j] = 0;
			for(int k = 0; k < numRowsB; k++)
				mul[i][j] += a[i][k] * b[k][j];
		}
	}
}
// Transpose of Matrix
void transposeOf(double a[][NUM_COLS1], int numRows) {

}
// Determinant of Matrix
double deter(double a[][NUM_COLS1], int numRows){
	
}
// Inverse of Matrix
void inv(double a[][NUM_COLS1], int numRows) {

}
// Checks if our matrix is square
bool isSquareMatrix(int numRows) {
	if (NUM_COLS1 == numRows)
		return true;
	return false;
}
// Checks if valid to multiply
bool isValidToMultiply(int numRows) {
	if (NUM_COLS1 == numRows)
		return true;
	return false;
}

void printMatrix(double matrix[][NUM_COLS1], int numRows) {
	for (int row = 0; row < numRows; row++) { 
		cout << "\t[";
		for (int col = 0; col < NUM_COLS1; col++) {
			cout<< matrix[row][col] << " ";
		}
		cout << "]";
		cout << endl;
	}
}

void copyMatrixValues(double mtx1 [][NUM_COLS1], double mtx2 [][NUM_COLS1], int numRows){
	for (int row = 0; row < numRows; row++) { 
		for (int col = 0; col < NUM_COLS1; col++) {
			mtx1[row][col] = mtx2[row][col];
		}
	}
}

void setValuesOfMatrix(double mtx1 [][NUM_COLS1], int numRows) {
	cout << "Enter "<< numRows * NUM_COLS1 << " values for the " << numRows << " X " << NUM_COLS1 << " matrix.\n";
	for (int i = 0; i < numRows; i++) {
		for(int j = 0; j < NUM_COLS1; j++)
			cin >> mtx1[i][j];
		cout << endl;
	}
}


