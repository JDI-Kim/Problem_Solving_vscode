/*
    [programmers] 2018 KAKAO BLIND RECRUITMENT [1차] 추석 트래픽
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// S T 2000개
// 시작:S-(T-1) 끝: S
//T:1~3000
typedef struct{
    int ST;
    int ET;
}info;

void calculateTimes(info &in, string &s){
    //2016-09-15 21:00:00.966 0.381s
    //012345678901234567890123456789
    //2016-09-15 01:00:07.000 2s
    int HH = (s[11]-'0')*10 + (s[12]-'0');   
    int MM = (s[14]-'0')*10 + (s[15]-'0');   
    int SS = (s[17]-'0')*10 + (s[18]-'0');   
    int SSS = (s[20]-'0')*100 + (s[21]-'0')*10 + (s[22]-'0');   
    
    int T = s[24]-'0';
    int TTT = 0;
    if(s[25]=='s') TTT=0;
    else if(s[27]=='s') TTT = (s[26]-'0')*100;
    else if(s[28]=='s') TTT = (s[26]-'0')*100 + (s[27]-'0')*10;
    else if(s[29]=='s') TTT = (s[26]-'0')*100 + (s[27]-'0')*10 + (s[28]-'0');
    

    int ET = ((HH*60+MM)*60+SS)*1000+SSS;
    int time = T*1000+TTT;
    int ST = ET-(time-1);
    in.ST=ST; in.ET=ET;
    

}
void cntCase(int st, int et, vector<info> &I, int &answer){
    int sz= I.size();
    int cnt=0;

    for(int i=0;i<sz;++i){
        if(I[i].ET<st) continue;
        if(et<I[i].ST) continue;
        cnt++;
    }
    if(answer<cnt)answer=cnt;
}
int solution(vector<string> lines) {
    //cout<<"\n\nSTART\n";
    int answer = 0;
    int szL= lines.size();
    vector<info> I;
    for(int i=0;i<szL;++i){
       // cout<<i<<": ";
        info temp;
        calculateTimes(temp,lines[i]);
        I.push_back(temp);
       // cout<<I[i].ST<<"~"<<I[i].ET<<"\n";
    }
    int szI=I.size();
    int cnt=0;
    for(int i=0;i<szI;++i){
        cntCase( I[i].ST-999,  I[i].ST, I, answer);
        cntCase( I[i].ST,      I[i].ST+999, I, answer);
        cntCase( I[i].ET-999,  I[i].ET, I, answer);
        cntCase( I[i].ET,      I[i].ET+999, I, answer);
    }
    return answer;
}
int main(void){
    int T;
    cin>>T;
    for(int test=1;test<=T;++test){
        cout<<"#"<<test<<"\n";
        int n;
        cin>>n;
        vector<string> lines;
        string str1,str2,str3;
        for(int i=0;i<n;++i){       
            cin>>str1>>str2>>str3;
            lines.push_back(str1+" "+str2+" "+str3);
            
        }
        cout<<"ANS : "<<solution(lines)<<"\n";
    }
    return 0;
}