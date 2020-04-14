#include <iostream>
using namespace std;
int N,M;
const int maxN=8;
const int maxM=8;
int result =0;
int num[maxM+1];
char arr[(maxM+1)*2];

void read(){
    cin>>N>>M;
}
void init(){
    for(int i=0;i<=M;++i){
        num[i]=0;
    }
    // for(int i=0;i<2*M;++i){
    //     arr[i]=' ';
    // }
}
void printresult(){
    for(int i=0;i<M;++i){
        cout<<num[i]<<" ";
    }
    cout<<"\n";
}
void solve(int count, int idx){
    if(count==M){
        printresult();
        //cout<<arr<<"\n";
        return;
    }
    if(idx>N){
        return;
    }
    for(int i=idx;i<=N;++i){
        num[count]=i;
        //arr[count*2]=i+'0';
        solve(count+1,i+1);
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
        solve(0,1);
    }
    return 0;
}