/*
 BOJ #2309 일곱난쟁이
*/
#include <iostream>
#include<algorithm>
using namespace std;
const int N=9;
int dwarfs[N];
int sum;
bool visit[N];

void read(){
    sum=0;
    for(int i=0;i<N;++i){
        cin>>dwarfs[i];
        sum+=dwarfs[i];
    }
}
void init(){
    for(int i=0; i<N;++i){
        visit[i]=true;
    }
}
void check(){
    for(int i=0;i<N;++i){
       int temp=sum-dwarfs[i];
       for(int j=i+1;j<N;++j){
            if(temp-dwarfs[j]!=100) continue; 
            visit[i]=false; visit[j]=false; 
            dwarfs[i]=101;dwarfs[j]=101;
            return;
       }
   }
}
void solve(){
   check();
   sort(dwarfs,dwarfs+9);
   for(int i=0;i<7;++i){
       cout<<dwarfs[i]<<"\n";
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
        
        cout<<"#"<<test<<" "<<"\n";
        solve();
    }
    return 0;
}