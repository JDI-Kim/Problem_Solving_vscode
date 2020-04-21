/*
    BOJ #7576 토마토 BFS;
*/
#include <iostream>
#include <queue>
using namespace std;
int N,M;
const int maxN=1000;
const int maxM=1000;
int map[maxN][maxM];
int days;
int numRiped;
int numTomato;
 
typedef struct{
    int x,y;
}pos;

queue<pos> q;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void init(){
    days=0;
    numTomato=0;
    numRiped=0;
    while(!q.empty()){q.pop();}
}
void read(){
    
    cin>>M>>N;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>map[i][j];
            if(map[i][j]==1){
                numTomato++; 
                numRiped++; 
                pos p={j,i}; 
                q.push(p); 
                continue;}
            if(map[i][j]==0){numTomato++;continue;}
        }
    }
}
void check(){
    days=0;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(map[i][j]==0) {days=-1; return;}
            days=max(days,map[i][j]);
        }
    }
    days--;
    return;
}
void solve(){
    if(numTomato==numRiped) {days=0; return;}
    while(!q.empty()){
        pos p = q.front(); q.pop();
        pos nP;
        for(int d=0;d<4;++d){
            int nX=p.x+dx[d];
            int nY=p.y+dy[d];
            if(nX<0 || nX>=M ||nY<0 ||nY>=N) continue;
            if(map[nY][nX]>0 || map[nY][nX]==-1) continue;
            map[nY][nX]=map[p.y][p.x]+1;
            days=map[p.y][p.x];
            numRiped++;//
            if(numRiped==numTomato) return;//
            nP.x=nX; nP.y=nY;
            q.push(nP);
        }
    }
    if(numRiped!=numTomato) days=-1;
    //check();
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;
    for(int test=1;test<=Test;++test){
        init();
        read();
        solve();
        cout<<"#"<<test<<" "<<days<<"\n";
    }
    return 0;
}