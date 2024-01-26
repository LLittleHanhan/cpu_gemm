#include <stdlib.h>
#include <iostream>
#define abs(x) ((x) < 0.0 ? -(x) : (x))

using namespace std;

void copyMatrix(double* a, double* b, int size) {
    for (int i = 0; i < size; i++)
        a[i] = b[i];
}

void randomMatrix(double* a, int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i * n + j] = 2.0 * drand48() - 1.0;
}

void printMatrix(double* a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i * n + j] << " ";
        }
        cout << endl;
    }
}

double compareMatrix(double* a, double* b, int m, int n) {
    double diff = 0.0;
    double max_diff = 0.0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            diff = abs(a[i * n + j] - b[i * n + j]);
            max_diff = (diff > max_diff ? diff : max_diff);
        }
    }
    return max_diff;
}

void sfn(double* a, double* b, double* c, int m, int n, int k) {
    for (int l = 0; l < k; l++)
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m; i++)
                c[i * n + j] += a[i * k + l] * b[l * n + j];
}