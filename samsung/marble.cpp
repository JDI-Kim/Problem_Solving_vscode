#include<iostream>
#include <algorithm>
using namespace std;
const int maxN=10;
const int maxM=10;
int N;
int M;
char board[maxN][maxM];
typedef struct{
    int r,c;
}pos;
pos red;
pos blue;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int minCount=100;
void read(){
    minCount=100;
    cin>>N>>M;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>board[i][j];
            if(board[i][j]=='R'){
                red.r=i;
                red.c=j;
                board[i][j]='.';
            }else if(board[i][j]=='B'){
                blue.r=i;
                blue.c=j;
                board[i][j]='.';
            }
        }
    }
    
}

void nxtPosition(int d, pos cR, pos cB, pos& nR, pos& nB){ //current+d -->next pos
    nR=cR;
    nB=cB;
    while(board[nR.r][nR.c]=='.'){
        nR.r+=dy[d];
        nR.c+=dx[d];
    }
    while(board[nB.r][nB.c]=='.'){
        nB.r+=dy[d];
        nB.c+=dx[d];
    }
    //red==blue
    if(board[nB.r][nB.c]=='O') {return;}
    if(board[nR.r][nR.c]=='O') {return;}
    if(nR.r==nB.r &&nR.c==nB.c){
        if(cR.r<cB.r){  // R
                        // B
            if(d==2) //up
            { nR.r += 1; nB.r += 2 ; }
            if(d==3)//down
            { nR.r -= 2; nB.r -= 1 ; }

        }else if(cR.r>cB.r){ //B
                             //R
            if(d==2) //up
            { nR.r += 2; nB.r += 1 ; }
            if(d==3)//down
            { nR.r -= 1; nB.r -= 2 ; }

        }else if(cR.c<cB.c){ //R B
            if(d==0) //left
            { nR.c += 1; nB.c += 2 ; }
            if(d==1)//right
            { nR.c -= 2; nB.c -= 1 ; }

            
        }else if(cR.c>cB.c){ //B R
            if(d==0) //left
            { nR.c += 2; nB.c += 1 ; }
            if(d==1)//right
            { nR.c -= 1; nB.c -= 2 ; }
        }
    }else{
        nR.r -=dy[d];
        nR.c -=dx[d];
        nB.r -=dy[d];
        nB.c -=dx[d];
    }

}
void printMap( pos cR, pos cB){
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(cR.r==i && cR.c==j){
                cout<<"R ";
            }

            else if(cB.r==i && cB.c==j){
                cout<<"B ";
            }
            else{
                cout<<board[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
    
}
bool move(int count, pos cR, pos cB, int prevD){
    
    
    pos nR, nB;
    if(count>=10){
        return false;
    }
    for(int d=0;d<4;++d){
        if(prevD==d || prevD+d==1 || prevD+d==5) continue;
        //cout<<"direction: "<<d<<"\n";
        nxtPosition(d,cR,cB,nR,nB);
        //cout<<"count: "<<count+1<<"\n";
        //printMap(nR,nB);
        if(board[nB.r][nB.c]=='O') continue;
        if(board[nR.r][nR.c]=='O') { 
            minCount=min(minCount,count+1);
            return true;
        }
        if(nR.r==cR.r && nR.c==cR.c && nB.r==cB.r && nB.c==cB.c ) continue;
        move(count+1,nR,nB,d);
    }
    return false;
}
//red in hole : true;
//blue in hole : false;
//blue in hole+red in hole:false
//cannot move: end
int main(void){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int test=1;test<=T;++test){
        read();
            move(0,red,blue,8);
        
        if(minCount==100) minCount=-1;
        cout<<"#"<<test<<" "<<minCount<<"\n";
    }


    return 0;
}