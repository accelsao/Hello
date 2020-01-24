#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include "CycleTimer.h"
#include <stdio.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <driver_functions.h>
#include <thrust/scan.h>
#include <thrust/device_ptr.h>
#include <thrust/device_malloc.h>
#include <thrust/device_free.h>
#include <iostream>
#include <cstdint>


using namespace std;

#define DEBUG

#ifdef DEBUG
#define cudaCheckError(ans) { cudaAssert((ans), __FILE__, __LINE__); }
inline void cudaAssert(cudaError_t code, const char *file, int line, bool abort=true)
{
   if (code != cudaSuccess)
   {
      fprintf(stderr, "CUDA Error: %s at %s:%d\n",
        cudaGetErrorString(code), file, line);
      if (abort) exit(code);
   }
}
#else
#define cudaCheckError(ans) ans
#endif

const int threadsPerBlock = 256;

// helper function to round an integer up to the next power of 2
static inline int nextPow2(int n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

// gpu_bitonic_sort
__global__ void gpu_bitonic_sort(uint32_t* input, int j, int k)
{
	int i = blockDim.x * blockIdx.x + threadIdx.x;

	int id = i ^ j;
	if(id > i){
		if((i & k) == 0){
			if(input[i] > input[id]){
				int val = input[id];
				input[id] = input[i];
				input[i] = val;
			}
		}
		else{
			if(input[i] < input[id]){
				int val = input[id];
				input[id] = input[i];
				input[i] = val;
			}
		}
	}


}

// sum of a[i] * i
__global__ void gpu_sum(uint32_t* input, uint32_t* result, int n)
{
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	if(i < n){
		atomicAdd(result, input[i] * i);
	}
}

uint32_t cudaFunc(int n, int k){
	int N = nextPow2(n);
	size_t size = N * sizeof(uint32_t);

	uint32_t* input = (uint32_t*)malloc(size);
	uint32_t* device_input;
	for(int i=0; i<n; i++){
		input[i] = encrypt(i, k);
	}
	for(int i=n; i<N; i++){
		input[i] = UINT32_MAX;
	}


	cudaCheckError(cudaMalloc(&device_input, size));
	cudaCheckError(cudaMemcpy(device_input, input, size, cudaMemcpyHostToDevice));
	const int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;

	// BITONIC BEGIN

	for(int k=2; k<=N; k<<=1){
		for(int j=k>>1; j>0; j>>=1){
			gpu_bitonic_sort<<<blocksPerGrid, threadsPerBlock>>>(device_input, j, k);
			cudaCheckError(cudaDeviceSynchronize());
		}
	}
	// BITONIC END

	uint32_t* device_result;
	cudaCheckError(cudaMalloc(&device_result, sizeof(uint32_t)));
	gpu_sum<<<blocksPerGrid, threadsPerBlock>>>(device_input, device_result, n);
	cudaCheckError(cudaDeviceSynchronize());

	uint32_t* sum = (uint32_t*)malloc(sizeof(uint32_t));
	cudaCheckError(cudaMemcpy(sum, device_result, sizeof(uint32_t), cudaMemcpyDeviceToHost));
	cudaFree(device_input);
	cudaFree(device_result);
    return *sum;

}

// cudaSortingThrust --
double cudaSortingThrust(int* input, int* end, int* output) {


    int N = end - input;
    thrust::device_ptr<int> d_input = thrust::device_malloc<int>(N);

	size_t size = N * sizeof(int);

    cudaCheckError(cudaMemcpy(d_input.get(), input, size, cudaMemcpyHostToDevice));

    double startTime = CycleTimer::currentSeconds();

	thrust::sort(d_input, d_input + N);

    cudaCheckError(cudaDeviceSynchronize());
    double endTime = CycleTimer::currentSeconds();

    cudaCheckError(cudaMemcpy(output, d_input.get(), size, cudaMemcpyDeviceToHost));

    thrust::device_free(d_input);

    double overallDuration = endTime - startTime;
    return overallDuration;
}

void printCudaInfo()
{
    int deviceCount = 0;
    cudaError_t err = cudaGetDeviceCount(&deviceCount);

    printf("---------------------------------------------------------\n");
    printf("Found %d CUDA devices\n", deviceCount);

    for (int i=0; i<deviceCount; i++)
    {
        cudaDeviceProp deviceProps;
        cudaGetDeviceProperties(&deviceProps, i);
        printf("Device %d: %s\n", i, deviceProps.name);
        printf("   SMs:        %d\n", deviceProps.multiProcessorCount);
        printf("   Global mem: %.0f MB\n",
               static_cast<float>(deviceProps.totalGlobalMem) / (1024 * 1024));
        printf("   CUDA Cap:   %d.%d\n", deviceProps.major, deviceProps.minor);
    }
    printf("---------------------------------------------------------\n");
}


inline uint32_t encrypt(uint32_t m, uint32_t key) {
    return (m*m + key)%key;
}



uint32_t cpu_func(int n, int k) {
	vector<uint32_t> a(n);
	for(int i=0; i<n; i++){
		a[i] = encrypt(i, k);
	}
	sort(a.begin(), a.end());
	uint32_t sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i] * i;
	return sum;
}

int main(int argc, char** argv) {
    printCudaInfo();
	int N, K;
	while(cin >> N >> K){
        printf("Input N, K\n");
		printf("N: %d, K: %d\n", N, K);
		double cudaTime = 50000.;
		double cpuTime = 50000.;
		double startTime;
		double endTime;
		if ((N&(-N)) == N) {
			startTime = CycleTimer::currentSeconds();
			uint32_t sum = cpu_func(N, K);
			endTime = CycleTimer::currentSeconds();
			cpuTime = endTime - startTime;
			uint32_t cuda_sum;
			startTime = CycleTimer::currentSeconds();
			cuda_sum = cudaFunc(N, K);
			endTime = CycleTimer::currentSeconds();
			cudaTime = endTime - startTime;

			printf("Student CPU time: %.3f ms\n", 1000.f * cpuTime);
			printf("Student GPU time: %.3f ms\n", 1000.f * cudaTime);

			if(sum != cuda_sum){
				fprintf(stderr,
						"Error: Device outputs incorrect result."
						"cuda_sum = %u, expecting %u.\n",
						cuda_sum, sum);
			}
			else{
				printf("Correct!! Sum = %u\n", cuda_sum);

			}
		}
		else{
			fprintf(stderr, "N must be power of 2\n");
		}
	}
    return 0;
}
