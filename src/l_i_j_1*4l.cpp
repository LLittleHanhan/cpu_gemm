#define A(i, j) a[(i) * k + (j)]
#define B(i, j) b[(i) * n + (j)]
#define C(i, j) c[(i) * n + (j)]

void fn(double* a, double* b, double* c, int m, int n, int k) {
    for (int l = 0; l < k; l += 4)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                C(i, j) += A(i, l) * B(l, j);
                C(i, j) += A(i, l + 1) * B(l + 1, j);
                C(i, j) += A(i, l + 2) * B(l + 2, j);
                C(i, j) += A(i, l + 3) * B(l + 3, j);
            }
}