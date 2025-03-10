#include <iostream>
#include <cmath> // ƒл€ функции fabs
#include <fstream>

using namespace std;

const int MAX_SIZE = 10;

void printMatrix(int n, double matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void gaussElimination(int n, double matrix[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], double x[MAX_SIZE]) {
    for (int i = 0; i < n; ++i) {
        for (int k = i + 1; k < n; ++k) {
            double factor = matrix[k][i] / matrix[i][i];
            b[k] -= factor * b[i]; // дл€ бокового вектора 
            for (int j = i; j < n; ++j) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i] / matrix[i][i];
        for (int k = i - 1; k >= 0; --k) {
            b[k] -= matrix[k][i] * x[i];
        }
    }
}

int main() {
    int n = 3;

    double A[MAX_SIZE][MAX_SIZE];
    double b[MAX_SIZE];
    double x[MAX_SIZE];

    ifstream inputFile("input.txt");
    inputFile >> n; // оператор >> считывает данные из файла до тех пор, пока не встретит пробел, табул€цию или перевод строки.

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> A[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        inputFile >> b[i];
    }

    inputFile.close();

    gaussElimination(n, A, b, x);

    ofstream outputFile("output.txt");

    outputFile << "Solved system:" << endl;
    for (int i = 0; i < n; ++i) {
        outputFile << "x" << i + 1 << "=" << x[i] << endl;
    }

    outputFile.close();

    return 0;
}