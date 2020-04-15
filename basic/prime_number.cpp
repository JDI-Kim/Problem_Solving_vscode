#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int N;
const int maxN=1000000;
int cmp[7];
void read(){
    cin>>N;
    for(int i=0;i<7;++i){
        cmp[i]=0;
    }
}
bool isPrime(int n){
    int root=(int)sqrt(n);
    if(n%2==0) return false;
    for(int i=3;i<=root;i+=2){
        if(n%i==0) return false;
    }
    return true;
}

bool isPal(int num){
    if(num<10) return true;
    int size=0;
    for(size=0;num>0;++size){
        cmp[size]=(num%10);
        num=(int)num/10;
    }
    int halfsize=size/2;
    int size_1=size-1;
    for(int i=0;i<=halfsize;++i){
        if(cmp[i]!=cmp[size_1-i])return false;
    }
    return true;    
}
int solve(){
    int num;
    if(N==1){return 2;}//1은 소수가 아니래...
    if(N<=3){return N;}
    if(N%2==0) num=N+1;
    else num=N;

    while(true){
        
        if(isPal(num)&&isPrime(num)){            
            return num;
        }else{
            num+=2;
        }
    }

}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Test;
    cin>>Test;
    for(int test=1;test<=Test;++test){
        read();
        cout<<"#"<<test<<" "<<solve()<<"\n";
        
    }
    
    return 0;
}