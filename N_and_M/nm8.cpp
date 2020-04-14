
/*
BOJ #15657. N과 M (8) 중복되고 순서 없고 비내림차순
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

N개의 자연수 중에서 M개를 고른 수열
- 같은 수를 여러 번 골라도 된다.
- 고른 수열은 비내림차순이어야 한다.
- 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

Imput
- 첫째 줄에 테스트케이스 개수 T가 주어진다
- 둘째 줄부터 각 테스트 케이스가 주어진다.
- 각 테스트케이스 첫째줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)
- 각 테스트케이스 둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

Output
- # 테스트케이스 숫자로 시작한다
- 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
- 수열은 사전 순으로 증가하는 순서로 출력해야 한다.

sample_input.txt
3
3 1
4 5 2
4 2
9 8 7 1
4 4
1231 1232 1233 1234
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
const int maxN=8;
const int maxM=8;
int input[maxN];
int output[maxM];

void read(){
    cin>>N>>M;
    for(int i=0;i<N;++i){
        cin>>input[i];
    }
}
void init(){
    sort(input,input+N);
}
void printResult(){
    for(int i=0;i<M;++i){
        cout<<output[i]<<" ";
    }
    cout<<"\n";
}
void solve(int count, int startI){
    if(count==M){
        printResult();
        return;
    }
    for(int i=startI;i<N;++i){
        output[count]=input[i];
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

        cout<<"#"<<test<<" "<<"\n";
        solve(0,0);
    }

    return 0;
}