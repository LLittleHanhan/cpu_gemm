#define A(i, j) a[(i) * k + (j)]
#define B(i, j) b[(i) * n + (j)]
#define C(i, j) c[(i) * n + (j)]

void fn(double* a, double* b, double* c, int m, int n, int k) {
    for (int l = 0; l < k; l++)
        for (int i = 0; i < m; i += 4)
            for (int j = 0; j < n; j++) {
                C(i, j) += A(i, l) * B(l, j);
                C(i + 1, j) += A(i + 1, l) * B(l, j);
                C(i + 2, j) += A(i + 2, l) * B(l, j);
                C(i + 3, j) += A(i + 3, l) * B(l, j);
            }
}