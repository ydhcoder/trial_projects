/* 
 * This is a program that helps manipulate Matrices and make computations with them. This program supports
 * matrix operations such as addition, multiplication, transpose, determinant and inverse of Matrices. 
 * Simplified using arrays and condensed into functions, any programmer can use them in its program.
 * 
 * A maximum of 5 X 5 matrices may be operated with this program. Our program works best in the lower 
 * size matrices. To support further matrix size, one can change the constant variable N.
 * 
 * MADE IN AASTU; Group 8; Section C
 * Department of Electrical and Computer Engineering
 */
 
#include <iostream>
#include <math.h>
#include <pthread.h>

using namespace std;

#define N 10

typedef float matrix[N][N];	// Created a type definition of matrix type
								// supporting 5 x 5 size.
								

// Matrix Addition
void addMatrix(matrix, matrix, matrix, int, int);
// Matrix Multiplication
void mulMatrix(matrix, matrix, matrix, int, int, int);
// Check for Square Matirx
bool isSquareMatrix(int, int);
// Check if valid to multiply
bool isValidToMultiply(int, int);
// Print Matrix with square braces
void printMatrix(matrix, int, int);
// Prints matrix in determinant form
void printMatrixDet(matrix, int, int);
// Create a copy Matrix
void copyMatrixValues(matrix, matrix, int, int);
// Assign Values to Matrix
void setValuesOfMatrix(matrix, int, int);
// Cofactor of a matrix
void cofactorOf(matrix, matrix, int, int, int);
// Cofactored Matrix
void cofactoredMatrix (matrix, matrix, int);
// Adjoint of a matrix
void adjoint (matrix, matrix, int);
// Determinant of Matrix
float determinant(matrix, int);
// Inverse of Matrix
bool inv(matrix, matrix, int);


int main(int argc, char** argv) {
	char cont;
	int choice;
	int rows, cols;

	cout << "\t\t\t\t\t\tWelcome to Matrix Lab! \n";
	cout << "\t\t\t\t\t#####################################\n";
	do {
		do {
			cout <<  "Here are the possible set of tools you can use to manipulate Matrices.\n";
			cout <<  "1. Add Matrices\n";
			cout <<  "2. Multiply Matrices\n";
			cout <<  "3. Transpose Matrices\n";
			cout <<  "4. Determinant of Matrices\n";
			cout <<  "5. Cofactor of Matrices\n";
			cout <<  "6. Adjoint of Matrices\n";
			cout <<  "7. Inverse of Matrices\n";
			cout <<  "Choose one ...";
			cin >> choice;
		} while (choice < 1 || choice > 7);
		
		system("pause");
		system("cls");
		
		if(choice == 1) { 
			cout<<"\t\t\t#### Determinant of a Matrices ####\n";
			cout << "Please insert the number of rows and columns respectively you operate with respectively.";
			cin >> rows >> cols;
		
			matrix mtx1;
			matrix mtx2;
			matrix sum;
			
			cout << "Now insert the first matrix: \n";
			setValuesOfMatrix(mtx1, rows, cols);
			
			cout << "Then insert values for the second matrix: \n";
			setValuesOfMatrix(mtx2, rows, cols);	
			
			addMatrix(mtx1, mtx2, sum, rows, cols);
			
			printMatrix(mtx1, rows, cols); 
			cout << "+\n";
			printMatrix(mtx2, rows, cols);
			cout << "=\n";
			printMatrix(sum, rows, cols);	
		}
		else if (choice == 2) {
			int rowsA, rowsB, colsA, colsB;
			cout<<"\t\t\t#### Multiplication of a Matrices ####\n";
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
		
			matrix mtxA;
			matrix mtxB;
			matrix mul;

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
			cout<<"\t\t\t#### Transpose of a Matrices ####\n";
			cout << "Please insert the number of rows and columns respectively for the your matrix: ";
			cin >> rows >> cols;

			matrix mtx;
			matrix trans;

			cout << "Now insert values to the matrix to be transposed: \n";
			setValuesOfMatrix(mtx, rows, cols);

			// Transposes the matrix
			for(int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					trans[j][i] = mtx[i][j];
				}
			}

			cout << "The transpose of: \n";
			printMatrix(mtx, rows, cols);
			cout << "is \n";
			printMatrix(trans, cols, rows);	
		}
		else if (choice == 4) {
			cout<<"\t\t\t#### Determinant of a Matrices ####\n";
			int size;
			matrix mtx;
			cout << "Enter the dimension of your square matrix: \n";
			cin >> size;
			setValuesOfMatrix(mtx, size, size);
			cout << "The determinant: \n";
			printMatrixDet(mtx, size, size);
			cout<< "equals " << determinant(mtx, size) << endl;
		}
		else if (choice == 5) {
			cout<<"\t\t\t#### Cofactoring Matrices ####\n";
			int size;
			matrix mtx;
			matrix temp;
			cout << "Enter the dimension of your square matrix: \n";
			cin >> size;
			setValuesOfMatrix(mtx, size, size);
			cofactoredMatrix(mtx, temp, size);
			
			cout << "The cofactor of:  " << endl;
			printMatrix(mtx, size, size);
			cout << "is " << endl;
			printMatrix(temp, size, size);
		}	
		else if (choice == 6 ) {
			cout<<"\t\t\t#### Adjoint of Matrices ####\n";
			int size;
			matrix mtx;
			matrix temp;
			cout << "Enter the dimension of your square matrix: \n";
			cin >> size;
			setValuesOfMatrix(mtx, size, size);
			adjoint(mtx, temp, size);

			cout << "The adjoint of:  " << endl;
			printMatrix(mtx, size, size);
			cout << "is " << endl;
			printMatrix(temp, size, size);
		}
		else if (choice == 7) {
			cout<<"\t\t\t#### Inverse of Matrices ####\n";
			int size;
			matrix mtx;
			matrix temp;

			cout << "Enter the dimension of your square matrix: \n";
			cin >> size;
			setValuesOfMatrix(mtx, size, size);
			bool inverse = inv(mtx, temp, size);
			if (inverse) {
				cout << "The inverse of:  " << endl;
				printMatrix(mtx, size, size);
				cout << "is " << endl;
				printMatrix(temp, size, size);
			}
			else {
				cout << "Singular Matrix! Doesn't have an inverse.";
			}
		}
		cout << "Do you want to continue with the program? Y / N.\n";
		cin >> cont;
	}
	while (cont == 'Y' || cont == 'y');
	return 0;

}// main ends here

// Matrix Addition
void addMatrix(matrix a, matrix b, matrix sum, int row, int col) {
	// Loop each row by column to add both components
	// of matrix a and b
	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++)
			sum[i][j] = a[i][j] + b[i][j];
	}
}

// Matrix Multiplication
void mulMatrix(matrix a, matrix b, matrix mul, int rowsA, int colsA, int rowsB) {
	// Looping each row by column
	for (int i = 0; i < rowsA; i++) {
		for(int j = 0; j < colsA; j++) {
			mul[i][j] = 0;  // sets the temp variable to 0 at ith row
							// and jth column
			for(int k = 0; k < rowsB; k++)
				mul[i][j] += a[i][k] * b[k][j]; //Loop through and multiply each elements
												// at a specific row for matrix a and at a specific
												// column for matrix b
		}
	}
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

// Function prints each elements in a matrix
void printMatrix(matrix mtx, int row, int col) {
	for (int i = 0; i < row; i++) { 
		cout << "\t[";
		for (int j = 0; j < col; j++)
			cout<< mtx[i][j] << " ";
		cout << "]";
		cout << endl;
	}
}

// Function prints each elements in a determinant form
void printMatrixDet(matrix mtx, int row, int col) {
	for (int i = 0; i < row; i++) { 
		cout << "\t|";
		for (int j = 0; j < col; j++)
			cout<< mtx[i][j] << " ";
		cout << "|";
		cout << endl;
	}
}

// Copies values from the first matrix to the second matrix
void copyMatrixValues(matrix mtx1 , matrix mtx2 , int row, int col){
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mtx2[i][j] = mtx1[i][j];
}

// Assigns values to each element in a matrix
void setValuesOfMatrix(matrix mtx, int row, int col) {
	cout << "Enter "<< row * col << " values for the " << row << " X " << col << " matrix.\n";
	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++)
			cin >> mtx[i][j];
		cout << endl;
	}
}

// Function that helps get the cofactor of a matrix A and 
// stores it in a temp matrix; d is the current dimension of the matrix
void cofactorOf(matrix A, matrix temp, int r, int c, int size) {
	
	int i, j;
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			// Copying into temporary matrix only for those elements
			// which are not in the given row and columns
			if(row != r && col != c) {
				temp[i][j++] = A[row][col];

				// Row is filled, so increase row index and
				// reset col index
				if (j == size - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
} 

/* Recursive function for finding the determinant of a matrix.
	size is the current dimension of matrix mtx. */

float determinant(matrix A, int size) {
	float D = 0; //Initializing result

	// Base case : if matrix contains single element
	if (size == 1) 
		return A[0][0];
	
	matrix temp; // To store cofactors
	int sign = 1; // Stores sign multipliers

	// Iterate for each element of first row (fr)
	for (int fr = 0; fr < size; fr++) {
		//Getting Cofactor of A[0][fr]
		cofactorOf(A, temp, 0, fr, size);
		D += sign * A[0][fr] * determinant(temp, size - 1);

		// Terms are to be added with alternate sign
		sign = -sign;
	}

	return D;
}

// Function that stores the cofactored matrix of matrix A  
// in a temp matrix variable cof
void cofactoredMatrix (matrix A, matrix cof, int size) {
	if (size == 1) {
		cof[0][0] = A[0][0];
		return;
	}

	// temp is used as a temp variable to store the submatrices
	int sign = 1;
	matrix temp;

	for (int i = 0; i < size; i ++) {
		for (int j = 0; j < size; j++) {
			// Get cofactor of A[i][j]
			cofactorOf(A, temp, i, j, size);

			// Sign of adj matrix positive if the sum of row
			// and column indexes is even.
			sign = ((i+j) % 2 == 0) ? 1 : -1;

			cof[i][j] = (sign) * (determinant(temp, size - 1));
		}
	}
}

// Function to get adjoint of A[N][N] in adj[N][N]
void adjoint (matrix A, matrix adj, int size) {
	if (size == 1) {
		adj[0][0] = 1;
		return;
	}

	// temp is used to store cofactors of matrix A
	int sign = 1;
	matrix temp;

	for (int i = 0; i < size; i ++) {
		for (int j = 0; j < size; j++) {
			// Get cofactor of A[i][j]
			cofactorOf(A, temp, i, j, size);

			// Sign of adj matrix positive if the sum of row
			// and column indexes is even.
			sign = ((i+j) % 2 == 0) ? 1 : -1;

			// Interchanging rows and columns to get the 
			// transpose of the cofactor matrix
			adj[j][i] = (sign) * (determinant(temp, size - 1));
			
		}
	}
}

// Function to calculate and store the inverse, returns false if
// the matrix is singular
bool inv(matrix A, matrix inverse, int size) {

	// Find the determinant of matrix A
	float det = determinant(A, size);
	if (det == 0) {
		cout << "Singular matrix, can't find its inverse.";
		return false;
	}

	// Finding adjoint
	matrix adj;
	adjoint(A, adj, size);
	
	// Find the inverse using formula "inverse(A) = adj(A) / det(A)"

	for (int i = 0; i < size; i++)
		for(int j = 0; j < size; )
			inverse[i][j] = adj[i][j] / det;
		
	return true;
}



