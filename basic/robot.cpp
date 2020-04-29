/*
    BOJ #3649 로봇프로젝트 * 함수호출하지 않고 풀기
    *예외처리로 개선한 코드 예외처리시 false인 경우만 걸러낼 것!
    *테스트케이스 갯수가 주어지지 않은 경우 while(cin>>a)를 쓰면됨
    *정렬과 이진탐색. 
*/
#include <iostream>
#include <algorithm>
using namespace std;
int x,n;
const int maxN=1000000;
int l[maxN];
int cnt;
int ans1,ans2;

void read(){
    cin>>n;
    x*=10000000;
    int temp;
    cnt=0;
    ans1=ans2=-1;
    for(int i=0;i<n;++i){
        cin>>temp;
        if(temp>x){ continue; }
        l[cnt++]=temp;
    }
    sort(l,l+cnt);
     
}
bool solve(){
    int goal;
    if(n==0) return false;
    int half=x/2;
    int L=0;
    int R=cnt-1;
    while(L<R && l[L]<=half){
        goal=l[L]+l[R];
        if(goal==x){ans1=l[L];ans2=l[R];return true;}
        if(goal<x){L++;continue;}
        if(goal>x){R--;continue;}
    }
    return false;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>x){
        read();
        if(solve()){
            cout<<"yes "<<ans1<<" "<<ans2<<"\n";}
        else{
            cout<<"danger"<<"\n";
        }

    }
    return 0;
}