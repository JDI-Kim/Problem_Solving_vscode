/*
    [programmers] 2018 KAKAO BLIND RECRUITMENT 다트게임  *예외처리 잘 하기.
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
*/
#include <string>

using namespace std;
const int maxN=3;
int solution(string dartResult) {
    int answer = 0;
    int score[maxN]={0,0,0};
    int sz=dartResult.size();
    int cnt=-1;
    bool star[3]={false,false,false};
    
    for(int i=0;i<sz;++i){
        switch(dartResult[i]){
            case 'S': break;
            case 'D':  score[cnt]*=score[cnt]; break;
            case 'T':  score[cnt]*=score[cnt]*score[cnt]; break;
            case '#':  score[cnt]*= -1; break;
            case '*':  star[cnt]=true;  break;
            case '1': if(dartResult[i+1]=='0'){score[++cnt]=10; i++; break;}
                    else{score[++cnt]=1;break;}
            default: score[++cnt]=dartResult[i]-'0';
        }
    }
    for(int i=0;i<maxN;++i){
        if(star[i]){ 
            score[i]*=2; 
            if(i==0)continue;
            score[i-1]*=2;
        }
    }
    for(int i=0;i<maxN;++i){
        answer+=score[i];
    }
    
    return answer;
}