#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <math.h>

using namespace std;

// Matrix Addition
void addMatrix(double [10][10], double [10][10], double [10][10], int, int);
// Matrix Multiplication
void mulMatrix(double [10][10], double [10][10], double [10][10], int, int, int);
// Transpose of Matrix
void transposeOf(double [10][10], double [10][10], int, int);
// Determinant of Matrix
double deter(double [10][10], int);
// Inverse of Matrix
void inv(double [10][10], int);
// Check for Square Matirx
bool isSquareMatrix(int, int);
// Check if valid to multiply
bool isValidToMultiply(int, int);
// Check similarity of size of Matrix
bool isEqualSizeMatrix(int, int, int , int);
// Print Matrix
void printMatrix(double [10][10], int, int);
// Create a copy Matrix
void copyMatrixValues(double [10][10], double [10][10], int, int);
// Assign Values to Matrix
void setValuesOfMatrix(double [10][10], int, int);

int main(int argc, char** argv) {
	char cont;
	int choice;
	int rows, rowsA, rowsB, colsA, colsB;

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
				cout << "Please insert the number of rows and columns respectively for the first matrix: ";
				cin >> rowsA >> colsA;
				cout << "Now insert the number of rows and columns respectively for the second matrix: ";
				cin >> rowsB >> colsB;
				while (!isEqualSizeMatrix(rowsA, colsA, rowsB, colsB)) {
					cout << "You can't multiply a "<< rowsA << " X " << colsA << " matrix with a " << rowsB <<  " X " << colsB << " matrix.\n";
					cout << "Please re-enter your values ...\n";
					cout << "Insert the number of rows and columns respectively for the first matrix: ";
					cin >> rowsA >> colsA;
					cout << "Insert the number of rows and columns respectively for the second matrix: ";
					cin >> rowsB >> colsB;
				}
				cout << endl;
				
				double mtx1[10][10];
				double mtx2[10][10];
				double sum[10][10];
				
				cout << "Now insert the first matrix: \n";
				setValuesOfMatrix(mtx1, rowsA, colsA);
				
				cout << "Then insert values for the second matrix: \n";
				setValuesOfMatrix(mtx2, rowsB, colsB);	
				
				addMatrix(mtx1, mtx2, sum, rowsA, colsA);
				
				printMatrix(mtx1, rowsA, colsA); 
				cout << "+\n";
				printMatrix(mtx2, rowsB, colsB);
				cout << "=\n";
				printMatrix(sum, rowsA, colsB);	
		}
		else if (choice == 2) {
			cout << "Please insert the number of rows and columns respectively for the first matrix: ";
			cin >> rowsA >> colsA;
			cout << "Now insert the number of rows and columns respectively for the second matrix: ";
			cin >> rowsB >> colsB;
			while (!isValidToMultiply(colsA, rowsB)) {
				cout << "You can't multiply a "<< rowsA << " X " << colsA << " matrix with a " << rowsB <<  " X " << colsB << " matrix.\n";
				cout << "Please re-enter your values ...\n";
				cout << "Insert the number of rows and columns respectively for the first matrix: ";
				cin >> rowsA >> colsA;
				cout << "Insert the number of rows and columns respectively for the second matrix: ";
				cin >> rowsB >> colsB;
			}
		
			double mtxA[10][10];
			double mtxB[10][10];
			double mul[10][10];

			cout << endl;
			cout << "Now insert values to the first matrix: \n";
			setValuesOfMatrix(mtxA, rowsA, colsA);
			cout << "Then insert values for the second matrix: \n";
			setValuesOfMatrix(mtxB, rowsB, colsB);	
			mulMatrix(mtxA, mtxB, mul, rowsA, colsA, rowsB);
			printMatrix(mtxA, rowsA, colsA); 
			cout << "X\n";
			printMatrix(mtxB, rowsB, colsB);
			cout << "=\n";
			printMatrix(mul, rowsA, colsB);	
		}
		else if (choice == 3) {
			cout << "Please insert the number of rows and columns respectively for the first matrix: ";
			cin >> rowsA >> colsA;

			double mtx1[10][10];
			double trans[10][10];

			cout << "Now insert values to the matrix to be transposed: \n";
			setValuesOfMatrix(mtx1, rowsA, colsA);
			transposeOf(mtx1, trans, rowsA, colsB);
			cout << "The transpose of: \n";
			printMatrix(mtx1, rowsA, colsA);
			cout << "is \n";
			printMatrix(trans, colsB, rowsA);	
		}
		else if (choice == 4) {
			int size;
			double matrix[10][10];
			cout << "Enter the size of your matrix: \n";
			cin >> size;
			setValuesOfMatrix(matrix, size, size);
			cout << "The determinant of: \n";
			printMatrix(matrix, size, size);
			cout << " is equal to:    " << deter(matrix, size) << endl;
		}	
		cout << "Do you want to continue with the program? Y / N.\n";
		cin >> cont;
	}
	while (cont == 'Y' || cont == 'y');

	return 0;
}

// Matrix Addition
void addMatrix(double a[10][10], double b[10][10], double sum[10][10], int row, int col) {
	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++)
			sum[i][j] = a[i][j] + b[i][j];
	}
}

// Matrix Multiplication
void mulMatrix(double a[10][10], double b[10][10], double mul[10][10], int rowsA, int colsA, int rowsB) {
	for (int i = 0; i < rowsA; i++) {
		for(int j = 0; j < colsA; j++) {
			mul[i][j] = 0;
			for(int k = 0; k < rowsB; k++)
				mul[i][j] += a[i][k] * b[k][j];
		}
	}
}
// Transpose of Matrix
void transposeOf(double a[10][10], double trans[10][10], int row, int col) {
	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			trans[i][j] = a[j][i];
		}
	}
}
// Determinant of Matrix
double deter(double a[10][10], int size){
	double det = 0;
	double subMtx[10][10];
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
bool isSquareMatrix(int row, int col) {
	if (row == col)
		return true;
	return false;
}
// Checks if valid to multiply
bool isValidToMultiply(int colA, int rowB) {
	if (colA == rowB)
		return true;
	return false;
}

// Check similarity of size of Matrix
bool isEqualSizeMatrix(int rowA, int colA, int rowsB, int colB) {
	if (rowA == rowsB && colA == colB) 
		return true;
	return false;
}

void printMatrix(double matrix[10][10], int row, int col) {
	for (int i = 0; i < row; i++) { 
		cout << "\t[";
		for (int j = 0; j < col; j++)
			cout<< matrix[i][j] << " ";
		cout << "]";
		cout << endl;
	}
}

void copyMatrixValues(double mtx1 [10][10], double mtx2 [10][10], int row, int col){
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mtx1[i][j] = mtx2[i][j];
}

void setValuesOfMatrix(double mtx[10][10], int row, int col) {
	cout << "Enter "<< row * col << " values for the " << row << " X " << col << " matrix.\n";
	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++)
			cin >> mtx[i][j];
		cout << endl;
	}
}


