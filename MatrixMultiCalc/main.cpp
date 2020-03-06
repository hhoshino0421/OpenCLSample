#include <iostream>
#include "matrixcalc.h"

int main() {
    //std::cout << "Hello, World!" << std::endl;

    // 計算処理実行
    //execute_cacl();


    int n = 3;
    int m = 3;
    int **nums1;
    nums1 = (int **)malloc(sizeof(int *) * n); // ｎ行個分のアドレスを保持する領域を確保

    for(int i = 0; i < n; i++) {
        nums1[i] = (int *)malloc(sizeof(int) * m); // 1行分のデータを保持する領域を確保
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            nums1[i][j] = i * m + j; // 初期化
            if(j < m -1) {
                printf("%d,", nums1[i][j]);
            } else {
                printf("%d\n", nums1[i][j]);
            }
        }
    }

    // メモリ解放
    for(int i = 0; i < n; i++) {
        free(nums1[i]);
    }
    free(nums1);


    int length = 3;
    int ** a_matrix;
    int ** b_matrix;
    int ** c_matrix;

    a_matrix = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++) {
        a_matrix[i] = (int *)malloc(sizeof(int) * m);
    }

    b_matrix = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++) {
        b_matrix[i] = (int *)malloc(sizeof(int) * m);
    }

    //計算処理実行
    c_matrix = matrix_calc_square(a_matrix, b_matrix, length);



    //メモリ解放
    for(int i = 0; i < n; i++) {
        free(a_matrix[i]);
    }
    free(a_matrix);

    for(int i = 0; i < n; i++) {
        free(b_matrix[i]);
    }
    free(b_matrix);

    for(int i = 0; i < n; i++) {
        free(c_matrix[i]);
    }
    free(c_matrix);


    return 0;
}
