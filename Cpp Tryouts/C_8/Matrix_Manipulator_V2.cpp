/* 
 * This is a program that helps manipulate Matrices and make computations with them. This program supports
 * matrix operations such as addition, multiplication, transpose, determinant, adjoint and inverse of Matrices. 
 * Simplified using arrays and condensed into functions, any programmer can use them in its program.
 * 
 * A maximum of 5 X 5 matrices may be operated with this program.  
 * To support further matrix size, one can change the constant variable N.
 * 
 * MADE IN AASTU; Group 8; Section C
 * Department of Electrical and Computer Engineering
 */
 
#include <iostream>
#include <math.h>
#include <pthread.h>
#include <bits/stdc++.h>

using namespace std;

#define N 5 

typedef float matrix[N][N];		// Created a type definition of matrix type
								// supporting 5 x 5 size.
								
// Matrix Addition
void addMatrix(matrix a, matrix b, matrix sum, int row, int col) {
	// Loop each row by column to add both components
	// of matrix a and b
	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++)
			sum[i][j] = a[i][j] + b[i][j];
	}
}

// Matrix Subtraction
void subMatrix(matrix a, matrix b, matrix sub, int row, int col) {
	// Loop each row by column to subtract both components
	// of matrix a and b
	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++)
			sub[i][j] = a[i][j] - b[i][j];
	}
}

// Matrix Multiplication
void mulMatrix(matrix a, matrix b, matrix mul, int rowsA, int colsA, int rowsB) {
	// Looping each row by column
	for (int i = 0; i < rowsA; i++) {
		for(int j = 0; j < colsA; j++) {
			//mul[i][j] = 0;  // sets the temp variable to 0 at ith row
							// and jth column
			for(int k = 0; k < rowsB; k++)
				mul[i][j] += a[i][k] * b[k][j]; // Loop through and multiply each elements
												// at a specific row for matrix a and at a specific
												// column for matrix b
		}
	}
}

// Checks if our matrix is a square matrix
bool isSquareMatrix(int row, int col) {
	if (row == col)
		return true;
	return false;
}

// Checks if two matrices are valid to multiply
bool isValidToMultiply(int colA, int rowB) {
	if (colA == rowB)
		return true;
	return false;
}

// Function prints each elements in a matrix with square braces
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
void printMatrixDet(matrix mtx, int size) {
	for (int i = 0; i < size; i++) { 
		cout << "\t|";
		for (int j = 0; j < size; j++)
			cout<< mtx[i][j] << " ";
		cout << "|";
		cout << endl;
	}
}

// Prints a square matrix to the screen
void printSqrMatrix(matrix mtx, int size) {
		for (int i = 0; i < size; i++) { 
		cout << "\t[";
		for (int j = 0; j < size; j++)
			cout<< mtx[i][j] << " ";
		cout << "]";
		cout << endl;
	}
}

// Copies values from the first matrix to the second matrix
void copyMatrixValues(matrix mtx1 , matrix mtx2 , int row, int col){
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mtx2[i][j] = mtx1[i][j];
}

// Assigns values to each element in a matrix by prompting the user
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
void cofactorOf(matrix mat, matrix temp, int r, int c, int size) {
	
	int i = 0;
	int j = 0;
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			// Copying into temporary matrix only for those elements
			// which are not in the given row and columns
			if(row != r && col != c) {
				temp[i][j++] = mat[row][col];

				// Row is filled, so increase row index and
				// reset col index
				if (j == (size - 1)) {
					j = 0;
					i++;
				}
			}
		}
	}
} 

/* Recursive function for finding the determinant of a matrix.
 * size is the current dimension of matrix A. 
 */
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

// Function to get the adjoint Matrix of A[size][size] in adj[size][size]
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

// Function to get the cofactored Matrix of A[size][size] in cofM[size][size]
void cofactoredMatrix (matrix A, matrix cofM, int size) {
	if (size == 1) {
		cofM[0][0] = A[0][0];
		return;
	}

	// temp is used to store cofactors of matrix A
	int sign = 1;
	matrix temp;

	for (int i = 0; i < size; i ++) {
		for (int j = 0; j < size; j++) {
			// Get cofactor of A[i][j]
			cofactorOf(A, temp, i, j, size);

			// Sign of cofactored matrix positive if the sum of row
			// and column indexes is even.
			sign = ((i+j) % 2 == 0) ? 1 : -1;

			cofM[i][j] = (sign) * (determinant(temp, size - 1));
			
		}
	}
}

// Function to calculate and store the inverse, returns false if
// the matrix is singular
bool inv(matrix A, matrix inverse, int size) {

	// Find the determinant of matrix A
	float det = determinant(A, size);
	if (det == 0) {
		cout << "Singular matrix! It doesn't have inverse.\n";
		return false;
	}

	// Finding adjoint
	matrix adj;
	adjoint(A, adj, size);
	
	// Find the inverse using formula "inverse(A) = adj(A) / det(A)"

	for (int i = 0; i < size; i++)
		for(int j = 0; j < size; j++ )
			inverse[i][j] = adj[i][j] / det;
		
	return true;
}


int main(int argc, char** argv) {
	char cont;
	int choice;
	int rows, cols;
	
	system("color 0B");
	cout << "\t\t\t\t\t\tWelcome to Matrix Lab! \n";
	cout << "\t\t\t\t\t#####################################\n";
	do {
		do {
			cout <<  "Here are the possible set of tools you can use to manipulate Matrices.\n";
			cout <<  "1. Add Matrices\n";
			cout <<  "2. Subtract Matrices\n";
			cout <<  "3. Multiply Matrices\n";
			cout <<  "4. Transpose Matrices\n";
			cout <<  "5. Determinant of Matrices\n";
			cout <<  "6. Adjoint of Matrices\n";
			cout <<  "7. Cofactor Matrix of Matrices\n";
			cout <<  "8. Inverse of Matrices\n";
			cout <<  "Choose one ...";
			cin >> choice;
		} while (choice < 1 || choice > 8);
		
		system("pause");
		system("cls");
		
		if(choice == 1) { 
			cout<<"\t\t\t#### Addition of Matrices ####\n";
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

			char addmore;
			cout << "Do you want to continue adding? Insert + for Yes and any other key for NO!\n";
			cin >> addmore;
			while (addmore == '+') {
				copyMatrixValues(sum, mtx1, rows, cols);
				setValuesOfMatrix(mtx2, rows, cols);
				addMatrix(mtx1, mtx2, sum, rows, cols);
				printMatrix(mtx1, rows, cols); 
				cout << "+\n";
				printMatrix(mtx2, rows, cols);
				cout << "=\n";
				printMatrix(sum, rows, cols);
				cout << "Do you want to continue adding? Insert + for Yes and any other key for NO!";
				cin >> addmore;
			}
		}
		else if(choice == 2) { 
			cout<<"\t\t\t#### Subtraction of Matrices ####\n";
			cout << "Please insert the number of rows and columns respectively you operate with respectively.";
			cin >> rows >> cols;
		
			matrix mtx1;
			matrix mtx2;
			matrix sub;
			
			cout << "Now insert the first matrix: \n";
			setValuesOfMatrix(mtx1, rows, cols);
			
			cout << "Then insert values for the second matrix: \n";
			setValuesOfMatrix(mtx2, rows, cols);	
			
			subMatrix(mtx1, mtx2, sub, rows, cols);
			
			printMatrix(mtx1, rows, cols); 
			cout << "-\n";
			printMatrix(mtx2, rows, cols);
			cout << "=\n";
			printMatrix(sub, rows, cols);	
			
			char subMore;
			cout << "Do you want to continue subtracting? Insert - for Yes and any other key for NO!\n";
			cin >> subMore;
			while (subMore == '-') {
				copyMatrixValues(sub, mtx1, rows, cols);
				setValuesOfMatrix(mtx2, rows, cols);
				addMatrix(mtx1, mtx2, sub, rows, cols);
				printMatrix(mtx1, rows, cols); 
				cout << "+\n";
				printMatrix(mtx2, rows, cols);
				cout << "=\n";
				printMatrix(sub, rows, cols);
				cout << "Do you want to continue subtracting? Insert + for Yes and any other key for NO!";
				cin >> subMore;
			}
		}
		else if (choice == 3) {
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
		else if (choice == 4) {
			cout<<"\t\t\t#### Transpose of Matrices ####\n";
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
		else if (choice == 5) {
			cout<<"\t\t\t#### Determinant of Matrices ####\n";
			matrix mtx;
			cout << "Enter the dimension of your square matrix: \n";
			int size;
			cin >> size;
			setValuesOfMatrix(mtx, size, size);
			cout << "The determinant: \n";
			printMatrixDet(mtx, size);
			cout<< "equals " << determinant(mtx, size) << endl;
		}
		else if (choice == 6) {
			cout<<"\t\t\t#### Adjoint of Matrices ####\n";
			matrix mtx, adj;
			cout << "Enter the dimension of your square matrix: \n";
			int size;
			cin >> size;
			setValuesOfMatrix(mtx, size, size);
			adjoint(mtx, adj, size);
			cout << "The adjoint of: \n";
			printMatrix(mtx, size, size);
			cout << "is\n";
			printMatrix(adj, size, size);
		}
		else if (choice == 7) {
			cout<<"\t\t\t#### Cofactor Matrix of Matrices ####\n";
			matrix mtx, cof;
			cout << "Enter the dimension of your square matrix: \n";
			int size;
			cin >> size;
			setValuesOfMatrix(mtx, size, size);
			cofactoredMatrix(mtx, cof, size);
			cout << "The cofactored matrix of: \n";
			printMatrix(mtx, size, size);
			cout << "is\n";
			printMatrix(cof, size, size);
		}
		else if (choice == 8) {
			cout<<"\t\t\t#### Inverse of Matrices ####\n";
			matrix mtx, inverse;
			cout << "Enter the dimension of your square matrix: \n";
			int size;
			cin >> size;
			setValuesOfMatrix(mtx, size, size); 
			if (inv(mtx, inverse, size)) {
				cout << "The inverse of: \n";
				printMatrix(mtx, size, size);
				cout << "is \n";
				printMatrix(inverse, size, size);
			}
		}
		cout << "Do you want to continue with the program? Y / N.\n";
		cin >> cont; // Continuation condition

		cout << "*******************************************************\n";
		cout << " Thanks for using our program! We would love to hear \n";
		cout << "	your feedback at someMatrixLab@gmail.com.  \n";
		cout << " 			 MatrixLab 		               \n";
		cout << "			Version 2.0  		           \n";
		cout << "		  All rights reserved.		       \n";
		cout << "*******************************************************\n";
		system("pause");
		system("cls");
	}
	while (cont == 'Y' || cont == 'y');
	return 0;

}// program ends here
