/*
    [codility] Odd Occurrences in array
    * 정렬하고, 짝수인덱스의 배열 값이 다음 값이랑 같은지 확인. 다르면 그 짝수 인덱스의 값이 홀수개라는 뜻임. 
    출처: https://app.codility.com/programmers/lessons/
    O(N) or O(N*log(N))
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int sz = A.size();
    if(sz==1) return A[0]; //제발~

    sort(A.begin(), A.end());

    for(int i=0; i<sz ; i+=2){
       if(A[i]!=A[i+1]) return A[i];
    }
    return A[0];
    
}
int main(void){
    int T;
    cin>>T;
    for(int test=1;test<=T;++test){
        int n;
        cin>>n;

        vector<int> A;
        int temp;

        for(int i=0;i<n;++i){
            cin>>temp;
            A.push_back(temp);
        }
        cout<<"#"<<test<<" "<< solution(A)<<"\n";
       
    }
    return 0;

}