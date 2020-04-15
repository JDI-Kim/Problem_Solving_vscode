/*
BOJ #1747. 소수&팰린드롬
어떤 수와 그 수의 숫자 순서를 뒤집은 수가 일치하는 수를 팰린드롬이라 부른다. 예를 들어 79,197과 324,423 등이 팰린드롬 수이다.
어떤 수 N (1 ≤ N ≤ 1,000,000)이 주어졌을 때, N보다 크거나 같고, 소수이면서 팰린드롬인 수 중에서, 가장 작은 수를 구하는 프로그램을 작성하시오.

입력
- 첫째 줄에 N이 주어진다.

출력
- 첫째 줄에 조건을 만족하는 수를 출력한다.

예제 입력 1 
 31
예제 출력 1 
 101
*/

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