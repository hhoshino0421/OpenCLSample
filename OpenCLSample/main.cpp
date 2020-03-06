
//Mac OSの場合は<OpenCL/cl.h>になる。
//https://blog.miz-ar.info/2017/05/opencl-with-cxx-0/
//#include <CL/cl.h>
//#include <OpenCL/cl.h>

#include "opencl_1.h"
#include "opencl_0.h"
#include "opencl_2.h"


int main() {


    // Device情報出力
    info_output();

    // Hello World実行
    hello_execute();

    //データ計算処理実行
    dataParallel();

    return 0;
}
