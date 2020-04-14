/*
BOJ #15651. N과 M (3) 순서 상관 없이 중복가능 뽑기
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
- 1부터 N까지 자연수 중에서 M개를 고른 수열
- 같은 수를 여러 번 골라도 된다.

Imput
- 첫째 줄에 테스트케이스 개수 T가 주어진다
- 둘째 줄부터 T줄만큼 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)

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
int N,M;
const int maxN=7+1;
const int maxM=7+1;
char arr[maxM*2];

void read(){
    cin>>N>>M;
}
void init(){
    for(int i=0;i<M*2;++i){ //여기가 자꾸 문제
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