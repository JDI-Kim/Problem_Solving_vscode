/*
    BOJ #1987 알파벳; DFS
*/
#include <iostream>
#include <algorithm>

using namespace std;
int R,C;
const int maxR=20+1;
const int maxC=20+1;
char board[maxR][maxC];
typedef struct{
    int r,c;
}pos;
pos mal;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool visit[30];
int result;

void read(){
    cin>>R>>C;
    for(int i=0;i<R;++i){
        cin>>board[i];
    }
}
void init(){
    mal.r=0;
    mal.c=0;
    result=1;
    for(int i=0;i<30;++i){
        visit[i]=false;
    }   
}
void findmax(int count, pos pre){
    int charNum;
    for(int d=0;d<4;++d){
        int nR=pre.r+dy[d];
        int nC=pre.c+dx[d];
        if(nR<0||nR>=R||nC<0||nC>=C)continue;
        charNum=board[nR][nC]-'A';
        if(visit[charNum]) continue;
        visit[charNum]=true;
        int nCount=count+1;
        result=max(result,nCount);
        pos next={nR,nC};
        findmax(nCount,next);
        visit[charNum]=false;
    }
}
void solve(){

    int charNum=board[mal.r][mal.c]-'A';
    visit[charNum]=true;
    findmax(1,mal);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;

    for(int test=1;test<=Test;++test){
        read();
        init();
       
        cout<<"#"<<test<<"\n";
         solve();
        cout<<result<<"\n";
    }

    return 0;
}