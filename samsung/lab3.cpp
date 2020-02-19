#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
const int maxM=10;
const int maxN=50;
int N;
int M;
int mapInit[maxN][maxN];
int map[maxN][maxN];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int minTime=1000;
bool chosen[maxM];
struct pos{
    int r,c;
};
pos v[maxM];
queue<pos> q;
int vI;
int numEmpty;
int empty;
void read(){
     vI=0;
     numEmpty=0;
    cin>>N>>M;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>mapInit[i][j];
            if(mapInit[i][j]==0) {mapInit[i][j]= -3; //empty
                numEmpty++;
            }
            else if(mapInit[i][j]==1) mapInit[i][j]= -1; //wall
            else if(mapInit[i][j]==2) {mapInit[i][j]= -2; //inactive-virus
                v[vI].r=i;
                v[vI].c=j;
                vI++;
            }
        }
    }
}

void printMap(){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void copyInit(){
    empty=numEmpty;
     for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            map[i][j]=mapInit[i][j];
        }
     }
     
     
}
int activeVirus(){
     copyInit();
     while(!q.empty()){
         q.pop();
     }
    for(int i=0;i<vI;++i){
        if(chosen[i]==true){
            int cR=v[i].r;
            int cC=v[i].c;
            map[cR][cC]=0;
            q.push(v[i]);
        }        
    }
  
    int time=0;
    while(!q.empty() && empty!=0){
        pos p= q.front(); q.pop();
        int cR=p.r; int cC=p.c;
        for(int d=0;d<4;++d){
            int nR=cR+dy[d];
            int nC=cC+dx[d];
            if(nR<0 || nR>=N || nC<0 ||nC>=N) continue;
            if(map[nR][nC]==-1 ||map[nR][nC]>0) continue; //wall
            if(map[nR][nC]==-2 || map[nR][nC]==-3){//inactive or empty
               if(map[nR][nC]==-3) empty--;
                map[nR][nC]=map[cR][cC]+1;
                time=max(time,map[nR][nC]);
                pos nxt;
                nxt.r=nR;
                nxt.c=nC;
                q.push(nxt);  
                                      
            }
            if(empty==0) break;
        }
    }
   
    if(empty>0) time=1000;
    
    return time;
}
void printChosen(){
    cout<<"\n";
    for(int i=0;i<vI;++i){
        cout<<chosen[i]<<" ";
    }
    cout<<"\nmap:\n";

    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void choose(int count,int index){
    if(count==M){
        minTime=min(activeVirus(),minTime);        
        return;
    }
    else if(index==vI-1 &&count<M){ 
        return;
    }
    chosen[index]=true;
    choose(count+1,index+1);
    chosen[index]=false;
    choose(count,index+1);

}
void solve(){
    minTime=1000;

     for(int i=0;i<vI;++i){
         chosen[i]=false;
     }
    choose(0,0);
    
}

int main(void){
    ios::sync_with_stdio(false);

    int T;
    cin>>T;
    for(int test=0;test<T;++test){
        read();
        if(numEmpty==0)minTime=0;
        else{
            solve();
        if(minTime==1000) minTime=-1;}
        cout<<"#"<<test<<" "<<minTime<<"\n";
    }
    return 0;
}