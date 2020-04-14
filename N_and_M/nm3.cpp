#include <iostream>
using namespace std;
int N,M;
const int maxN=7+1;
const int maxM=7+1;
char arr[maxM*2];

void read(){
    cin>>N>>M;
}
void init(){
    for(int i=0;i<M*2;++i){
        arr[i]=' ';
    }
}
void printResult(){
    cout<<arr<<"\n";
}
void solve(int count){
    if(count==M){
        printResult();
        return;
    }

    for(int i=1;i<=N;++i){
        arr[count*2]=i+'0';
        solve(count+1);

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

    }
    return 0;
}