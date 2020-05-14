/*
    [codility] cyclic_rotation
    * mod 0 is undefined!!
    출처: https://app.codility.com/programmers/lessons/
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int sz=A.size();
    if(sz==0 || K==0 || K%sz==0) return A;
    //if(K%sz==0) return A; //-->이렇게 하면 empty 벡터 들어왔을때 런타임 에러남. 이걸 해주려면 위에처럼 해줘야 함.
    
    vector<int> result(sz);
    for(int i=0;i<sz;++i){
        result[(i+K)%sz]=A[i];
    }
    return result;
}

int main(void){
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        int n;
        int K;
        vector<int> A;

        cin>>n>>K;

        int temp;
        
        for(int i=0;i<n;++i){
            cin>>temp;
            A.push_back(temp);
        }

        cout<< "#"<<t<<" "<<"\n";         
        A = solution(A,K);
        for(int i=0;i<n;++i){
            cout<<A[i]<< " ";
        }
        cout<<"\n";
    }
}