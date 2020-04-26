#include <iostream>

using namespace std;
int N, K;
const int maxN=100;
const int maxK=100;
int input[maxK];
int minResult;
bool isPlugged[maxK+1];
int plug[maxN];
int numPlug;
void read(){
    cin>>N>>K;
    for(int i=0;i<K;++i){
        cin>>input[i];
    }
}
void init(){
    minResult=1000;
    numPlug=0;
    for(int i=1;i<=K;++i){
        isPlugged[i]=false;
    }
    for(int i=0;i<N;++i){
        plug[i]=0;
    }
}
int findInput(int startI){
    for(int i=startI;i<K;++i){
        if(isPlugged[input[i]])continue;
        return i;
    }
    return -1;
}
void solve(int index, int unpplug){
    int I=findInput(index);
    if(I==-1){
        if(minResult>unpplug){
            minResult=unpplug;
        }
        return;
    }
    if(numPlug<N) {
        isPlugged[input[I]]=true;
        plug[numPlug]=input[I];
        numPlug++;
        solve(I+1, unpplug);
        return;
    }
   
    for(int i=0;i<N;++i){
        int p=plug[i];
        isPlugged[input[I]]=true;
        isPlugged[p]=false;
        plug[i]=input[I];
        solve(I+1,unpplug+1);
        plug[i]=p;
        isPlugged[p]=true;
        isPlugged[input[I]]=false;
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
        solve(0,0);
        cout<<"#"<<test<<" "<<minResult<<"\n";
    }
    return 0;
}
