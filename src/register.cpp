#define A(i, j) a[(i) * k + (j)]
#define B(i, j) b[(i) * n + (j)]
#define C(i, j) c[(i) * n + (j)]

void fn(double* a, double* b, double* c, int m, int n, int k) {
    for (int l = 0; l < k; l += 4)
        for (int i = 0; i < m; i++) {
            double reg0 = A(i, l);
            double reg1 = A(i, l + 1);
            double reg2 = A(i, l + 2);
            double reg3 = A(i, l + 3);
            for (int j = 0; j < n; j++) {
                C(i, j) += reg0 * B(l, j);
                C(i, j) += reg1 * B(l + 1, j);
                C(i, j) += reg2 * B(l + 2, j);
                C(i, j) += reg3 * B(l + 3, j);
            }
        }
}