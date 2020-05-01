/*
    programmers 2019 KAKAO BLIND RECRUITMENT 실패율 * 정렬, 0으로 나누기, 자료형
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN=500+2;

typedef struct{
    int stageNum;
    int failplayer;
    int player;
    float failureRatio;
}info;

bool operator<(info a, info b){
    if(a.failureRatio==b.failureRatio) return a.stageNum<b.stageNum;
    else return a.failureRatio>b.failureRatio;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    info I[maxN];
    int sz=stages.size();
    for(int i=0;i<=N+1;++i){
        I[i].stageNum=i;
        I[i].failplayer=I[i].player=I[i].failureRatio=0;
    }
    for(int i=0;i<sz;++i){
        int curS=stages[i]-1;
        I[curS].failplayer++;
        for(int j=0;j<=curS;++j) {
            I[j].player++;
        }            
    }
    for(int i=0;i<N;++i){
        if(I[i].player==0){ continue;}
        I[i].failureRatio=(float)I[i].failplayer/(float)I[i].player;
    }
    sort(I,I+N);
    for(int i=0;i<N;++i){
        answer.push_back(I[i].stageNum+1);
    }
    return answer;
}