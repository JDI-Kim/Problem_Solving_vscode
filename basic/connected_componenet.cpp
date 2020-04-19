/*
BOJ #11724 연결 요소의 개수
*/
#include <iostream>
using namespace std;
int N,M;
const int maxN=1000+1;
const int maxM=500000;
bool graph[maxN][maxN];
bool visit[maxN];
int cc;
void read(){
    int u,v;
    cc=0;
    cin>>N>>M;
    for(int i=1; i<=N;++i){
        visit[i]=false;
    }
     for(int i=1;i<=N;++i){
         for(int j=1;j<=N;++j){
             graph[i][j]=false;
         }
     }
    for(int i=0;i<M;++i){
        cin>>u>>v;
        graph[u][v]=graph[v][u]=true;
    }
}
void row(int idx){
    for(int j=1;j<=N;++j){////////////j=1 부터 해야 해. j=idx부터 해서는 안됐음..
        if(!graph[idx][j])continue;
        if(visit[j])continue;
        visit[j]=true;
        row(j);
    }
}
void solve(){
    for(int i=1; i<=N; ++i){
        if(visit[i]) continue;
        visit[i]=true;
        cc++;
        row(i);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Test;
    cin>>Test;
    for(int test=1; test<=Test;++test){
        read();
        if(M==0) cc=N;
        else solve();
        cout<<"#"<<test<<" "<<cc<<"\n";
    }
    return 0;
}