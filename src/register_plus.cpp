#define A(i, j) a[(i) * k + (j)]
#define B(i, j) b[(i) * n + (j)]
#define C(i, j) c[(i) * n + (j)]

void fn(double* a, double* b, double* c, int m, int n, int k) {
    double *pb0, *pb1, *pb2, *pb3;
    double reg0, reg1, reg2, reg3;
    double regc;
    for (int l = 0; l < k; l += 4) {
        for (int i = 0; i < m; i++) {
            reg0 = A(i, l);
            reg1 = A(i, l + 1);
            reg2 = A(i, l + 2);
            reg3 = A(i, l + 3);

            pb0 = &B(l, 0);
            pb1 = &B(l + 1, 0);
            pb2 = &B(l + 2, 0);
            pb3 = &B(l + 3, 0);
            for (int j = 0; j < n; j++) {
                regc = C(i, j);
                regc += reg0 * *pb0++;
                regc += reg1 * *pb1++;
                regc += reg2 * *pb2++;
                regc += reg3 * *pb3++;
                C(i, j) = regc;
            }
        }
    }
}