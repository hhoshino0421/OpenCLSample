//
// Created by 星野斉 on 2020/04/16.
//
#include <stdio.h>
#include "matrixcalc.h"
#include <OpenCL/cl.h>
#include <time.h>

#define MAX_SOURCE_SIZE (0x100000)


void executeCalc(const int N) {

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
    //ret = clGetDeviceIDs( platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);
    ret = clGetDeviceIDs( platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &ret_num_devices);


    // for debug--------------------------------
    cl_device_type type;
    char string2[256];
    cl_uint value;
    size_t sizes[3];
    cl_ulong ulvalue;

    printf("	device idx : %d\n", j);
    cl_device_id device = device_id;
    clGetDeviceInfo(device, CL_DEVICE_NAME, 256, string2, NULL);
    printf("	device name : %s\n", string2);
    clGetDeviceInfo(device, CL_DEVICE_TYPE, sizeof(cl_device_type), &type, NULL);
    if (type == CL_DEVICE_TYPE_CPU) printf("	device type : CPU\n");
    if (type == CL_DEVICE_TYPE_GPU) printf("	device type : GPU\n");
    if (type == CL_DEVICE_TYPE_ACCELERATOR) printf("	device type : ACCELERATOR\n");
    if (type == CL_DEVICE_TYPE_ACCELERATOR) printf("	device type : ACCELERATOR\n");
    clGetDeviceInfo(device, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_uint), &value, NULL);
    printf("	device max compute units : %d\n", value);
    clGetDeviceInfo(device, CL_DEVICE_MAX_WORK_ITEM_SIZES, sizeof(size_t) * 3, sizes, NULL);
    printf("	device max work item sizes : [%d][%d][%d]\n", sizes[0], sizes[1], sizes[2]);
    clGetDeviceInfo(device, CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(cl_uint), &value, NULL);
    printf("	device max work group size : %d\n", value);
    clGetDeviceInfo(device, CL_DEVICE_MAX_MEM_ALLOC_SIZE, sizeof(cl_ulong), &ulvalue, NULL);
    printf("	device max mem alloc size : %d\n", ulvalue);
    clGetDeviceInfo(device, CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, sizeof(cl_ulong), &ulvalue, NULL);
    printf("	device max constant buffer size : %d\n", ulvalue);
    printf("\n");
    //for debug end------------------------------------

    /* OpenCLコンテキストの作成 */
    context = clCreateContext( NULL, 1, &device_id, NULL, NULL, &ret);

    /* コマンドキューの作成 */
    command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

    /* バッファオブジェクトの作成 */
    Amobj = clCreateBuffer(context, CL_MEM_READ_WRITE, N * N * sizeof(float), NULL, &ret);
    Bmobj = clCreateBuffer(context, CL_MEM_READ_WRITE, N * N * sizeof(float), NULL, &ret);
    Cmobj = clCreateBuffer(context, CL_MEM_READ_WRITE, N * N * sizeof(float), NULL, &ret);

    if (!Amobj || !Bmobj || !Cmobj) {
        printf("Error: Failed to allocate device memory!\n");
        exit(1);
    }

    /* メモリバッファにデータを転送 */
    ret = clEnqueueWriteBuffer(command_queue, Amobj, CL_TRUE, 0, N*N*sizeof(float), a, 0, NULL, NULL);
    ret = clEnqueueWriteBuffer(command_queue, Bmobj, CL_TRUE, 0, N*N*sizeof(float), b, 0, NULL, NULL);

    /* 読み込んだソースからカーネルプログラムを作成 */
    program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);
    ret     = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

    if (ret != CL_SUCCESS) {
        printf("Error: Failed clBuildProgram! %d\n", ret);
        exit(1);
    }

    /* データ並列のOpenCLカーネルの作成 */
    kernel = clCreateKernel(program, "KernelMatrixCalc", &ret);

    /* OpenCLカーネル引数の設定 */
    int wA = N;
    int wB = N;
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&Amobj);
    ret |= clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&Bmobj);
    ret |= clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&Cmobj);
    ret |= clSetKernelArg(kernel, 3, sizeof(int), (void *)&wA);
    ret |= clSetKernelArg(kernel, 4, sizeof(int), (void *)&wB);
    if (ret != CL_SUCCESS) {
        printf("Error: Failed to set kernel arguments! %d\n", ret);
        exit(1);
    }

    size_t global_item_size = 4;
    size_t local_item_size = 1;

    clock_t startTime = clock();

    /* OpenCLカーネルをデータ並列で実行 */
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL,
                                 &global_item_size, &local_item_size, 0, NULL, NULL);

    if (ret != CL_SUCCESS) {
        printf("Error: Failed clEnqueueNDRangeKernel! %d\n", ret);
        exit(1);
    }

    /* メモリバッファから結果を取得 */
    ret = clEnqueueReadBuffer(command_queue, Cmobj, CL_TRUE, 0, N*N*sizeof(float), c, 0, NULL, NULL);

    if (ret != CL_SUCCESS) {
        printf("Error: Failed clEnqueueReadBuffer! %d\n", ret);
        exit(1);
    }

    clock_t stopTime = clock();
    float etime = (float)(stopTime - startTime) / CLOCKS_PER_SEC;
    printf("elapsed time= %15.7f sec\n", etime);

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