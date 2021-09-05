#include <iostream>
#include <vector>
#include <chrono>
#include "reader.cpp"

using namespace std;
using namespace std::chrono;

/* Add two matrices a and b and sets the result on a third s matrix. */
vector<vector<int>> addMatrices(vector<vector<int>> &a, vector<vector<int>> &b, size_t  mSize) {
    vector<int> ss(a.size(), 0);
    vector<vector<int>> s(ss.size(), ss);
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            s[i][j] = a[i][j] + b[i][j];
        }
    }
    return s;
}

/* Substract two matrices a and b and sets the result on a third s matrix. */
vector<vector<int>> subMatrices(vector<vector<int>> &a, vector<vector<int>> &b, size_t  mSize) {
    vector<int> ss(a.size(), 0);
    vector<vector<int>> s(ss.size(), ss);
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            s[i][j] = a[i][j] - b[i][j];
        }
    }
    return s;
}

/* Multiply two matrices */
void multiply(vector<vector<int>> &a, vector<vector<int>> &b, vector<vector<int>> &s, size_t n) {
    if (n <= 1) {
        s[0][0] = a[0][0] * b[0][0];
    } else {
        /* Get half of the current size */
        size_t half = n / 2;
        /* Create inner vector with half of the size */
        vector<int> inner(half, 0);
        /* Create new matrices */
        vector<vector<int>> A11(half, inner),
                            A12(half, inner),
                            A21(half, inner),
                            A22(half, inner),
                            B11(half, inner),
                            B12(half, inner),
                            B21(half, inner),
                            B22(half, inner),
                            P1(half, inner),
                            P2(half, inner),
                            P3(half, inner),
                            P4(half, inner),
                            P5(half, inner),
                            P6(half, inner),
                            P7(half, inner),
                            tempA(half, inner),
                            tempB(half, inner);
        /*Divide submatrices */
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                /* For A matrix */
                A11[i][j] = a[i][j];
                A12[i][j] = a[i][j + half];
                A21[i][j] = a[i + half][j];
                A22[i][j] = a[i + half][j + half];  
                /* For B matrix */
                B11[i][j] = b[i][j];
                B12[i][j] = b[i][j + half];
                B21[i][j] = b[i + half][j];
                B22[i][j] = b[i + half][j + half];
            }
        }
        /* Perform suboperations */
        /* P */
        vector<vector<int>> P1_1 = subMatrices(B12, B22, half);
        multiply(A11, P1_1, P1, half);
        vector<vector<int>> P2_1 = addMatrices(A11, A12, half);
        multiply(P2_1, B22, P2, half);
        vector<vector<int>> P3_1 = addMatrices(A21, A22, half);
        multiply(P3_1, B11, P3, half);
        vector<vector<int>> P4_1 = subMatrices(B21, B11, half);
        multiply(A22, P4_1, P4, half);
        vector<vector<int>> P5_1 = addMatrices(A11, A22, half);
        vector<vector<int>> P5_2 = addMatrices(B11, B22, half);
        multiply(P5_1, P5_2, P5, half);
        vector<vector<int>> P6_1 = subMatrices(A12, A22, half);
        vector<vector<int>> P6_2 = addMatrices(B21, B22, half);
        multiply(P6_1, P6_2, P6, half);
        vector<vector<int>> P7_1 = subMatrices(A11, A21, half);
        vector<vector<int>> P7_2 = addMatrices(B11, B12, half);
        multiply(P7_1, P7_2, P7, half);
        /* C */
        vector<vector<int>> C11_1 = addMatrices(P5, P4, half);
        vector<vector<int>> C11_2 = subMatrices(C11_1, P2, half);
        vector<vector<int>> C11 = addMatrices(C11_2, P6, half);
        vector<vector<int>> C12 = addMatrices(P1, P2, half);
        vector<vector<int>> C21 = addMatrices(P3, P4, half);
        vector<vector<int>> C22_1 = addMatrices(P1, P5, half);
        vector<vector<int>> C22_2 = subMatrices(C22_1, P3, half);
        vector<vector<int>> C22 = subMatrices(C22_2, P7, half);
        /* Regroup submatrices */
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                s[i][j] = C11[i][j];
                s[i][j + half] = C12[i][j];
                s[i + half][j] = C21[i][j];
                s[i + half][j + half] = C22[i][j];
            }
        }
    }
}

int main(int argc, char** argv) {
    /* ------------ FILE TOKENIZATION ------------ */
    /* Start measuring file reading runtime */
    auto r_start = high_resolution_clock::now();
    /* Read file and initialize matrices */
    vector<vector<int>> matA1 = initMatrixFromFile(argv[1]);
    vector<vector<int>> matB1 = initMatrixFromFile(argv[2]);
    /* Initialize result matrix */
    size_t curSize = matA1.size();
    vector<int> init(curSize, 0);
    vector<vector<int>> matS1(curSize, init);
    /* End file reading runtime measurement */
    auto r_stop = high_resolution_clock::now();
    auto r_runtime = duration_cast<microseconds>(r_stop - r_start);
    auto r_secs = r_runtime.count() / 10e5;
    /* ------------ MATRIX MULTIPLICATION ------------ */
    /* Start measuring multiplication runtime */
    auto m_start = high_resolution_clock::now();
    /* Start multiplying */
    multiply(matA1, matB1, matS1, curSize);
    /* End multiplication runtime measurement */
    auto m_stop = high_resolution_clock::now();
    auto m_runtime = duration_cast<microseconds>(m_stop - m_start);
    auto m_secs = m_runtime.count() / 10e5;
    /* Print solution */
    printMatrix(matS1);
    cout << "File tokenized in: " << r_secs << "seconds" << endl;
    cout << "Solved in: " << m_secs << "seconds" << endl;
    /* Write solution to file */
    string solPath = "../Matrices/solution.txt";
    printMatrix(matS1, solPath);
    cout << "File \"" << solPath << "\" has been updated." << endl; 
}