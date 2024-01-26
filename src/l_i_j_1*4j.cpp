#define A(i, j) a[(i) * k + (j)]
#define B(i, j) b[(i) * n + (j)]
#define C(i, j) c[(i) * n + (j)]

void fn(double* a, double* b, double* c, int m, int n, int k) {
    for (int l = 0; l < k; l++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j += 4) {
                C(i, j) += A(i, l) * B(l, j);
                C(i, j + 1) += A(i, l) * B(l, j + 1);
                C(i, j + 2) += A(i, l) * B(l, j + 2);
                C(i, j + 3) += A(i, l) * B(l, j + 3);
            }
}