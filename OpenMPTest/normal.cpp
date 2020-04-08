//
// Created by 星野斉 on 2020/04/04.
//

#include <time.h>
#include <stdio.h>
#include <cstdlib>

#include <omp.h>

void normal_calc(int N) {

    int         i, j, k;

    clock_t totalStartTime  = clock();
    clock_t initStartTime   = clock();

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

    clock_t initStopTime   = clock();

    clock_t calcStartTime = clock();

    #pragma omp parallel for
    for (i = 0;i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    clock_t calcStopTime = clock();

    clock_t deleteStartTime = clock();

    for (i = 0; i < N; i++) {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    clock_t deleteStopTime = clock();


    float initTime = (float)(initStopTime - initStartTime) / CLOCKS_PER_SEC;
    float calcTime = (float)(calcStopTime - calcStartTime) / CLOCKS_PER_SEC;
    float deleteTime = (float)(deleteStopTime - deleteStartTime) / CLOCKS_PER_SEC;

    clock_t totalStopTime  = clock();
    float totalTime = (float)(totalStopTime - totalStartTime) / CLOCKS_PER_SEC;

    printf("Normal Version time report start*********\n");
    printf("init time   = %15.7f sec\n", initTime);
    printf("calc time   = %15.7f sec\n", calcTime);
    printf("delete time = %15.7f sec\n", deleteTime);
    printf("total time  = %15.7f sec\n", totalTime);
    printf("Normal Version time report end*********\n\n");
    //printf(" ￿\n");

}