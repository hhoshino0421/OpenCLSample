#include <iostream>
#include <time.h>
#include <stdio.h>

int main() {

    const int   N = 1024;
    int         i, j, k;

    float **a   = new float*[N];
    float **b   = new float*[N];
    float **c   = new float*[N];

    for (i = 0; i < N; i++) {
        a[i] = new float[N];
        b[i] = new float[N];
        c[i] = new float[N];
    }

    for (i = 0; i < N; i++) {
        for (j=0;j<N;j++) {
            a[i][j] = (float)(int)(rand()/4096);
            b[i][j] = (float)(int)(rand()/4096);
            c[i][j] = 0.0f;
        }
    }

    clock_t startTime = clock();

    for (i = 0;i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    clock_t stopTime = clock();

    float etime = (float)(stopTime - startTime) / CLOCKS_PER_SEC;

    printf("elapsed time= %15.7f sec\n", etime);

    for (i = 0; i < N; i++) {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    return 0;
}
