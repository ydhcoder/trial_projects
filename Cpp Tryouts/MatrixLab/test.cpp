#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <math.h>

using namespace std;

const int NUM_COLS1 = 2;
const int NUM_COLS2 = 2;

// Matrix Addition
void addMatrix(double [][NUM_COLS1], double [][NUM_COLS1], double [][NUM_COLS1], int);
// Matrix Multiplication
void mulMatrix(double [][NUM_COLS1], double [][NUM_COLS1], double [][NUM_COLS2], int, int);
// Transpose of Matrix
void transposeOf(double [][NUM_COLS1], double [][NUM_COLS1], int);
// Determinant of Matrix
double deter(double [10][10], int);
// Inverse of Matrix
void inv(double [10][10], int);
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
void setValuesOfSubMatrix(double [10][10], int);

int main(int argc, char** argv) {
	char cont;
	int choice;
	int rows, rowsA, rowsB;

	cout << "Welcome to Matrix Lab! \n";
	cout << "---------------------------\n";
	do {
		do {
			cout <<  "Here are the possible set of tools you can use to manipulate Matrices.\n";
			cout <<  "1. Add Matrices\n";
			cout <<  "2. Multiply Matrices\n";
			cout <<  "3. Transpose Matrix\n";
			cout <<  "4. Determinant of Matrix\n";
			cout <<  "5. Inverse of Matrix\n";
			cout <<  "Choose one ...";
			cin >> choice;
		} while (choice < 1 || choice > 5);
		
		if(choice == 1) { 
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
		}
		else if (choice == 2) {
			cout << "The number of columns for the first Matrix is pre-set to: " << NUM_COLS1 << endl; 
			cout << "Please insert the number of rows for the first matrix: ";
			cin >> rowsA;
			cout << "The number of columns for the second Matrix is pre-set to: " << NUM_COLS2 << endl; 
			cout << "Please insert the number of rows for the second matrix: ";
			cin >> rowsB;
			cout << "Making sure the Matrices are valid to be multiplied ...\n";
			
			while (!isValidToMultiply(rowsB)) {
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
				cout << "You can't multiply a "<< rowsA << " X " << NUM_COLS1 << " matrix with a " << rowsB <<  " X " << NUM_COLS2 << " matrix.\n";
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
				cout << "Please re-enter your values ...\n";
				cout << "The number of columns for the first Matrix is pre-set to: " << NUM_COLS1 << endl; 
				cout << "Please insert the number of rows for the first matrix: ";
				cin >> rowsA;
				cout << "The number of columns for the second Matrix is pre-set to: " << NUM_COLS2 << endl; 
				cout << "Please insert the number of rows for the second matrix: ";
				cin >> rowsB;
				cout << "Making sure the Matrices are valid to be multiplied ...\n";
			}
		
			double mtxA[rowsA][NUM_COLS1];
			double mtxB[rowsB][NUM_COLS1];
			double mul[rows][NUM_COLS1];
			cout << endl;
			cout << "Now insert values to the first matrix: \n";
			setValuesOfMatrix(mtxA, rowsA);
			cout << "Then insert values for the second matrix: \n";
			setValuesOfMatrix(mtxB, rowsB);	
			mulMatrix(mtxA, mtxB, mul, rowsA, rowsB);
			printMatrix(mtxA, rowsA); 
			cout << "X\n";
			printMatrix(mtxB, rowsB);
			cout << "=\n";
			printMatrix(mul, rowsA);	
		}
		else if (choice == 3) {
			cout << "The number of columns is pre-set to: " << NUM_COLS1 << endl; 
			cout << "Please insert the number of rows for the first matrix: ";
			cin >> rows;

			double mtx1[rows][NUM_COLS1];
			double trans[rows][NUM_COLS1];

			cout << "Now insert values to the matrix to be transposed: \n";
			setValuesOfMatrix(mtx1, rows);
			transposeOf(mtx1, trans, rows);
			cout << "The transpose of: \n";
			printMatrix(mtx1, rows);
			cout << "is \n";
			printMatrix(trans, rows);	
		}
		else if (choice == 4) {
			int size;
			double matrix[10][10];
			cout << "Enter the size of your matrix: ";
			cin >> size;
			cout << "Enter the values for your " << size << " X " << size << " matrix";
			setValuesOfSubMatrix(matrix, size);
			cout << "The determinant of: \n";
			printMatrix(matrix, size);
			cout << " is -->", deter(matrix, size);
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
void mulMatrix(double a[][NUM_COLS1], double b[][NUM_COLS2], double mul[][NUM_COLS1], int numRowsA, int numRowsB) {
	for (int i = 0; i < numRowsA; i++) {
		for(int j = 0; j < NUM_COLS1; j++) {
			mul[i][j] = 0;
			for(int k = 0; k < numRowsB; k++)
				mul[i][j] += a[i][k] * b[k][j];
		}
	}
}
// Transpose of Matrix
void transposeOf(double a[][NUM_COLS1], double trans[][NUM_COLS1], int numRows) {
	for (int i = 0; i < numRows; i++) {
		for(int j = 0; j < NUM_COLS1; j++) {
			trans[i][j] = a[j][i];
		}
	}
}
// Determinant of Matrix
double deter(double a[10][10], int size){
	int det = 0;
	int subMtx[10][10];
	if (size = 2) 
	 	return ((a[0][0] * a[1][1] - a[1][0] * a[0][1]));
	else {
		for (int x = 0; x < size; x++) {
			int subi = 0;
			for (int i = 1; i < size; i++) {
				int subj = 0;
				for(int j = 0; j < size; j++) {
					if (j = x)
						continue;
					subMtx[subi][subj] = a[i][j];
					subj++;
				}
				subi++;
			}
			det = det + pow(-1, x) * a[0][x] * deter(subMtx, size - 1);
		}
	}
}
// Inverse of Matrix
void inv(double a[10][10], int size) {

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
void printMatrix(double matrix[10][10], int size) {
	for (int row = 0; row < size; row++) { 
		cout << "\t[";
		for (int col = 0; col < size; col++) {
			cout<< matrix[row][col] << " ";
		}
		cout << "]";
		cout << endl;
	}
}

void copyMatrixValues(double mtx1 [][NUM_COLS1], double mtx2 [][NUM_COLS1], int numRows){
	for (int row = 0; row < numRows; row++)
		for (int col = 0; col < NUM_COLS1; col++)
			mtx1[row][col] = mtx2[row][col];
}

void setValuesOfMatrix(double mtx1 [][NUM_COLS1], int numRows) {
	cout << "Enter "<< numRows * NUM_COLS1 << " values for the " << numRows << " X " << NUM_COLS1 << " matrix.\n";
	for (int i = 0; i < numRows; i++) {
		for(int j = 0; j < NUM_COLS1; j++)
			cin >> mtx1[i][j];
		cout << endl;
	}
}

void setValuesOfSubMatrix(double mtx[10][10], int size) {
	cout << "Enter "<< pow(size, 2) << " values for the " << size << " X " << size << " matrix.\n";
	for (int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++)
			cin >> mtx[i][j];
		cout << endl;
	}
}


