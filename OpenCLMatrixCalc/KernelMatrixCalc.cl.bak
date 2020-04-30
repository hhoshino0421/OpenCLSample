__kernel void KernelMatrixCalc(__global float* A, __global float* B, __global float* C)
{
    int base = 4*get_global_id(0);
    
    C[base+0] = A[base+0] + B[base+0];
    C[base+1] = A[base+1] - B[base+1];
    C[base+2] = A[base+2] * B[base+2];
    C[base+3] = A[base+3] / B[base+3];
}

for (i = 0;i < N; i++) {
    for (j = 0; j < N; j++) {
        for (k = 0; k < N; k++) {
            c[i][j] += a[i][k] * b[k][j];
        }
    }
}