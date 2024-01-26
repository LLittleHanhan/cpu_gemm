#include <immintrin.h>
void fn(double* a, double* b, double* c, int N) {
    for (int i = 0; i < N; i += 4)
        _mm256_store_pd(&c[i], _mm256_add_pd(_mm256_load_pd(&a[i]), _mm256_load_pd(&b[i])));
}
