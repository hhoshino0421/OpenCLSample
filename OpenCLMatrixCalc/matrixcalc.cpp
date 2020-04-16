//
// Created by 星野斉 on 2020/04/16.
//
#include <stdio.h>
#include "matrixcalc.h"
#include <OpenCL/cl.h>

#define MAX_SOURCE_SIZE (0x100000)


void executeCalc() {

    cl_platform_id      platform_id     = NULL;
    cl_device_id        device_id       = NULL;
    cl_context          context         = NULL;
    cl_command_queue    command_queue   = NULL;
    cl_mem              Amobj           = NULL;
    cl_mem              Bmobj           = NULL;
    cl_mem              Cmobj           = NULL;
    cl_program          program         = NULL;
    cl_kernel           kernel          = NULL;
    cl_uint             ret_num_devices;
    cl_uint             ret_num_platforms;
    cl_int              ret;

    const int   N = 1024;
    int         i, j;

    //データ領域宣言
    float **a   = new float*[N];
    float **b   = new float*[N];
    float **c   = new float*[N];

    for (i = 0; i < N; i++) {
        a[i] = new float[N];
        b[i] = new float[N];
        c[i] = new float[N];
    }

    //データ初期値設定
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = (float)(int)(rand() / 4096);
            b[i][j] = (float)(int)(rand() / 4096);
            c[i][j] = 0.0f;
        }
    }

    //カーネルコードの定義
    FILE *fp;
    const char fileName[] = "/Users/hhoshino/develop/CLion_workspace/OpenCLMatrixCalc/KernelMatrixCalc.cl";
    size_t source_size;
    char *source_str;

    /* カーネルを含むソースコードをロード */
    fp = fopen(fileName, "r");
    if (!fp) {
        fprintf(stderr, "Failed to load kernel.\n");
        exit(1);
    }
    source_str = (char *)malloc(MAX_SOURCE_SIZE);
    source_size = fread( source_str, 1, MAX_SOURCE_SIZE, fp );
    fclose( fp );

    /* プラットフォーム・デバイスの情報の取得 */
    ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
    ret = clGetDeviceIDs( platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);

    /* OpenCLコンテキストの作成 */
    context = clCreateContext( NULL, 1, &device_id, NULL, NULL, &ret);

    /* コマンドキューの作成 */
    command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

    /* バッファオブジェクトの作成 */
    Amobj = clCreateBuffer(context, CL_MEM_READ_WRITE, N * N * sizeof(float), NULL, &ret);
    Bmobj = clCreateBuffer(context, CL_MEM_READ_WRITE, N * N * sizeof(float), NULL, &ret);
    Cmobj = clCreateBuffer(context, CL_MEM_READ_WRITE, N * N * sizeof(float), NULL, &ret);

    /* メモリバッファにデータを転送 */
    ret = clEnqueueWriteBuffer(command_queue, Amobj, CL_TRUE, 0, 4*4*sizeof(float), a, 0, NULL, NULL);
    ret = clEnqueueWriteBuffer(command_queue, Bmobj, CL_TRUE, 0, 4*4*sizeof(float), b, 0, NULL, NULL);

    /* 読み込んだソースからカーネルプログラムを作成 */
    program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);
    ret     = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

    /* データ並列のOpenCLカーネルの作成 */
    kernel = clCreateKernel(program, "KernelMatrixCalc", &ret);

    /* OpenCLカーネル引数の設定 */
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&Amobj);
    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&Bmobj);
    ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&Cmobj);

    size_t global_item_size = 4;
    size_t local_item_size = 1;

    /* OpenCLカーネルをデータ並列で実行 */
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL,
                                 &global_item_size, &local_item_size, 0, NULL, NULL);

    /* メモリバッファから結果を取得 */
    ret = clEnqueueReadBuffer(command_queue, Cmobj, CL_TRUE, 0, 4*4*sizeof(float), c, 0, NULL, NULL);

    /* 終了処理 */
    ret = clFlush(command_queue);
    ret = clFinish(command_queue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(Amobj);
    ret = clReleaseMemObject(Bmobj);
    ret = clReleaseMemObject(Cmobj);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);

    free(source_str);

    free(a);
    free(b);
    free(c);

}