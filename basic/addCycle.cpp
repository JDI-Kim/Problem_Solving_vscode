/* 
    BOJ #1110. 더하기 사이클
*/
#include <iostream>
using namespace std;
int N;
int result;
void read(){
    cin>>N;
}
void init(){
    result=1;
}
void solve(){
    int n1=N/10;
    int n2=N%10;
    int s=n1+n2;
    int newN=n2*10+(s%10);

    while(newN!=N){
        result++;
        n1=newN/10;
        n2=newN%10;
        s=n1+n2;
        newN=n2*10+(s%10);
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
        solve();
        cout<<"#"<<test<<" "<<result<<"\n";
    }
    return 0;
}