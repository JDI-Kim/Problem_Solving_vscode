int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int result = -1;
    int sz = A.size();
    if(sz < X) return -1;
    
    vector<int> visit(X+1);
    for(int i=0; i<X+1 ;++i){
        visit[i]=-1;
    }
    for(int i=0; i<sz ;++i){
        if(visit[A[i]]==-1) visit[A[i]]=i;
    }
    for(int i=1; i<X+1; ++i){
        if(visit[i]==-1) return -1;
        result = max(result,visit[i]);
    }
    
    
    return result;
}
/*
Detected time complexity:
O(N)
▶example
example test✔OK
expand allCorrectness tests
▶simple
simple test✔OK
▶single
single element✔OK
▶extreme_frog
frog never across the river✔OK
▶small_random1
3 random permutation, X = 50✔OK
▶small_random2
5 random permutation, X = 60✔OK
▶extreme_leaves
all leaves in the same place✔OK
expand allPerformance tests
▶medium_random
6 and 2 random permutations, X = ~5,000✔OK
▶medium_range
arithmetic sequences, X = 5,000✔OK
▶large_random
10 and 100 random permutation, X = ~10,000✔OK
▶large_permutation
permutation tests✔OK
▶large_range
arithmetic sequences, X = 30,000✔OK
*/