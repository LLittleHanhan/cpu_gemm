#include <cblas.h>

void fn(double* a, double* b, double* c, int m, int n, int k) {
    openblas_set_num_threads(1);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1, a, k, b, n, 1, c, n);
}