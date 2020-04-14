#include <iostream>
using namespace std;
const int maxN=8;
const int maxM=8;
int N;
int M;
bool visit[maxN+1];
//int num[maxM+1];
char arr[(maxM+1)*2];

void read(){
    cin>>N>>M;
}
void init(){
    for(int i=1;i<=N;++i){
        visit[i]=false;
    }
    for(int i=0;i<M*2;++i){
        arr[i]=' ';
    }
}
void printresult(){
    for(int i=0;i<M;++i){
        cout<<num[i]<<" ";
    }
    cout<<"\n";
}
void printarr(){
    cout<<arr<<"\n";
}
void solve(int count){
   if(count==M){
       //printresult();
       printarr();
       return;
   }
   for(int i=1;i<=N;++i){
       if(visit[i]) continue;
       visit[i]=true;
       //num[count]=i;
       arr[count*2]=i+'0';
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
        
        cout<<"#"<<test<<"\n";
        solve(0);
        cout<<"\n\n";
    }
    return 0;
}