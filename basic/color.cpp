/*
    BOJ #10026  적록색약
    ** nI>=N 입니당 nI>N 아니고. 인덱스 범위 확인 확실히 할 것.
 */

#include <iostream>
using namespace std;

int N;
const int maxN=100+1;
char grid[maxN][maxN];
bool visit[maxN][maxN];
int R,G,B,RG;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void read(){
    cin>>N;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>grid[i][j];
        }
    }
    R=G=B=RG=0;

}
void init(){
     for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            visit[i][j]=false;
        }
     }
}
void area(int i, int j, char c){
    for(int d=0;d<4;++d){
        int nI=i+dy[d];
        int nJ=j+dx[d];
        if(nI<0 ||nI>=N ||nJ<0 ||nJ>=N) continue;
        if(grid[nI][nJ]!=c) continue;
        if(visit[nI][nJ]) continue;
       visit[nI][nJ]=true;
        area(nI,nJ,c);
    }
}
void areaRG(int i, int j){
    for(int d=0;d<4;++d){
        int nI=i+dy[d];
        int nJ=j+dx[d];
        if(nI<0 ||nI>=N ||nJ<0 ||nJ>=N) continue; // nI>=N 입니당 nI>N 아니고. 범위 확인 확실히 할 것.
        if(grid[nI][nJ]=='B') continue;
        if(visit[nI][nJ]) continue;
       visit[nI][nJ]=true;
        areaRG(nI,nJ);
    }
}
void solve(){
    init();
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(visit[i][j]) continue;
            if(grid[i][j]=='R') {R++;}
            else if(grid[i][j]=='G'){ G++;}
            else if(grid[i][j]=='B') {B++;}
            visit[i][j]=true;
                        
            area(i,j,grid[i][j]);
        }
    }
    init();
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(visit[i][j])continue;
            if(grid[i][j]=='B') {continue;}
            if(grid[i][j]=='R'|| grid[i][j]=='G'){ RG++;}            
            visit[i][j]=true;            
            areaRG(i,j);
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
        //init();
        solve();
        cout<<"#"<<test<<" "<<R+G+B<<" "<<RG+B<<"\n";

    }
    
    return 0;
}