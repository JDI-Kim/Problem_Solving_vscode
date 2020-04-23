/*
    BOJ #10819  차이를 최대로
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N;
const int maxN=8;
int arr[maxN];
int order[maxN];
bool visit[maxN];
int maxSum;
void read(){
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
}
void init(){
    maxSum=0;
}
void calculate(){
    int temp=0;
    for(int i=0;i<N-1;i++){
        temp+= abs(arr[order[i]]-arr[order[i+1]]);
    }
    maxSum=max(maxSum,temp);
} 
void printR(){
    for(int i=0;i<N;++i){
        cout<<order[i]<<" ";
    }
    cout<<"\n";
}
void solve(int count){
    if(count==N){
        printR();
        calculate();
        return;
    }
    for(int i=0;i<N;++i){
        if(visit[i])continue;
        visit[i]=true;
        order[count]=i;
        solve(count+1);
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
        init();
        solve(0);
        cout<<"#"<<test<<" "<<maxSum<<"\n";
    }
    return 0;
}