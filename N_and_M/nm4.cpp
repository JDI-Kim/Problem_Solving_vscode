/*
BOJ #15649. N과 M (4) 시작인덱스고려한 중복허용뽑기
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

- 1부터 N까지 자연수 중에서 M개를 고른 수열
- 같은 수를 여러 번 골라도 된다.
- 고른 수열은 비내림차순이어야 한다.
    길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

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
3 3
*/
#include <iostream>
using namespace std;
#define ARRMODE 1;
int N,M;
const int maxN=8+1;
const int maxM=8+1;
char arr[maxM*2];
int num[maxM];

void read(){
    cin>>N>>M;
}
void init(){
#ifdef ARRMODE
    for(int i=0;i<2*M;++i){
        arr[i]=' ';
    }

#else
    for(int i=0;i<M;++i){
        num[i]=0;
    }
#endif
}
void printResult(){
#ifdef ARRMODE
    cout<<arr<<"\n";
#else
    for(int i=0;i<M;++i){
        cout<<num[i]<<" ";
    }
    cout<<"\n";
#endif
}
void solve(int count,int startI){
    if(count==M){
        printResult();
        return;
    }
    for(int i=startI;i<=N;++i){
#ifdef ARRMODE
        arr[count*2]=i+'0';
#else
        num[count]=i;
#endif
        solve(count+1,i);
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