/*
 BOJ #1260 DFS와 BFS
*/
#include <iostream>
#include <queue>
using namespace std;
int N,M,V;
const int maxN=1000+1;
const int maxM=10000+1;

bool map[maxN][maxN];
bool visit[maxN];
void read(){
    cin>>N>>M>>V;
    int e1,e2;
    
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            map[i][j]=false;
        }
    }
    for(int i=0;i<M;++i){
        cin>>e1>>e2;
        map[e1][e2]=map[e2][e1]=true;
    }

}
void init(){
    for(int i=1;i<=N;++i){
        visit[i]=false;
    }
}

void DFS(int v){ 
    //처음 방문한 노드에서 뭔가 처리를 해줘야 할 경우
    if(visit[v]) return;
    visit[v]=true;
    cout<<v<<" ";

    for(int j=1;j<=N;++j){
        if(!map[v][j]) continue;
        DFS(j);
    }
}
void BFS(){
    queue<int> q;
    q.push(V);

    while(!q.empty()){
        int v=q.front();q.pop();
        if(visit[v])continue; 
        visit[v]=true;
        cout<<v<<" ";//방문해서 할 일은 여기서 처리합시다.

        for(int j=1;j<=N;++j){
            if(!map[v][j])continue;
            q.push(j);
        }

    }
}
void solve(){
    init();
    DFS(V);
    
    cout<<"\n";
    init();
    
    BFS();
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;
    for(int test=1;test<=Test;++test){
        read();
        solve();
        cout<<"#"<<test<<" "<<"\n";
    }
    return 0;
}