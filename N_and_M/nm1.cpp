#include <iostream>
using namespace std;
const int maxN=8;
const int maxM=8;
int N;
int M;
bool visit[maxN+1];
int num[maxM+1];

void read(){
    cin>>N>>M;
    cout<<N<<" "<<M<<"\n";
}
void init(){
    for(int i=1;i<=N;++i){
        visit[i]=false;
    }
}
void printresult(){
    for(int i=0;i<M;++i){
        cout<<num[i]<<" ";
    }
    cout<<"\n";
}
void solve(int count){
   if(count==M){
       printresult();
       return;
   }
   for(int i=1;i<=N;++i){
       if(visit[i]) continue;
       visit[i]=true;
       num[count]=i;
       solve(count+1);
       visit[i]=false;
   }
}
int main(void){
    ios::sync_with_stdio(false);
    int Test;
    cin>>Test;
    for(int test=1;test<=Test;++test){
        read();
        init();
        
        cout<<"#"<<test<<"\n";
        solve(0);
        cout<<"\n\n";
    }
    return 0;
}