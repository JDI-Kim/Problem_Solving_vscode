/*
    BOJ #2179 미로탐색 BFS, **인풋이 붙어서 들어오면 문자열로 받되 계산을 정수형으로 할거면 수정해줄것
*/
#include <iostream>
#include <queue>

using namespace std;
int N,M;
const int maxN=101;
const int maxM=101;
char mapInit[maxN][maxM];
int map[maxN][maxM];
typedef struct{
    int x,y;
}pos;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int path;
void read(){
    path=0;
    cin>>N>>M;
    for(int i=1;i<=N;++i){
        cin>>mapInit[i];
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            map[i][j]=mapInit[i][j-1]-'0';
        }
    }
}
void printMap(){
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void solve(){
    queue<pos> q;
    pos initP={1,1};
    map[1][1]=2;
    q.push(initP);
    
    while(!q.empty()){
        pos p = q.front();q.pop();
        for( int d=0;d<4;++d){
            int nX=p.x+dx[d];
            int nY=p.y+dy[d];
            if(nX<=0 || nX>M || nY<=0 ||nY>N) continue;
            if(map[nY][nX]!=1) continue;
            if(nY==N && nX ==M) {path = map[p.y][p.x]; return;}
            map[nY][nX]=map[p.y][p.x]+1;
            pos nP = {nX,nY};
            q.push(nP);
        }
       // printMap();
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
        cout<<"#"<<test<<" "<<path<<"\n";
    }
    return 0;
}