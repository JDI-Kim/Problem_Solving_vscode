/*
    BOJ #3649 로봇프로젝트 *예외처리로 개선한 코드 예외처리시 false인 경우만 걸러낼 것!
    *테스트케이스 갯수가 주어지지 않은 경우 while(cin>>a)를 쓰면됨
    *정렬과 이진탐색. 
*/
#include <iostream>
#include <algorithm>
using namespace std;
int x,n;
const int maxN=1000000;
int l1[maxN];
int l2[maxN];
int cnt1,cnt2;
int ans1,ans2;
int halfcnt;
void read(){
    cin>>n;
    x*=10000000;
    int temp;
    cnt1=cnt2=0;
    ans1=ans2=-1;
    int half=x/2;
    halfcnt=0;
    for(int i=0;i<n;++i){

        cin>>temp;
        if(temp>x){ continue; }
        
        if(temp<half) l1[cnt1++]=temp;
        else if(temp>half) l2[cnt2++]=temp;
        else halfcnt++;
    }
    if(halfcnt>=2){l1[cnt1++]=half;l2[cnt2++]=half;}
    sort(l1,l1+cnt1);
    sort(l2,l2+cnt2);
}
bool search(int goal,int first, int last){
    if(first>last) return false;
    int mid=(first+last)/2;
    if(l2[mid]==goal) return true;
    if(l2[mid]<goal) return search(goal,mid+1,last);
    if(goal<l2[mid]) return search(goal,first,mid-1);
    return false;
}
bool solve(){
    int goal;
    if(n==0) return false;
    //if(l1[cnt1-1]+l2[cnt2-1]==x) {ans1=l1[cnt1-1]; ans2=l2[cnt2-1];return true;} //false인 경우만 걸러낼 것
    if(l1[cnt1-1]+l2[cnt2-1]<x) return false;
    if(l1[0]+l2[0]>x)return false;
    for(int i=0;i<cnt1;++i){
        goal=x-l1[i];
        if(search(goal,0,cnt2-1)){
            ans1=l1[i];
            ans2=goal;
            return true;
        }
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