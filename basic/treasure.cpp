/*
    BOJ #1026 보물 **정렬
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N;
const int maxN=50;
int A[maxN];
int B[maxN];
int result;
void read(){
    cin>>N;
    result=0;
    for(int i=0;i<N;++i){
        cin>>A[i];
    }
    for(int i=0;i<N;++i){
        cin>>B[i];
    }
}
void solve(){
    sort(A,A+N);
    sort(B,B+N);
    for(int i=0;i<N;++i){
        result+=A[N-i-1]*B[i];
    }

}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;
    for(int test=1;test<=Test;++test){
        read();
        solve();
        cout<<"#"<<test<<" "<<result<<"\n";
    }
    return 0;
}