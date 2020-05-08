/*
   
    [programmers]  2019 카카오 개발자 겨울 인턴십 불량 사용자 **index 주의..
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

*/
#include <string>
#include <vector>

using namespace std;
void makeList(int count, int nB,int nU, vector<vector<int>> candidates, vector<bool> visit,vector<vector<bool>> &pList){
    if(count==nB){
        //중복체크하고 
        int sz=pList.size();
        int result=0;
        bool possible=true;
        for(int i=0;i<sz;++i){
            result=0;
            for(int j=0;j<nU;++j){
                if(pList[i][j]!=visit[j]){ result++;break;}//다른게 있으면 가능.
            }
            if(result==0) {possible=false;break;}//같았으면 불가능.
        }
        if(possible) pList.push_back(visit);
        return;
    }
    for(int i=0;i<candidates[count].size();++i){
        if(visit[candidates[count][i]]) continue;
        visit[candidates[count][i]]=true;
        makeList(count+1,nB,nU,candidates,visit,pList);
        visit[candidates[count][i]]=false;
        
    }
}
bool canbeBan(string u, string b){
    int b_sz=b.size();
    int u_sz=u.size();
    if(u_sz!=b_sz) return false;
    for(int i=0;i<b_sz;++i){
        if(b[i]=='*') continue;
        if(b[i]!=u[i]) return false;
    }
    return true;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int nU=user_id.size();
    int nB=banned_id.size();
    vector<vector<bool>> pList;
    vector<bool> visit;
    vector<vector<int>>  candidates;
    for(int i=0;i<nU;++i){
        visit.push_back(false);
    }
    for(int b=0;b<nB;++b){
        vector<int> v;        
        for(int u=0;u<nU;++u){
            if(canbeBan(user_id[u],banned_id[b])){
                v.push_back(u);
            }
        }
        candidates.push_back(v);
    }
    makeList(0,nB,nU,candidates,visit,pList);
    
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