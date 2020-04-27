/*
    BOJ #2661 좋은 수열 **
*/
#include <iostream>
using namespace std;
int N;
const int maxN=80;
int arr[maxN];
void read(){
    cin>>N;
}
bool isBad(int count){
    int half=(count+1)/2;
    for(int len=1;len<=half;++len){
        bool isBad=true;
        for(int check=0;check<len;++check){
            if(arr[count-check]!=arr[count-len-check]) {
                isBad=false; break;
            }
        }
        if(isBad) return true;
    }
    return false;
}
bool findArr(int count){
    if(count==N){
        for(int i=0;i<N;++i){
            cout<<arr[i];
        }
        cout<<"\n";
        return true;
    }
    for(int i=1;i<=3;++i){
        if(arr[count-1]==i)continue;
        arr[count]=i;
        if(isBad(count)) continue;
        if(findArr(count+1)) return true;
    }
    return false;

}
void solve(){
    if(N==1) { cout<<1;return;}
    for(int i=1;i<3;++i){
        arr[0]=i;
        if(findArr(1))return;
    }

}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;

    for(int test=1;test<=Test;++test){
        read();
        cout<<"#"<<test<<" "<<"\n";
        solve();
        cout<<"\n";

    }
    return 0;
}