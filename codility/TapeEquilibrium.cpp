// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int sz = A.size();//2~100000
    int sumL = A[0];
    int sumR = 0;
    int diff = 0;
    
    for(int i=1; i<sz; ++i){
        sumR+=A[i];   
    }
    diff = abs(sumL - sumR);
    
    
    for(int i=1; i<sz-1; ++i){
        sumL += A[i];
        sumR -= A[i];
        diff = min(diff, abs(sumL - sumR));
    }
    
    return diff;
    
}

/*

expand allCorrectness tests
▶double
two elements✔OK
▶simple_positive
simple test with positive numbers, length = 5✔OK
▶simple_negative
simple test with negative numbers, length = 5✔OK
▶simple_boundary
only one element on one of the sides✔OK
▶small_random
random small, length = 100✔OK
▶small_range
range sequence, length = ~1,000✔OK
▶small
small elements✔OK
expand allPerformance tests
▶medium_random1
random medium, numbers from 0 to 100, length = ~10,000✔OK
▶medium_random2
random medium, numbers from -1,000 to 50, length = ~10,000✔OK
▶large_ones
large sequence, numbers from -1 to 1, length = ~100,000✔OK
▶large_random
random large, length = ~100,000✔OK
▶large_sequence
large sequence, length = ~100,000✔OK
▶large_extreme
large test with maximal and minimal values, length = ~100,000✔OK
*/