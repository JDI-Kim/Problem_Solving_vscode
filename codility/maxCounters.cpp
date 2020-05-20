// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> C(N);
    int sz = A.size();
    int maxC=0;
    
    for(int i=0;i<sz;++i){
        if(1<=A[i] && A[i]<=N){ 
            C[A[i]-1]+=1; 
            maxC = max(maxC, C[A[i]-1]);
            continue;
        }
        if(A[i] == N+1) {
            for(int j=0; j<N;++j){
                C[j]=maxC;   
            }
        }
    }
    return C;
}