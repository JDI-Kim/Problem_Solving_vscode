/*
BOJ #8979. 올림픽
*/

#include <iostream>
using namespace std;
int N;
const int maxN = 1000+1;
int K;
int C[maxN];
int gold[maxN];
int silver[maxN];
int cu[maxN];
int score[maxN];
void read(){

    cin>>N>>K;
    
    for(int i=1;i<=N;++i){
        cin>>C[i];
        cin>>gold[C[i]]>>silver[C[i]]>>cu[C[i]];
    }

}
void init(){
    for(int i=1;i<=N;++i){
        score[i]=0;
    }
}
void solve(){
    for(int i=1;i<=N;++i){
        int num=0;
        for(int j=1;j<=N;++j){
            if(i==j)continue;
            if(gold[C[j]]>gold[C[i]]){ num++; continue;}
            if(gold[C[j]]==gold[C[i]]){
                if(silver[C[j]]>silver[C[i]]){num++;continue;}
                if(silver[C[j]]==silver[C[i]] && cu[C[j]]>cu[C[i]]){num++;continue;}
            }
        }
        score[C[i]]=num+1;
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;

    for(int test=1;test<=Test;++test){
        read();
        init();
        solve();
        cout<<"#"<<test<<" "<<score[K]<<"\n";
    }
    return 0;
}