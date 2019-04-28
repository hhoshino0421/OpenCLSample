
#include "LinearSample.h"
#include "CLSample.h"

/*
 * エントリポイント
 */
int main() {

    //逐次処理方式
    int ret = LinearProcess();

    if (ret != 0) {
        //異常終了
        return -1;
    }

    //OpenCL使用並列処理方式
    ret = CLProcess();

    if (ret != 0) {
        //異常終了
        return -1;
    }


    return 0;
}