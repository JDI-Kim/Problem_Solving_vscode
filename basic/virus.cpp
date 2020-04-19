/*
 BOJ #2606 바이러스
*/
#include <iostream>
using namespace std;
int com,M;
const int maxCom=100+1;
bool network[maxCom][maxCom];
bool visit[maxCom];
int result;

void init(){
    result=0;//1번 걸렸으니까
    for(int i=1;i<=com;++i){
        visit[i]=false;
    }
    for(int i=1;i<=com;++i){
        for(int j=1;j<=com;++j){
            network[i][j]=false;
        }
    }
}
void read(){    
    cin>>com>>M;
    init();
    int a,b;
    for(int i=1;i<=M;++i){
        cin>>a>>b;
        network[a][b]=network[b][a]=true;
    }
}
void solve(int i){
    for(int j=1;j<=com;++j){
        if(!network[i][j]) continue;
        if(visit[j]) continue;
        visit[j]=true;
        result++;
        solve(j);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;
    for(int test=1; test<=Test;++test){
        read();
        visit[1]=true;
        solve(1);
        cout<<"#"<<test<<" "<<result<<"\n";
    }


    return 0;
}