/*
    BOJ #1697 숨바꼭질. BFS. 
    **  범위 바깥은 가지칠 것. 메모리를 많이 쓰고싶지 않으면 큐에 넣기 전에 판단해서 끝내버릴 것
*/
#include<iostream>
#include<queue>
using namespace std;
int N,K;
const int maxN=100001;
bool visit[maxN];
typedef struct {
    int X;
    int tm;
}pos;
void read(){
    cin>>N>>K;
}

void init(){
    for(int i=0;i<maxN;++i){
        visit[i]=false;
    }
}
int move(int X,int d){
    if(d==0) return X+1;
    else if (d==1) return X-1;
    else return X*2;
}
int solve(){
    if(N==K) return 0;
    queue<pos> q;
    pos initPos={N,0};
    q.push(initPos);
    visit[N]=true;

    while(!q.empty()){
        pos p = q.front();q.pop();
        int X= p.X; int tm=p.tm;
        for(int d=0;d<3;++d){
            int nX=move(X,d);
            if(nX<0 || nX>100000 || visit[nX]) continue;
            if(nX==K) { return tm+1;}
            visit[nX]=true;
            pos nP={nX,tm+1};
            q.push(nP);            
        }

    }
    return -1;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;

    for(int test=1;test<=Test;++test){
        read();
        init();
        int result=solve();

        cout<<"#"<<test<<" "<<result<<"\n";
    }
    return 0;
}