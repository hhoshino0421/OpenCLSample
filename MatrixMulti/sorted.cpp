//
// Created by 星野斉 on 2020/04/04.
//

#include <time.h>
#include <stdio.h>
#include <cstdlib>

void sorted_calc(int N) {

    int         i, j, k;

    clock_t totalStartTime = clock();
    clock_t initStartTime = clock();

    float **a   = new float*[N];
    float **b   = new float*[N];
    float **c   = new float*[N];
    float **tb  = new float*[N];

    for (i = 0; i < N; i++) {
        a[i] = new float[N];
        b[i] = new float[N];
        c[i] = new float[N];
        tb[i] = new float[N];
    }

    for (i = 0; i < N; i++) {
        for (j=0;j<N;j++) {
            a[i][j] = (float)(int)(rand() / 4096);
            b[i][j] = (float)(int)(rand() / 4096);
            c[i][j] = 0.0f;
        }
    }

    clock_t initStopTime = clock();

    clock_t sortStartTime = clock();

    // sort
    for (j = 0; i < N; j++) {
        for (k = 0; k < N; k++) {
            tb[j][k] = b[k][j];
        }
    }

    clock_t sortStopTime = clock();

    clock_t calcStartTime = clock();

    for (i = 0;i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                c[i][j] += a[i][k] * tb[j][k];
            }
        }
    }

    clock_t calcStopTime = clock();

    float etime = (float)(calcStopTime - calcStartTime) / CLOCKS_PER_SEC;

    clock_t deleteStartTime = clock();

    for (i = 0; i < N; i++) {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
        delete[] tb[i];
    }

    clock_t deleteStopTime = clock();

    float initTime      = (float)(initStopTime - initStartTime)     / CLOCKS_PER_SEC;
    float sortTime      = (float)(sortStopTime - sortStartTime)     / CLOCKS_PER_SEC;
    float calcTime      = (float)(calcStopTime - calcStartTime)     / CLOCKS_PER_SEC;
    float deleteTime    = (float)(deleteStopTime - deleteStartTime) / CLOCKS_PER_SEC;

    clock_t totalStopTime  = clock();
    float totalTime     = (float)(totalStopTime - totalStartTime)   / CLOCKS_PER_SEC;

    printf("Sort Version time report start*********\n");
    printf("init time   = %15.7f sec\n", initTime);
    printf("sort time   = %15.7f sec\n", sortTime);
    printf("calc time   = %15.7f sec\n", calcTime);
    printf("delete time = %15.7f sec\n", deleteTime);
    printf("total time  = %15.7f sec\n", totalTime);
    printf("Sort Version time report end*********\n\n");
    //printf("￿ \n");

}
