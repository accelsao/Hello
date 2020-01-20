#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#include "CycleTimer.h"

double cudaSorting(int* start, int* end, int* resultarray);
double cudaSortingThrust(int* start, int* end, int* resultarray);
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

void cpu_sorting(int *start, int length, int *output) {
	std::sort(start, start + length);
	memcpy(output, start, sizeof(int) * length);
}

int main(int argc, char** argv) {
  
    int N = 64;
    bool useThrust = false;
    std::string test("sorting"); 
    std::string input("random");

    // parse commandline options ////////////////////////////////////////////
    int opt;
    static struct option long_options[] = {
        {"test",       1, 0, 'm'},
        {"arraysize",  1, 0, 'n'},
        {"input",      1, 0, 'i'},
        {"help",       0, 0, '?'},
        {"thrust",     0, 0, 't'},
        {0 ,0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "m:n:i:?t", long_options, NULL)) != EOF) {
        switch (opt) {
        case 'm':
            test = optarg; 
            break;
        case 'n':
            N = atoi(optarg);
            break;
        case 'i':
            input = optarg;
            break;
        case 't':
            useThrust = true;
            break;
        case '?':
        default:
            usage(argv[0]);
            return 1;
        }
    }
    // end parsing of commandline options //////////////////////////////////////

    int* inarray = new int[N];
    int* resultarray = new int[N];
    int* checkarray = new int[N];

    if (input.compare("random") == 0) {

        srand(time(NULL));

        // generate random array
        for (int i = 0; i < N; i++) {
            int val = rand() % 10;
            inarray[i] = val;
            checkarray[i] = val;
        }
	
    } else {
      
        // all one's test case - you may find this useful for debugging
        for(int i = 0; i < N; i++) {
            inarray[i] = 1;
            checkarray[i] = 1;
        }  
    }

    printCudaInfo();

    double cudaTime = 50000.;

    printf("Array size: %d\n", N);
    
    if (test.compare("sorting") == 0) { // test sorting
	  
        // run CUDA implementation
        for (int i=0; i<1; i++) {
            if (useThrust){
				cudaTime = std::min(cudaTime, cudaSortingThrust(inarray, inarray+N, resultarray));
			}
            else
                cudaTime = std::min(cudaTime, cudaSorting(inarray, inarray+N, resultarray));
        }

        // run CPU implementation to check correctness
        cpu_sorting(inarray, N, checkarray);

        if (useThrust) { 
            printf("Thrust GPU time: %.3f ms\n", 1000.f * cudaTime);
        } else {    
            printf("Student GPU time: %.3f ms\n", 1000.f * cudaTime);
        } 

        // validate results
        for (int i = 0; i < N; i++) {
            if (checkarray[i] != resultarray[i]) {
                fprintf(stderr,
                        "Error: Device sorting outputs incorrect result."
                        " A[%d] = %d, expecting %d.\n",
                        i, resultarray[i], checkarray[i]);
                exit(1);
            }
        }
        printf("Sorting outputs are correct!\n");
	
    }
	else { 
        usage(argv[0]); 
        exit(1); 
    }
    
    delete [] inarray;
    delete [] resultarray;
    delete [] checkarray;
    
    return 0;
}
