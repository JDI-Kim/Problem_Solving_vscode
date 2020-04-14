/*
BOJ #15649. N과 M (1)
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
- 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

Imput
- 첫째 줄에 테스트케이스 개수 T가 주어진다
- 둘째 줄부터 T줄만큼 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

Output
- # 테스트케이스 숫자로 시작한다
- 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
- 수열은 사전 순으로 증가하는 순서로 출력해야 한다.

sample_input.txt
3
3 1
4 2
4 4
*/
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
// void printresult(){
//     for(int i=0;i<M;++i){
//         cout<<num[i]<<" ";
//     }
//     cout<<"\n";
// }
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