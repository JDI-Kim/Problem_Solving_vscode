/*
    BOJ #2589  보물섬, BFS 최적화 전
*/
#include<iostream>
#include <queue>
using namespace std;
int H,W;
const int maxH=50+1;
const int maxW=50+1;
char map[maxH][maxW];
int visit[maxH][maxW];
int maxDis;
typedef struct{
    int x, y;
}pos;
queue<pos> startPos;
pos startMap[maxH][maxW];

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void checkStart(int i, int j){
    if(map[i-1][j]=='W' && map[i][j-1]=='W') {startMap[i][j].x=i;startMap[i][j].y=j;return;}
    if(map[i-1][j]=='W' && map[i][j-1]=='L') {startMap[i][j]=startMap[i][j-1];return;}
    if(map[i-1][j]=='L' && map[i][j-1]=='W') {startMap[i][j]=startMap[i-1][j];return;}
    if(map[i])



}
void read(){
    maxDis=0;
   
    while(!startPos.empty()){startPos.pop();}

    cin>>H>>W;
    for(int i=0;i<=H;++i){ map[i][0]='W';}
    for(int j=0;j<=W;++j){ map[0][j]='W';}

    for(int i=1;i<=H;++i){
        for(int j=1;j<=W;++j){
            cin>>map[i][j];
            if(map[i][j]=='L') { pos p={j,i}; startPos.push(p);}
        }
    }
}
void initVisit(){
    for(int i=1;i<=H;++i){
        for(int j=1;j<=W;++j){
            visit[i][j]=-1 ;
        }
    }
}
void findLast(pos s){//update maxDis with corresponding start/last
    initVisit();
    queue<pos> q;
    q.push(s);
    visit[s.y][s.x]=0;
    
    while(!q.empty()){
        pos p = q.front(); q.pop();
        for(int d=0;d<4;++d){
            int nX=p.x+dx[d];
            int nY=p.y+dy[d];
            if(nX<=0 || nX>W || nY<=0 || nY>H) continue;
            if(visit[nY][nX]> -1 || map[nY][nX]=='W')continue;
            visit[nY][nX]=visit[p.y][p.x]+1;
            pos nP = {nX,nY};
            if(maxDis<visit[nY][nX]){ maxDis=visit[nY][nX];}
            q.push(nP);

        }
    }
    
}
void solve(){
    while(!startPos.empty()){
        pos tempStart= startPos.front();startPos.pop();
        findLast(tempStart);
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
        cout<<"#"<<test<<" "<<maxDis<<"\n";
    }
    return 0;
}