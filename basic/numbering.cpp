/*
    BOJ #2667. 단지나누기 DFS
    
*/
#include<iostream>
#include<algorithm>

using namespace std;
int N;
const int maxN=25+1;
char map[maxN][maxN];
int total;
const int maxH=maxN*maxN/2+1;
int numH[maxH];

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void read(){
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>map[i];
    }
    cout<<N;
}
void init(){
    total=0;
    for(int i=0;i<maxH;++i){
        numH[i]=0;
    }    
}
void findNear(int i, int j){
    for(int d=0;d<4;++d){
        int nI=i+dy[d];
        int nJ=j+dx[d];
        if(nI<0 ||nI>=N ||nJ<0 ||nJ>=N){ continue;}
        if(map[nI][nJ]=='0')continue;
        map[nI][nJ]='0';
        numH[total]++;
        findNear(nI,nJ);
    }
}
void solve(){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(map[i][j]=='0')continue;
            map[i][j]='0';///visit
            numH[total]=1;
            findNear(i,j);
            total++;
        }
    }
    sort(numH,numH+total);
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

        cout<<"#"<<test<<" "<<total<<"\n";
        
        for(int i=0;i<total;++i){
            cout<<numH[i]<<"\n";
        }

    }
    return 0;
}