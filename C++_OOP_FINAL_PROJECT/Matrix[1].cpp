#include <iostream>
#include <iomanip>
using namespace std;

// Abstract class for matrix operations
class MatrixOp {
public:
    virtual double** execute(double** A, double** B, int r1, int c1, int r2, int c2) = 0;
    virtual ~MatrixOp() {}
};

// Utility to allocate a matrix
double** allocateMatrix(int rows, int cols) {
    double** mat = new double*[rows];
    for (int i = 0; i < rows; i++) {
        mat[i] = new double[cols];
    }
    return mat;
}

// Utility to free a matrix
void freeMatrix(double** mat, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

// Utility to print a matrix
void printMatrix(double** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(10) << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// ADDITION
class AddMatrixOp : public MatrixOp {
public:
    double** execute(double** A, double** B, int r1, int c1, int r2, int c2) {
        if (r1 != r2 || c1 != c2) {
            cout << "Matrix dimensions must match for addition.\n";
            return NULL;
        }
        double** result = allocateMatrix(r1, c1);
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                *(*(result + i) + j) = *(*(A + i) + j) + *(*(B + i) + j);
            }
        }
        return result;
    }
};

// MULTIPLICATION
class MulMatrixOp : public MatrixOp {
public:
    double** execute(double** A, double** B, int r1, int c1, int r2, int c2) {
        if (c1 != r2) {
            cout << "Matrix A columns must match Matrix B rows for multiplication.\n";
            return NULL;
        }
        double** result = allocateMatrix(r1, c2);
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                *(*(result + i) + j) = 0;
                for (int k = 0; k < c1; k++) {
                    *(*(result + i) + j) += *(*(A + i) + k) * *(*(B + k) + j);
                }
            }
        }
        return result;
    }
};

// INVERSE (for 2x2 matrix only)
class InverseMatrixOp : public MatrixOp {
public:
    double** execute(double** A, double** B, int r1, int c1, int r2, int c2) {
        if (r1 != 2 || c1 != 2) {
            cout << "Inverse implemented for 2x2 matrix only.\n";
            return NULL;
        }

        double det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
        if (det == 0) {
            cout << "Matrix is singular and cannot be inverted.\n";
            return NULL;
        }

        double** inv = allocateMatrix(2, 2);
        inv[0][0] = A[1][1] / det;
        inv[0][1] = -A[0][1] / det;
        inv[1][0] = -A[1][0] / det;
        inv[1][1] = A[0][0] / det;

        return inv;
    }
};

// MAIN
int main() {
    // Example matrices
    int r1 = 2, c1 = 2;
    int r2 = 2, c2 = 2;

    double** A = allocateMatrix(r1, c1);
    double** B = allocateMatrix(r2, c2);

    // Initialize A
    A[0][0] = 4; A[0][1] = 7;
    A[1][0] = 2; A[1][1] = 6;

    // Initialize B
    B[0][0] = 1; B[0][1] = 0;
    B[1][0] = 5; B[1][1] = 1;

    cout << "Matrix A:\n";
    printMatrix(A, r1, c1);

    cout << "\nMatrix B:\n";
    printMatrix(B, r2, c2);

    // Create operations
    MatrixOp** ops = new MatrixOp*[3];
    ops[0] = new AddMatrixOp();
    ops[1] = new MulMatrixOp();
    ops[2] = new InverseMatrixOp();

    cout << "\n--- Addition A + B ---\n";
    double** addResult = ops[0]->execute(A, B, r1, c1, r2, c2);
    if (addResult) {
        printMatrix(addResult, r1, c1);
        freeMatrix(addResult, r1);
    }

    cout << "\n--- Multiplication A * B ---\n";
    double** mulResult = ops[1]->execute(A, B, r1, c1, r2, c2);
    if (mulResult) {
        printMatrix(mulResult, r1, c2);
        freeMatrix(mulResult, r1);
    }

    cout << "\n--- Inverse of A ---\n";
    double** invResult = ops[2]->execute(A, NULL, r1, c1, 0, 0);
    if (invResult) {
        printMatrix(invResult, 2, 2);
        freeMatrix(invResult, 2);
    }

    // Cleanup
    for (int i = 0; i < 3; i++) {
        delete ops[i];
    }
    delete[] ops;
    freeMatrix(A, r1);
    freeMatrix(B, r2);

    return 0;
}

