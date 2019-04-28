//
// Created by Hoshino Hitoshi on 2019-04-28.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "Const.h"

/*
 * 逐次処理方式関数
 */
int LinearProcess() {

    //使用変数定義
    float * x_Array;
    float * y_Array;
    float * dist_Array;
    //処理時間計測用
    clock_t     start_clock_time, end_clock_time;
    double      process_time;

    //処理時間計測開始
    start_clock_time = clock();


    //データ領域作成
    x_Array     = (float *)malloc(sizeof(float) * ARRAY_SIZE);
    y_Array     = (float *)malloc(sizeof(float) * ARRAY_SIZE);
    dist_Array  = (float *)malloc(sizeof(float) * ARRAY_SIZE * ARRAY_SIZE);

    if (x_Array == NULL || y_Array == NULL || dist_Array == NULL) {
        printf("Memory Allocate Error\n");
        //異常終了
        return -1;
    }

    //乱数のシードを設定
    srand((unsigned int)time(NULL));

    //計算用データ作成処理
    for (int i = 0; i < ARRAY_SIZE; i++) {
        *(x_Array + i) =  (float)rand() / SALT_DATA;
        *(y_Array + i) =  (float)rand() / SALT_DATA;
    }

    //計算処理
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            dist_Array[j + i * ARRAY_SIZE] = sqrt(pow(x_Array[i] - x_Array[j], 2) + pow(y_Array[i] - y_Array[j], 2));

        }
    }

    /*
    //計算結果確認処理(デバッグ用)
    for (int i=0;i<ARRAY_SIZE;i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            printf("dist(%d,%d):%lf\n", i, j, *(dist_Array + i + j));
        }


    }
    */

    //後始末
    free(x_Array);
    free(y_Array);
    free(dist_Array);


    //処理時間表示
    end_clock_time = clock();
    process_time = (double)(end_clock_time - start_clock_time) / CLOCKS_PER_SEC;

    printf("LinearProcess ProcessTime:%f\n", process_time);

    //正常終了
    return 0;

}
