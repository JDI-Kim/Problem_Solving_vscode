/*
    [programmers] 2018 KAKAO BLIND RECRUITMENT [1차] 프렌즈4블록 ** 인덱스 틀리는 소리 좀 안나게 해라~~~
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
// void printState(int m,int n, vector<string> &board, vector<vector<bool> >  &visit){
//     for(int i=0;i<m;++i){
//         for(int j=0;j<n;++j){
//             cout<<visit[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
//     cout<<"\n";

//       for(int i=0;i<m;++i){
//         for(int j=0;j<n;++j){
//             cout<<board[i][j]<<" ";
//         }
//         cout<<"\n";
//       }
//         cout<<"\n";

// }
void init(int m,int n, vector<vector<bool> >  &visit){
    visit.clear();
    for(int i=0;i<m;++i){
        vector<bool> v;
        for(int j=0;j<n;++j){
            v.push_back(false);
        }
        visit.push_back(v);
    }
}
void checkBoard(int &m, int &n, vector<string> &board, vector<vector<bool> >  &visit){
    char c;
    for(int j=n-1;j>0;--j){    //폭    
        for(int i=m-1;i>0;--i){//높이
            c=board[i][j];
            if(board[i][j]=='0') break;
            if(board[i][j-1]!=c) continue;
            if(board[i-1][j]!=c) continue;
            if(board[i-1][j-1]!=c) continue;
            visit[i][j]=true;
            visit[i][j-1]=true;
            visit[i-1][j]=true;
            visit[i-1][j-1]=true;
        }
    }
}
int removeTrue(int &m, int &n, vector<string> &board, vector<vector<bool> >  &visit){
    int cnt=0;
     for(int j=n-1;j>=0;--j){    //폭    
        for(int i=m-1;i>=0;--i){//높이
            if(board[i][j]=='0') break;//이 위로는 검사 안해도 됨
            if(!visit[i][j]) continue;

            board[i][j]='0';
            visit[i][j]=false;
            cnt++;
        }
     }

    for(int j=n-1;j>=0;--j){    //폭    
     queue<int> q;
        for(int i=m-1;i>=0;--i){//높이
            if(board[i][j]=='0'){ q.push(i); continue;}
            //board[i][j]빈칸이 아니라면
            if(q.empty())continue;
            //빈칸이 있다면
            board[q.front()][j]=board[i][j];
            q.pop();
            board[i][j]='0';
            q.push(i);
        }
    }

    return cnt;

}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<bool> > visit;
    init(m,n,visit);
    int cnt=1;
    
   
    while(cnt>0){
        checkBoard(m,n,board,visit);
        cnt=removeTrue(m,n,board,visit);
        answer+=cnt;
    }
    
    return answer;
}
int main(void){
    int T;
    cin>>T;
    for(int t=1;t<=T;++t){
        cout<<"#"<<t<<" "<<"\n";
        int m;
        int n; 
        vector<string> board;
        string str;
        cin>>m>>n;
        for(int i=0;i<m;++i){
            cin>>str;
            board.push_back(str);
        }
        cout<< solution(m,  n, board)<<"\n";

    }
    return 0;
}