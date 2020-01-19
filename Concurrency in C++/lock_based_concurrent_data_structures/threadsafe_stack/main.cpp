#include "threadsafestack.h"
#include <iostream>
#include <thread>
#include <random>
#include <fstream>

using namespace std;

const int N = 8; // number of threads

random_device r;
default_random_engine e1(r());
uniform_int_distribution<int> uniform_dist(-500, 500);

ofstream myfile;

void start(int id, ThreadSafeStack<int>& ts_stack)
{
    for(int i=0; i<10; i++){
        printf("thread(%d) is executing round(%d)\n", id, i);
        if(ts_stack.size() < 4){
            ts_stack.push(id + N * i);
            printf("thread(%d) push value (%d)\n", id, id + N * i);
        }
        else{
            int num;
            ts_stack.pop(num);
            printf("thread(%d) pop value (%d)\n", id, num);
        }
        printf("thread(%d) get the top value of stack: (%d)\n", id, ts_stack.top());
        this_thread::sleep_for(chrono::milliseconds(1000 + uniform_dist(e1)));
    }
}



int main()
{
    ThreadSafeStack<int> ts_stack;
    puts("Start Here");
    vector<thread> threads(N);
    for(int i=0; i<N; i++){
        threads[i] = thread(start, i, ref(ts_stack));
    }
    for(auto& th: threads){
        th.join();
    }
    return 0;
}
