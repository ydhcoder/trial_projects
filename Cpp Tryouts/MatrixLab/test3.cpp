#include <iostream>
#include <math.h>

using namespace std;

typedef double matrix[10][10];

void cofactorOf(matrix, matrix, int);
void setValuesOfMatrix(matrix, int, int);
double deter(matrix, int);
void printMatrix(matrix, int, int);

double deter(matrix a, int size){
	double det = 0;
	matrix subMtx;
	if (size = 1) 
		return a[0][0];
	else if (size = 2) 
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

// Creates a cofactor of a matrix
void cofactorOf(matrix a, matrix cof, int size) {
    matrix subMtx;
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			int subi = 0;
			for (int i = 1; i < size; i++) {
				int subj = 0;
				for(int j = 0; j < size; j++) {
					if (j == y && i == x)
						continue;
					subMtx[subi][subj] = a[i][j];
					subj++;
				}
				subi++;
			}
            cof[x][y] = pow(-1, x + y) * a[x][y] * deter(subMtx, size - 1);
		}
	}
}

void setValuesOfMatrix(matrix mtx, int row, int col) {
	cout << "Enter "<< row * col << " values for the " << row << " X " << col << " matrix.\n";
	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++)
			cin >> mtx[i][j];
		cout << endl;
	}
}

void printMatrix(matrix mtx, int row, int col) {
	for (int i = 0; i < row; i++) { 
		cout << "\t[";
		for (int j = 0; j < col; j++)
			cout<< mtx[i][j] << " ";
		cout << "]";
		cout << endl;
	}
}

int main() {
    matrix arr, cofactor;
    setValuesOfMatrix(arr, 3, 3);
    printMatrix(arr, 3, 3);
    cofactorOf(arr, cofactor, 3);
    printMatrix(cofactor, 3, 3);
    return 0;

}
