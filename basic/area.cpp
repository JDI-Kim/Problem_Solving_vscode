/*
    BOJ #2583.영역구하기 dfs
*/
#include <iostream>
#include <algorithm>
using namespace std;
int M,N,K;
const int maxM=100+1;
const int maxN=100+1;
const int maxK=100+1;
int map[maxM][maxN];
typedef struct{
    int x1,y1;
    int x2,y2;
}rec;

rec R[maxK];
int numA;
int A[10000];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


void read(){
    cin>>M>>N>>K;
    for(int i=0;i<K;++i){
        cin>>R[i].x1>>R[i].y1>>R[i].x2>>R[i].y2;
    }
}

void init(){
    numA=0;
    for(int i=0;i<N*M;++i){
        A[i]=0;
    }
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            map[i][j]=0;
        }
    }
    for(int i=0;i<K;++i){
        for(int r=R[i].y1;r<R[i].y2;++r){
            for(int c=R[i].x1; c<R[i].x2;++c){
                map[r][c]= 1;
            }
        }
    }
}

void countA(int r, int c, int num){
    
    for(int d=0;d<4;++d){
        int nR=r+dy[d];
        int nC=c+dx[d];
        if(nR<0 ||nR>=M ||nC<0 ||nC>=N) continue;
        if(map[nR][nC]>0)continue;
        map[nR][nC]=1;
        A[num]++;
        countA(nR,nC,num);

    }
}
void solve(){
     for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            if(map[i][j]>0)continue;
            map[i][j]=1;
            A[numA]=1;
            countA(i,j,numA);
            numA++;
        }
     }
     sort(A,A+numA);

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
        cout<<"#"<<test<<" "<<numA<<"\n";
        for(int i=0;i<numA;++i){
            cout<<A[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}