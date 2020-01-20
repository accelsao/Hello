#include <stdio.h>

#include <cuda.h>
#include <cuda_runtime.h>

#include <driver_functions.h>

#include <thrust/scan.h>
#include <thrust/device_ptr.h>
#include <thrust/device_malloc.h>
#include <thrust/device_free.h>
#include <iostream>
using namespace std;

#include "CycleTimer.h"

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

__device__ void gpu_merge(int* input, int* output, int left, int width, int N)
{
	int mid = min(left + (width >> 1), N);
	int right = min(left + width, N);
	
	int i = left;
	int j = mid;
	for(int k=left;k<right;k++){
		if(i < mid && (j >= right || input[i] < input[j])){
			output[k] = input[i];
			i++;
		}
		else{
			output[k] = input[j];
			j++;
		}
	}	
}

// gpu_merge_sort
__global__ void gpu_merge_sort(int* input, int* output, int width, int N)
{	
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	if(i <= N / width){
		gpu_merge(input, output, i * width, width, N);
	}
}


// cudaSorting
double cudaSorting(int* input, int* end, int* result)
{
    int* device_output;
    int* device_input;
    int N = end - input;  
	size_t size = N * sizeof(int);
	
	cudaCheckError(cudaMalloc(&device_input, size));
	cudaCheckError(cudaMalloc(&device_output, size));
	cudaCheckError(cudaMemcpy(device_input, input, size, cudaMemcpyHostToDevice));
	
	
	
    double startTime = CycleTimer::currentSeconds();
	
	// MERGESORt BEGIN
	const int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;
	int roundN = nextPow2(N);
	int* tmp;
	for(int w = 2; w <= roundN; w <<= 1){
		gpu_merge_sort<<<blocksPerGrid, threadsPerBlock>>>(device_input, device_output, w, N);
		tmp = device_input;
		device_input = device_output;
		device_output = tmp;
		
		// Wait for completion
		cudaCheckError(cudaDeviceSynchronize());
	}
	cudaCheckError(cudaMemcpy(result, device_input, size, cudaMemcpyDeviceToHost));
	// MERGESORt END


    double endTime = CycleTimer::currentSeconds();

	cudaFree(device_input);
	cudaFree(device_output);

    double overallDuration = endTime - startTime;
    return overallDuration; 
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
