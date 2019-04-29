//
// Created by Hoshino Hitoshi on 2019-04-28.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <OpenCL/opencl.h>
//#include <CL/cl.h>
#include "Const.h"

int CLProcess() {

    //使用変数定義
    float * x_Array;
    float * y_Array;
    float * dist_Array;
    int     array_size    = ARRAY_SIZE;

    //OpenCL用変数定義
    cl_device_id        device_id       = NULL;
    cl_context          context         = NULL;
    cl_command_queue    command_queue   = NULL;
    cl_mem              memobj          = NULL;
    cl_mem              memobjb         = NULL;
    cl_mem              memobjout       = NULL;
    cl_mem              memor           = NULL;
    cl_mem              memosize        = NULL;
    cl_program          program         = NULL;
    cl_kernel           kernel          = NULL;
    cl_platform_id      platform_id     = NULL;
    cl_uint             ret_num_devices, ret_num_platforms;
    cl_int              ret;

    //処理時間計測用
    clock_t     start_clock_time, end_clock_time;
    double      process_time;

    //処理時間計測開始
    start_clock_time = clock();

    //OpenCL用カーネルコード読み込み処理
    FILE    *filepoi;
    char    fileName[]  = "./clsample.cl";
    char    *source_str;
    size_t  source_size;

    filepoi = fopen(fileName, "r");
    if(!filepoi) {
        //異常終了
        printf("Kernel Code Read Error!\n");
        return -1;
    }
    source_str  = (char*)malloc(MAX_SOURCE_SIZE);
    source_size = fread(source_str, 1, MAX_SOURCE_SIZE, filepoi);
    fclose(filepoi);

    //デバイスチェック
    ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
    if (ret != CL_SUCCESS) {
        printf("Device Check error(clGetPlatformIDs):%d\n",ret);
        return -1;
    }

    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);
    if (ret != CL_SUCCESS) {
        printf("Device Check error(clGetDeviceIDs):%d\n",ret);
        return -1;
    }

    //コンテキスト作成
    context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

    if (context == NULL) {
        printf("Context make error:%d\n", ret);
        return -1;
    }

    //コマンドキュー作成
    command_queue = clCreateCommandQueue(context, device_id, 0, &ret);
    if (command_queue == NULL) {
        printf("Command queue make error:%d\n", ret);
        return -1;
    }

    //カーネルコードオブジェクト作成
    program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);
    if (program == NULL) {
        printf("Program Object make error:%d\n", ret);
        return -1;
    }

    //カーネルコードコンパイル
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
    if (ret != CL_SUCCESS) {
        printf("Kernel Code compile error:%d\n", ret);
        return -1;
    }

    //カーネル作成
    kernel = clCreateKernel(program, "clexec", &ret);
    if (kernel == NULL) {
        printf("Kernel Code create error:%d\n", ret);
        return -1;
    }


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
        *(x_Array + i) = (float) rand() / SALT_DATA;
        *(y_Array + i) = (float) rand() / SALT_DATA;
    }


    //GPU用バッファ領域作成
    memobj      = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(float) * ARRAY_SIZE, NULL, &ret);
    memobjb     = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(float) * ARRAY_SIZE, NULL, &ret);
    memobjout   = clCreateBuffer(context, CL_MEM_READ_WRITE, ARRAY_SIZE * ARRAY_SIZE * sizeof(float), NULL, &ret);
    memosize    = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int), NULL, &ret);

    //バッファ領域にデータを出力
    ret = clEnqueueWriteBuffer(command_queue, memobj, CL_TRUE, 0, sizeof(float)*ARRAY_SIZE, x_Array, 0, NULL, NULL);
    if (ret != CL_SUCCESS) {
        printf("Write buffer error(1):%d\n", ret);
        return -1;
    }

    ret = clEnqueueWriteBuffer(command_queue, memobjb, CL_TRUE, 0, sizeof(float)*ARRAY_SIZE, y_Array, 0, NULL, NULL);
    if (ret != CL_SUCCESS) {
        printf("Write buffer error(2):%d\n", ret);
        return -1;
    }

    ret = clEnqueueWriteBuffer(command_queue, memobjout, CL_TRUE, 0, sizeof(float)*ARRAY_SIZE*ARRAY_SIZE, dist_Array, 0, NULL, NULL);
    if (ret != CL_SUCCESS) {
        printf("Write buffer error(3):%d\n", ret);
        return -1;
    }

    ret = clEnqueueWriteBuffer(command_queue, memosize, CL_TRUE, 0, sizeof(int), &array_size, 0, NULL, NULL);
    if (ret != CL_SUCCESS) {
        printf("Write buffer error(4):%d\n", ret);
        return -1;
    }

    //カーネルオブジェクトに引数設定
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobj);
    if (ret != CL_SUCCESS) {
        printf("Set argument kernel error(1):%d\n", ret);
        return -1;
    }

    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&memobjb);
    if (ret != CL_SUCCESS) {
        printf("Set argument kernel error(2):%d\n", ret);
        return -1;
    }

    ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&memobjout);
    if (ret != CL_SUCCESS) {
        printf("Set argument kernel error(3):%d\n", ret);
        return -1;
    }

    ret = clSetKernelArg(kernel, 3, sizeof(cl_mem), (void *)&memosize);
    if (ret != CL_SUCCESS) {
        printf("Set argument kernel error(4):%d\n", ret);
        return -1;
    }

    size_t local_item_size = ITEM_SIZE;
    size_t global_item_size = ITEM_SIZE;

    //GPU処理実行
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);
    if (ret != CL_SUCCESS) {
        printf("OpenCL execute error:%d\n", ret);
        return -1;
    }


    //後始末
    ret = clFlush(command_queue);
    ret = clFinish(command_queue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(memobj);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);

    free(source_str);

    free(x_Array);
    free(y_Array);
    free(dist_Array);


    //処理時間表示
    end_clock_time = clock();
    process_time = (double)(end_clock_time - start_clock_time) / CLOCKS_PER_SEC;

    printf("OpenCLProcess ProcessTime:%f\n", process_time);


    //正常終了
    return 0;

}