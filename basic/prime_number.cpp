#include <iostream>
#include <string>

using namespace std;
int N;
const int maxN=1000000;

void read(){
    cin>>N;
}
bool isPrime(int n){
    if(n%2==0) return false;
    for(int i=3;i<n;i+=2){
        if(n%i==0) return false;
    }
    return true;
}

bool isPal(int num){
    if(num<10) return true;
    string str=to_string(num);
    int size=str.size();
    for(int i=0;i<=(size/2);++i){
        if(str.at(i)!=str.at(str.size()-i-1)) return false;
    }
    return true;
}
int solve(){
    int num;
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