// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to read a matrix
void readMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";

            if (!(cin >> matrix[i][j]))
            {
                cout << "That is not a number." << endl;
                exit(0);
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Part A - Transpose
void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transpose[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:\n";
    displayMatrix(transpose, cols, rows);
}

// Part B - Add two matrices
void addMatrices(int matrix1[10][10], int matrix2[10][10], int rows, int cols)
{
    int sum[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    cout << "\nSum of Matrices:\n";
    displayMatrix(sum, rows, cols);
}

// Part C - Multiply two matrices
void multiplyMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10],
                      int rows1, int cols1, int cols2)
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    cout << "\nProduct of Matrices:\n";
    displayMatrix(result, rows1, cols2);
}

int main()
{
    int choice;

    cout << "Matrix Operations\n";
    cout << "1. Transpose Matrix\n";
    cout << "2. Add Two Matrices\n";
    cout << "3. Multiply Two Matrices\n";
    cout << "Enter your choice: ";

    if (!(cin >> choice))
    {
        cout << "That is not a number." << endl;
        return 0;
    }

    if (choice == 1)
    {
        int rows, cols;
        int matrix[10][10];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10)
        {
            cout << "Invalid matrix size." << endl;
            return 0;
        }

        readMatrix(matrix, rows, cols);

        cout << "\nOriginal Matrix:\n";
        displayMatrix(matrix, rows, cols);

        transposeMatrix(matrix, rows, cols);
    }
    else if (choice == 2)
    {
        int rows, cols;
        int matrix1[10][10], matrix2[10][10];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10)
        {
            cout << "Invalid matrix size." << endl;
            return 0;
        }

        cout << "\nEnter first matrix:\n";
        readMatrix(matrix1, rows, cols);

        cout << "\nEnter second matrix:\n";
        readMatrix(matrix2, rows, cols);

        addMatrices(matrix1, matrix2, rows, cols);
    }
    else if (choice == 3)
    {
        int rows1, cols1, rows2, cols2;
        int matrix1[10][10], matrix2[10][10], result[10][10];

        cout << "Enter rows for Matrix A: ";
        cin >> rows1;
        cout << "Enter columns for Matrix A: ";
        cin >> cols1;

        cout << "Enter rows for Matrix B: ";
        cin >> rows2;
        cout << "Enter columns for Matrix B: ";
        cin >> cols2;

        if (rows1 <= 0 || cols1 <= 0 || rows2 <= 0 || cols2 <= 0 ||
            rows1 > 10 || cols1 > 10 || rows2 > 10 || cols2 > 10)
        {
            cout << "Invalid matrix size." << endl;
            return 0;
        }

        if (cols1 != rows2)
        {
            cout << "Matrix multiplication is not possible." << endl;
            return 0;
        }

        cout << "\nEnter Matrix A:\n";
        readMatrix(matrix1, rows1, cols1);

        cout << "\nEnter Matrix B:\n";
        readMatrix(matrix2, rows2, cols2);

        multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
