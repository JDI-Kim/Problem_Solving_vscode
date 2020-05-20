int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    int left = 
    int hopI = (int)hop;
    if((hop-hopI)>0.0) return hopI+1;
    else return hopI;
}

//O(1)
int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    int dis=Y-X;
    int left= dis%D;
    int hop = dis/D;
    if(left==0) return hop;
    else return hop+1;
    
}
/*
▶many_jump1
many jumps, D = 2✘WRONG ANSWER
got 500000000 expected 499999998
▶many_jump2
many jumps, D = 99✘WRONG ANSWER
got 987654208 expected 987654222
▶many_jump3
many jumps, D = 1283✘WRONG ANSWER
got 499962048 expected 499962043
▶big_extreme_jump
maximal number of jumps✘WRONG ANSWER
got 1000000000 expected 999999999
▶small_jumps
many small jumps✘WRONG ANSWER
got 142730192 expected 142730189*/