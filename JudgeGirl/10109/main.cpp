#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#include "CycleTimer.h"


uint32_t cudaFunc(int n, int k);
void printCudaInfo();

void usage(const char* progname) {
    printf("Usage: %s [options] \n", progname);
    printf("Program Options:\n");
    printf("  -m  --test <TYPE>      Run specified function on input.  Valid tests are: scan, find_repeats (default: scan)\n"); 
    printf("  -i  --input <NAME>     Run test on given input type. Valid inputs are: ones, random (default: random)\n");
    printf("  -n  --arraysize <INT>  Number of elements in arrays\n");
    printf("  -t  --thrust           Use Thrust library implementation\n");
    printf("  -?  --help             This message\n");
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
	int N, K;
	while(cin >> N >> K){
		printCudaInfo();
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
