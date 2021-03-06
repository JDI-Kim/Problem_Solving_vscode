/*
BOJ #15654. N과 M (5) 중복허용 안하고 순서 있는 뽑기
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.
- N개의 자연수 중에서 M개를 고른 수열

Imput
- 첫째 줄에 테스트케이스 개수 T가 주어진다
- 둘째 줄부터 각 테스트 케이스가 주어진다.
- 각 테스트케이스 첫째줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
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

#include<iostream>
#include<algorithm>

using namespace std;

int N,M;
const int maxN=8;
const int maxM=8;
int num[maxN];
bool visit[maxN];
int output[maxM];

void read(){
    cin>>N>>M;
    for(int i=0;i<N;++i){
        cin>>num[i];
    }
}  

void init(){
    for(int i=0;i<N;++i){
        visit[i]=false;
    }
    //sorting
    sort(num,num+N);
}
void printResult(){
    for(int i=0;i<M;++i){
        cout<<output[i]<<" ";
    }
    cout<<"\n";
}
void solve(int count){
    if(count==M){
        printResult();
        return;
    }
    for(int i=0;i<N;++i){
        if(visit[i]) continue;
        visit[i]=true;
        output[count]=num[i];
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
    }
    return 0;
}
