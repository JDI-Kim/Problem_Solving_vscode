/*
    BOJ #1987 알파벳; DFS a bit optimized
*/
#include <iostream>

using namespace std;
int R,C;
const int maxR=20+2;
const int maxC=20+2;
char board[maxR][maxC]={0,};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool visit[200];
int result;

void read(){
    cin>>R>>C;
    for(int i=0;i<=R+1;++i){
       for(int j=0;j<=C+1;++j){
           board[i][j]=0;
       }
    }
    for(int i=1;i<=R;++i){
        cin>>&(board[i][1]);
    }
}
void init(){
    result=1;
    for(int i=0;i<200;++i){
        visit[i]=false;
    }   
}
void findmax(int r, int c,int count){
    if(result<count)result=count;
    
    if(!visit[board[r+1][c]]){
        visit[board[r+1][c]]=true;
        findmax(r+1,c,count+1);
        visit[board[r+1][c]]=false;
    }
    if(!visit[board[r-1][c]]){
        visit[board[r-1][c]]=true;
        findmax(r-1,c,count+1);
        visit[board[r-1][c]]=false;
    }
    if(!visit[board[r][c+1]]){
        visit[board[r][c+1]]=true;
        findmax(r,c+1,count+1);
        visit[board[r][c+1]]=false;
    }
    if(!visit[board[r][c-1]]){
        visit[board[r][c-1]]=true;
        findmax(r,c-1,count+1);
        visit[board[r][c-1]]=false;
    }

}
void solve(){

    visit[board[1][1]]=true;
    visit[0]=true;
    findmax(1,1,1);
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