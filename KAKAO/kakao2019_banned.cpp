/*
   
    [programmers]  2019 카카오 개발자 겨울 인턴십 불량 사용자 **index 주의..
    * set을 쓸 줄 알면 좋구나....
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

*/
#include<iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool canbeBan(string u, string b){
    if(u.size()!=b.size()) return false;
    for(int i=0;i<b.size();++i){
        if(b[i]=='*' || b[i]==u[i]) continue;
        return false;
    }
    return true;
}
void makeList(int count, vector<bool>visit, vector<vector<int> > cand, set<string> &pList){
    if(count==cand.size()){
         bool result=false;
         string str="";
        for(int i=0;i<visit.size();++i){
            str+=visit[i]+'0';
        }
        if(pList.find(str)==pList.end()) pList.insert(str);
        return;
    }
    for(int i=0;i<cand[count].size();++i){
        if(visit[cand[count][i]]) continue;
        visit[cand[count][i]]=true;
        makeList(count+1,visit,cand,pList);
        visit[cand[count][i]]=false;
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<int> > cand;
    set<string> pList;
    vector<bool>visit;
    for(int i=0;i<user_id.size();++i){
        visit.push_back(false);
    }
    for(int i=0;i<banned_id.size();++i){
        vector<int> v;
        for(int j=0;j<user_id.size();++j){
            if(canbeBan(user_id[j],banned_id[i])){
                v.push_back(j);
            }
        }
        cand.push_back(v);
    }

    makeList(0,visit,cand,pList);
    answer=pList.size();
    return answer;
}

int main(void){
    int Test;
    cin>>Test;
   
    for(int test=1;test<=Test;++test){
        cout<<"#"<<test<<"\n";
        int u,b;
        vector<string> user_id; 
        vector<string> banned_id;

        string str;
        cin>>u>>b;
        for(int i=0;i<u;++i){
            cin>>str;
            user_id.push_back(str);
        }
         for(int i=0;i<b;++i){
            cin>>str;
            banned_id.push_back(str);
        }
        cout<<solution(user_id,banned_id)<<"\n";;
    }
    return 0;
}