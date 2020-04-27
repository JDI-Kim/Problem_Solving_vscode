/*
    BOJ #1205 등수 구하기. 조건이 복잡할 땐 아닌 것부터 가지치기 하기

*/
#include <iostream>
using namespace std;
int P,N;
const int maxP=50;
const int maxN=50;
int U;
int ranking[maxP];
int rankInfo[maxP];
int rankU;
void read(){
    cin>>N>>U>>P;
    rankU=-1;
    for(int i=0;i<N;++i){
        cin>>ranking[i];

    }
}

void solve(){
    if(N==0) {rankU=1;return;}
    if(P<=N){//full
        if (U<=ranking[P-1]) { rankU=-1;return;}
        rankU = -1;
        for(int i=0;i<P;++i){
            if(ranking[i]<=U) {rankU=i+1; return;}
        }
        return;
    }else{ //there is a spot
        if(U<ranking[N-1]) { rankU=N+1; return; }
        for(int i=0;i<N;++i){
            if(ranking[i]<=U){rankU=i+1;return;}
        }
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
        cout<<"#"<<test<<" "<<rankU<<"\n";
    }
    return 0;
}