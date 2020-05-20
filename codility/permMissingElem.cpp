// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int startI=0;
    int endI = A.size();
    int result=-1;
    
    if(A[0]!=1) return 1;
    if(A[endI-1]==endI) return endI+1;
    
    while(startI<endI){
        int mid = (startI+endI)/2;
        if(A[mid]==mid+2){
            if(A[mid-1]==mid) {result=mid+1; break;}
            else endI=mid;
        }
        else{
            startI=mid+1;        
        }
    }
    
    return result;
}
//empty_and_single
//empty list and single element✘RUNTIME ERROR
//tested program terminated with exit code 1



// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int sz=A.size();
    
    if(sz==0) return 1;

    
    sort(A.begin(), A.end());
    
    if(A[0]!=1) return 1;
    if(A[sz-1]==sz) return sz+1;
    
    int startI = 0;
    int endI = sz;
    int mid=0;
    
    while(startI < endI){
        mid = (startI+endI)/2;    
        if(A[mid]==mid+2){
            if(A[mid-1]==mid) {break;}
            endI = mid;
        }else{
            startI = mid+1;
        }
        
    }
    
    return mid+1;
    
}