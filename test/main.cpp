#include <sys/time.h>
#include <time.h>
#include <iostream>
#define abs(x) ((x) < 0.0 ? -(x) : (x))

using namespace std;

static double gtod_ref_time_sec = 0.0;
/* Adapted from the bl2_clock() routine in the BLIS library */
double dclock() {
    double the_time, norm_sec;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    if (gtod_ref_time_sec == 0.0)
        gtod_ref_time_sec = (double)tv.tv_sec;
    norm_sec = (double)tv.tv_sec - gtod_ref_time_sec;
    the_time = norm_sec + tv.tv_usec * 1.0e-6;
    return the_time;
}

const int rep = 1;
const int N = 1000000;
float* a;
float* b;
float* c;
float* ref;

void fn(float* a, float* b, float* c, int N);

int main() {
    a = new ((align_val_t)32) float[N];
    b = new ((align_val_t)32) float[N];
    c = new ((align_val_t)32) float[N]{0};
    ref = new ((align_val_t)32) float[N]{0};

    for (int i = 0; i < N; i++) {
        a[i] = 2.0 * drand48() - 1.0;
        b[i] = 2.0 * drand48() - 1.0;
    }

    double dbest = 0.0;
    for (int i = 0; i < rep; i++) {
        double dtime = dclock();
        // cal
        fn(a, b, c, N);

        dtime = dclock() - dtime;
        if (i == 0)
            dbest = dtime;
        else
            dbest = (dtime < dbest ? dtime : dbest);
    }

    double gflops = N * 1.0e-09;
    std::cout << dbest << " " << endl;

    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}
