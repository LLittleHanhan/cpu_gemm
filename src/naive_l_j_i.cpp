#define A(i, j) a[(i) * k + (j)]
#define B(i, j) b[(i) * n + (j)]
#define C(i, j) c[(i) * n + (j)]

void fn(double* a, double* b, double* c, int m, int n, int k) {
    for (int l = 0; l < k; l++)
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m; i++)
                C(i, j) += A(i, l) * B(l, j);
}