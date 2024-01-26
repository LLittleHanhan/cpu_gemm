#include <iostream>
using namespace std;

const int rep = 3;
double *a, *b, *c, *ref, *cold;
int m, n, k;

void copyMatrix(double* a, double* b, int size);  // a=b
void randomMatrix(double* a, int m, int n);
void printMatrix(double* a, int m, int n);
double compareMatrix(double* a, double* b, int m, int n);
void sfn(double* a, double* b, double* c, int m, int n, int k);

double dclock();
void fn(double* a, double* b, double* c, int m, int n, int k);

int main() {
    for (int N = 32; N <= 1440; N += 32) {
        m = n = k = N;
        a = new double[m * k];
        b = new double[k * n];
        c = new double[m * n];
        ref = new double[m * n];
        cold = new double[m * n];
        randomMatrix(a, m, k);
        randomMatrix(b, k, n);
        randomMatrix(cold, m, n);

        double dbest = 0;
        double gflops = 2.0 * m * n * k * 1.0e-09;
        for (int i = 0; i < rep; i++) {
            copyMatrix(c, cold, m * n);
            double dtime = dclock();
            // cal
            fn(a, b, c, m, n, k);
            dtime = dclock() - dtime;
            if (i == 0)
                dbest = dtime;
            else
                dbest = (dtime < dbest ? dtime : dbest);
        }
        // compare
        copyMatrix(ref, cold, m * n);
        sfn(a, b, ref, m, n, k);
        cout << N << " " << gflops / dbest << " " << compareMatrix(c, ref, m, n) << endl;

        delete[] a;
        delete[] b;
        delete[] c;
        delete[] cold;
        delete[] ref;
    }
    return 0;
}
