/*
    BOJ #1012 유기농배추. dfs
*/
#include<iostream>
using namespace std;
int M,N,K;
const int maxM=50+1;
const int maxN=50+1;
const int maxK=2500+1;
int map[maxN][maxM];
typedef struct{
    int x,y;
}pos;
pos C[maxK];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int num;
void read(){
    num =0;
    cin>>M>>N>>K;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            map[i][j]=0;
        }
    }
    for(int i=0;i<K;++i){
        cin>>C[i].x>>C[i].y;
        map[C[i].y][C[i].x]=1;
    }
}
void findnear(int x, int y){
    
    for(int d=0;d<4;++d){
        int nx= x+dx[d];
        int ny= y+dy[d];
        if(nx<0 || nx>=M || ny<0 ||ny>=N) continue;
        if(map[ny][nx]==0) continue;
        if(map[ny][nx]==2)continue;
        map[ny][nx]=2;//visit
        findnear(nx,ny);
    }
}
void solve(){
    for(int i=0;i<K;++i){
        int xx=C[i].x;
        int yy=C[i].y;
        if(map[yy][xx]==2)continue;
        num++;
        findnear(xx,yy);    
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;
    for(int test=1; test<=Test; ++test){
        read();
        solve();
        cout<<"#"<<test<<" "<<num<<"\n";
    }
    return 0;
}