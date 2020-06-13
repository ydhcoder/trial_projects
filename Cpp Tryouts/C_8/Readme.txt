********************************************************************************************************
                                        MatrixLab
Program description: Matrix Lab is a program designed to facilitate matrix manipulation. Manipulating 
        Matrices starts from simple operations such as adding, subtracting, multiplying and transposing. 
        Furthermore, for a slightly advanced operations such as finding adjoint, cofactor and inverse of 
        Matrices, this program simplifies the tiresome task of finding these solutions in a friendly and
        interactive way.
               
                     Name                                 ID
Designed by:    Yeabsra Debebe  -------------------     1244/10
                Yeabsera Erdaw  -------------------     1222/10
                Yemiserach Nigatu  ----------------     1249/10
                Wongel Lakew    -------------------     1217/10
                Wondimu Haile   -------------------     1216/10
                Yeshiwork Solomon   ---------------     1253/10

Remark: Our program, Matrix Lab, works upto a matrix size of 5 x 5. This is done to optimize memory and 
limit the operation range, since further size of matrices puts a lot of pressure on the user to input 
more values than necessary. In our program, our user is expected to input a maximum of 25 values. But if 
the case is necessary to operate with more than a 5 x 5 size matrix, one can change the variable N in the
source code to any value they want. Unless this is done, one can still operate with the program with a 
memory overflow and bugs popping up. 

********************************************************************************************************
Output Templates of the Matrix Lab Program
********************************************************************************************************

                                                Welcome to Matrix Lab!
                                        #####################################
Here are the possible set of tools you can use to manipulate Matrices.
1. Add Matrices
2. Subtract Matrices
3. Multiply Matrices
4. Transpose Matrices
5. Determinant of Matrices
6. Adjoint of Matrices
7. Cofactor Matrix of Matrices
8. Inverse of Matrices
Choose one ...1
Press any key to continue . . .
========================================================================================================
                        #### Addition of Matrices ####
Please insert the number of rows and columns respectively you operate with respectively.3
4
Now insert the first matrix:
Enter 12 values for the 3 X 4 matrix.
2
33
4
5

3
4
5
3

4
5

4
3

Then insert values for the second matrix:
Enter 12 values for the 3 X 4 matrix.
4
3
4
56

7
8
9
6

5
6
6
5

        [2 33 4 5 ]
        [3 4 5 3 ]
        [4 5 4 3 ]
+
        [4 3 4 56 ]
        [7 8 9 6 ]
        [5 6 6 5 ]
=
        [6 36 8 61 ]
        [10 12 14 9 ]
        [9 11 10 8 ]
Do you want to continue adding? Insert + for Yes and any other key for NO!
0
Do you want to continue with the program? Y / N.
Y
Press any key to continue . . .
========================================================================================================
========================================================================================================
                                                Welcome to Matrix Lab!
                                        #####################################
Here are the possible set of tools you can use to manipulate Matrices.
1. Add Matrices
2. Subtract Matrices
3. Multiply Matrices
4. Transpose Matrices
5. Determinant of Matrices
6. Adjoint of Matrices
7. Cofactor Matrix of Matrices
8. Inverse of Matrices
Choose one ...2
Press any key to continue . . .
========================================================================================================
                        #### Subtraction of Matrices ####
Please insert the number of rows and columns respectively you operate with respectively.2
4
Now insert the first matrix:
Enter 8 values for the 2 X 4 matrix.
2
3
4
6

7
8
5
7

Then insert values for the second matrix:
Enter 8 values for the 2 X 4 matrix.
8
9
0
5

6
4
3
4

        [2 3 4 6 ]
        [7 8 5 7 ]
-
        [8 9 0 5 ]
        [6 4 3 4 ]
=
        [-6 -6 4 1 ]
        [1 4 2 3 ]
Do you want to continue subtracting? Insert - for Yes and any other key for NO!
n
Do you want to continue with the program? Y / N.
Y
Press any key to continue . . .
========================================================================================================
========================================================================================================
                                                Welcome to Matrix Lab!
                                        #####################################
Here are the possible set of tools you can use to manipulate Matrices.
1. Add Matrices
2. Subtract Matrices
3. Multiply Matrices
4. Transpose Matrices
5. Determinant of Matrices
6. Adjoint of Matrices
7. Cofactor Matrix of Matrices
8. Inverse of Matrices
Choose one ...3
Press any key to continue . . .
========================================================================================================
                        #### Multiplication of a Matrices ####
Please insert the number of rows and columns respectively for the first matrix: 3
4
Now insert the number of rows and columns respectively for the second matrix: 4
3

Now insert values to the first matrix:
Enter 12 values for the 3 X 4 matrix.
2
3
4
5

3
2
3
4

5
3

4
3

Then insert values for the second matrix:
Enter 12 values for the 4 X 3 matrix.
4
5
6

77
8
6

5
4
5

6
4
5

        [2 3 4 5 ]
        [3 2 3 4 ]
        [5 3 4 3 ]
X
        [4 5 6 ]
        [77 8 6 ]
        [5 4 5 ]
        [6 4 5 ]
=
        [283 64 79 ]
        [206 63 67 ]
        [298 88 93 ] 
Do you want to continue with the program? Y / N.
Y
Press any key to continue . . .
========================================================================================================
========================================================================================================
                                                Welcome to Matrix Lab!
                                        #####################################
Here are the possible set of tools you can use to manipulate Matrices.
1. Add Matrices
2. Subtract Matrices
3. Multiply Matrices
4. Transpose Matrices
5. Determinant of Matrices
6. Adjoint of Matrices
7. Cofactor Matrix of Matrices
8. Inverse of Matrices
Choose one ...4
Press any key to continue . . .
========================================================================================================
                                 #### Transpose of Matrices ####
Please insert the number of rows and columns respectively for the your matrix:
1
4
Now insert values to the matrix to be transposed:
Enter 4 values for the 1 X 4 matrix.
4
5
6
7

The transpose of:
        [4 5 6 7 ]
is
        [4 ]
        [5 ]
        [6 ]
        [7 ]
Do you want to continue with the program? Y / N.
Y     
Press any key to continue . . .          
========================================================================================================
========================================================================================================
                                                Welcome to Matrix Lab!
                                        #####################################
Here are the possible set of tools you can use to manipulate Matrices.
1. Add Matrices
2. Subtract Matrices
3. Multiply Matrices
4. Transpose Matrices
5. Determinant of Matrices
6. Adjoint of Matrices
7. Cofactor Matrix of Matrices
8. Inverse of Matrices
Choose one ...5
Press any key to continue . . .
========================================================================================================
                        #### Determinant of Matrices ####
Enter the dimension of your square matrix:
5
Enter 25 values for the 5 X 5 matrix.
3
4
5
6
4

3
4
5
3
6

8
6
4
5
6

4
5
3
4
5

6
7
8
9
6

The determinant:
        |3 4 5 6 4 |
        |3 4 5 3 6 |
        |8 6 4 5 6 |
        |4 5 3 4 5 |
        |6 7 8 9 6 |
equals 180
Do you want to continue with the program? Y / N.
Y
Press any key to continue . . .
========================================================================================================
========================================================================================================
                                                Welcome to Matrix Lab!
                                        #####################################
Here are the possible set of tools you can use to manipulate Matrices.
1. Add Matrices
2. Subtract Matrices
3. Multiply Matrices
4. Transpose Matrices
5. Determinant of Matrices
6. Adjoint of Matrices
7. Cofactor Matrix of Matrices
8. Inverse of Matrices
Choose one ...6 
Press any key to continue . . .
========================================================================================================
                        #### Adjoint of Matrices ####
Enter the dimension of your square matrix:

3
Enter 9 values for the 3 X 3 matrix.
3
4
5

6
7
9

4
5
7

The adjoint of:
        [3 4 5 ]
        [6 7 9 ]
        [4 5 7 ]
is
        [4 -3 1 ]
        [-6 1 3 ]
        [2 1 -3 ]
Do you want to continue with the program? Y / N.
Y    
Press any key to continue . . .           
========================================================================================================
========================================================================================================
                                                Welcome to Matrix Lab!
                                        #####################################
Here are the possible set of tools you can use to manipulate Matrices.
1. Add Matrices
2. Subtract Matrices
3. Multiply Matrices
4. Transpose Matrices
5. Determinant of Matrices
6. Adjoint of Matrices
7. Cofactor Matrix of Matrices
8. Inverse of Matrices
Choose one ...7 
Press any key to continue . . .
========================================================================================================
                        #### Adjoint of Matrices ####
Enter the dimension of your square matrix:

3
Enter 9 values for the 3 X 3 matrix.
3
4
5

6
7
9

4
5
7

The adjoint of:
        [3 4 5 ]
        [6 7 9 ]
        [4 5 7 ]
is
        [4 -3 1 ]
        [-6 1 3 ]
        [2 1 -3 ]
Do you want to continue with the program? Y / N.
Y    
Press any key to continue . . .           
========================================================================================================
========================================================================================================
                                                Welcome to Matrix Lab!
                                        #####################################
Here are the possible set of tools you can use to manipulate Matrices.
1. Add Matrices
2. Subtract Matrices
3. Multiply Matrices
4. Transpose Matrices
5. Determinant of Matrices
6. Adjoint of Matrices
7. Cofactor Matrix of Matrices
8. Inverse of Matrices
Choose one ...7 
Press any key to continue . . .
========================================================================================================
                        #### Cofactor Matrix of Matrices ####
Enter the dimension of your square matrix:
4
Enter 16 values for the 4 X 4 matrix.
2
3
4
5

6

3
4
4

5
6
3
4

5
3
4
5

The cofactored matrix of:
        [2 3 4 5 ]
        [6 3 4 4 ]
        [5 6 3 4 ]
        [5 3 4 5 ]
is
        [-15 6 33 -15 ]
        [-0 3 54 -45 ]
        [0 12 -9 -0 ]
        [15 -18 -69 60 ]
Do you want to continue with the program? Y / N.
Y  
Press any key to continue . . .
========================================================================================================
========================================================================================================
                                                Welcome to Matrix Lab!
                                        #####################################
Here are the possible set of tools you can use to manipulate Matrices.
1. Add Matrices
2. Subtract Matrices
3. Multiply Matrices
4. Transpose Matrices
5. Determinant of Matrices
6. Adjoint of Matrices
7. Cofactor Matrix of Matrices
8. Inverse of Matrices
Choose one ...8
Press any key to continue . . .
========================================================================================================
                        #### Inverse of Matrices ####
Enter the dimension of your square matrix:
2
Enter 4 values for the 2 X 2 matrix.
3
4

5
6

The inverse of:
        [3 4 ]
        [5 6 ]
is
        [-3 2 ]
        [2.5 -1.5 ]
Do you want to continue with the program? Y / N.
N
*******************************************************
 Thanks for using our program! We would love to hear
        your feedback at someMatrixLab@gmail.com.
                         MatrixLab
                        Version 2.0
                  All rights reserved.
*******************************************************
Press any key to continue . . .
========================================================================================================

*********************
End of program output
*********************