/*
    BOJ #11399 ATM *규칙 관찰, 소팅하면 금방 푸는 문제
*/
#include <iostream>
#include <algorithm>

using namespace std;
int N;
const int maxN=1000+1;
int P[maxN];
int minTime;
bool visit[maxN];
int O[maxN];

void init(){
    for(int i=0;i<N;++i){
        visit[i]=false;
    
    }
}
void read(){
    cin>>N;
    minTime=1000001;
    init();
    for(int i=0;i<N;++i){
        cin>>P[i];
    }
}

void solve(int count){
    minTime=0;
    sort(P,P+N);
    for(int i=0;i<N;++i){
        minTime+=P[i]*(N-i);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;
    for(int test=1;test<=Test;++test){
        read();
        solve(0);
        cout<<"#"<<test<<" "<<minTime<<"\n";
    }
    return 0;
}