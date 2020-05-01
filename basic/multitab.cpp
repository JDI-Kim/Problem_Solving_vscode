/*
    BOJ #1700. 멀티탭 스케쥴링. **나중에 쓸 것 부터 빼면 됨.. 많이 쓰는걸 두는 게 아니라.
*/

#include <iostream>
#include <queue>
using namespace std;
int N, K;
const int maxN=100+1;
const int maxK=100+1;

int input[maxK];
int nxt[maxK][maxK];
int cnt[maxK];
int num[maxK];
int plugNum;
bool isPlugged[maxK];
int result=0;

void init(){
    plugNum=0;//nothing is plugged
    result=0;
    for(int i=0;i<=K;++i){
        isPlugged[i]=false;
        cnt[i]=0;
        num[i]=0;
        for(int j=0;j<=K;++j){
            nxt[i][j]=0;
        }
    }
}
void read(){
    cin>>N>>K;
    init();
    for(int i=0;i<K;++i){
        cin>>input[i];
        nxt[input[i]][cnt[input[i]]++]=i;
    }   
    
}
int findSmallCNT(){
    int minName=-1;
    int uselater=-1;
    for(int i=1;i<=K;++i){
        if(!isPlugged[i])continue;
        if(cnt[i]==num[i]){return i;}
        if(nxt[i][num[i]]>uselater){
            uselater=nxt[i][num[i]];
            minName=i;
        }
    }
    return minName;
}
void solve(){
    if(K==1) return;
    if(N>=K) return;
    int firstFull=0;
    for(int i=0;i<K;++i){
        num[input[i]]++;
        if(isPlugged[input[i]]) continue;
        isPlugged[input[i]]=true;       
        plugNum++;
        if(plugNum==N){ firstFull = i; break;}
    }
    for(int i=firstFull+1; i<K;++i){
        num[input[i]]++;
        if(isPlugged[input[i]]) continue;
        int temp=findSmallCNT();
        isPlugged[temp]=false;
        isPlugged[input[i]]=true; 
        result++;
    }
    
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;
    for(int test=1;test<=Test;++test){
        read();
        solve();
        cout<<"#"<<test<<" "<<result<<"\n";
    }
    return 0;
}
