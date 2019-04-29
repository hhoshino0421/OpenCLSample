__kernel void clexec(__global float *x ,__global float *y
                    ,__global float *out,__global int *size) {
    int gx = get_global_id(0);
    //int i, j, k, x, y;
    int i, j, k, a, b;
    k = (*size) * (*size) / get_global_size(0);
    for(i = 0; i < k; i++){
        j = i + k * gx;
        a = j / (*size);
        b = j % (*size);
        out[j] = sqrt(pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2));
    }
}
