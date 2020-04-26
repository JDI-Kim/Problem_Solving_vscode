/*
    BOJ #2529. 부등호
*/
#include <iostream>
using namespace std;
int K;
const int maxK=9+1;
char input[maxK];
int output[maxK];
bool visit[maxK];
void read(){
    cin>>K;
    for(int i=0;i<K;++i){
        cin>>input[i];

    }
}
void init(){
    for(int i=0;i<10;++i){
        visit[i]=false;
        output[i]=-1;
    }
}
bool check(int index,int num){
    if(input[index]=='<'){
        return output[index] < num;
    }else{
        return output[index] > num;
    }    
}
bool findMin(int count){
    if(count==K+1) {
        for(int i=0;i<=K;++i){
            cout<<output[i];
        }
        cout<<"\n";
        return true;
    }
    for(int i=0;i<10;++i){
        if(visit[i])continue;
        if(!check(count-1,i)) continue;
        output[count]=i;
        visit[i]=true;
        if(findMin(count+1)) return true;
        visit[i]=false;
    }

    return false;
}
bool findMax(int count){
     if(count==K+1) {
        for(int i=0;i<=K;++i){
            cout<<output[i];
        }
        cout<<"\n";
        return true;
    }
    for(int i=9;i>=0;--i){
        if(visit[i])continue;
        if(!check(count-1,i)) continue;
        output[count]=i;
        visit[i]=true;
        if(findMax(count+1)) return true;
        visit[i]=false;
    }
    return false;
}
void solve(){

    init();

    for(int i=9;i>=0;--i){
        output[0]=i;
        visit[i]=true;
        if(findMax(1)) break;
        visit[i]=false;
    }
    init();

    for(int i=0;i<10;++i){
        output[0]=i;
        visit[i]=true;
        if(findMin(1)) break;
        visit[i]=false;
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
        cout<<"#"<<test<<" "<<"\n";
    }
    return 0;
}