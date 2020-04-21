/*
    BOJ #7562  나이트의 이동 **BFS. 불필요한 움직임을 가지치기 하면 훨씬 빠름.
*/
#include<iostream>
#include<queue>
using namespace std;
int L;
const int maxL=300;
int visit[maxL][maxL];
typedef struct{
    int x,y;
}pos;
pos start,last;
int num;
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};


void read(){
    cin>>L >>start.x>>start.y >>last.x>>last.y;
}
void init(){
    num=0;
    for(int i=0;i<L;++i){
        for(int j=0;j<L;++j){
            visit[i][j]=0;
        }
    }
    
}
void solve(){
    queue<pos> q;
    q.push(start);
    visit[start.y][start.x]=1;
    while(!q.empty()){
        pos p = q.front();q.pop();
        for(int d=0;d<8;++d){
            //optimized
            if(dx[d]<0){//내가 왼쪽에 있는데 왼쪽으로 가거나 
                if(p.x< last.x-2)continue;
            }else{//내가 오른쪽에 있는데 오른쪽으로 가거나 
                if(p.x>last.x+2)continue;
            }
            if(dy[d]<0){//내가 위에 있는데 위로 가거나
                if(p.y<last.y-2) continue;
            }else{//내가 아래에 있는데 아래로 가거나
                if(p.y>last.y+2) continue;
            }
            
            int nX=p.x+dx[d];
            int nY=p.y+dy[d];
            if(nX<0 ||nX>=L ||nY<0 ||nY>=L){ continue; }
            if(visit[nY][nX]>0) continue;
            

            if(nY==last.y && nX ==last.x){ num=visit[p.y][p.x]; return;}

            visit[nY][nX]=visit[p.y][p.x]+1;
            pos nP = {nX,nY};
            q.push(nP);
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
        init();
        solve();

        cout<<"#"<<test<<" "<<num<<"\n";
    }
    return 0;
}