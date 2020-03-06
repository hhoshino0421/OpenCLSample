//
// Created by 星野斉 on 2020/03/06.
//

#include "matrixcalc.h"
#include <stdio.h>

void execute_cacl() {

    //行列変数生成
    //行列A
    int a_matrix[2][2];
    a_matrix[0][0] = 1;
    a_matrix[0][1] = 2;
    a_matrix[1][0] = 3;
    a_matrix[1][1] = 4;

    //行列B
    int b_matrix[2][2];
    b_matrix[0][0] = 5;
    b_matrix[0][1] = 6;
    b_matrix[1][0] = 7;
    b_matrix[1][1] = 8;

    //for debug
    printf("a matrix\n");
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++) {
            printf("%d ",a_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("b matrix\n");
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++) {
            printf("%d ",b_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //計算結果
    int c_matrix[2][2];

    c_matrix[0][0] = a_matrix[0][0] * b_matrix[0][0] + a_matrix[0][1] * b_matrix[1][0];
    c_matrix[0][1] = a_matrix[0][0] * b_matrix[0][1] + a_matrix[0][1] * b_matrix[1][1];
    c_matrix[1][0] = a_matrix[1][0] * b_matrix[0][0] + a_matrix[1][1] * b_matrix[1][0];
    c_matrix[1][1] = a_matrix[1][0] * b_matrix[0][1] + a_matrix[1][1] * b_matrix[1][1];



    int c_matrix_new[2][2];
    //int i,j,k;
    int n = 2;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                c_matrix_new[ i ][ j ] = c_matrix_new[ i ][ j ] + a_matrix[ i ][ k ] * b_matrix[ k][ j ];
            }
        }
    }


    double c_matrix_double[2][2];
    double db;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            c_matrix_double[ i ][ j ] = 0.0;
        }
    }
    for (int k=0; k<n; k++) {
        for (int j=0; j<n; j++) {
            db = b_matrix[ k ][ j ];
            for (int i=0; i<n; i++) {
                c_matrix_double[ i ][ j ]= c_matrix_double[ i ][ j ]+ a_matrix[ i ][ k ]* db;
            }
        }
    }


    printf("c matrix\n");
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++) {
            printf("%d ",c_matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");


    printf("c matrix new\n");
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++) {
            printf("%d ",c_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("c matrix double\n");
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++) {
            printf("%f ",c_matrix_double[i][j]);
        }
        printf("\n");
    }



}



int * matrix_cacl(int * a, int al, int aw, int * b, int bl, int bw) {


}
