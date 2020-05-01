/*
    programmers 2019 카카오 개발자 겨울 인턴십: 크레인 인형뽑기 게임 
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
*/
#include <string>
#include <vector>

using namespace std;
const int maxN=30+1;

int solution(vector<vector<int>> board, vector<int> moves) {
    int result=0;
    int cnt[maxN];
    int N= board.size();
    vector<int> baguni;
    //find position of first items in each col;
    for(int col=0;col<N;++col){
        cnt[col]=N;
        for(int row=0;row<N;++row){
            if(board[row][col]==0)continue;
            cnt[col]=row;
            break;
        }
    }
    
    int sz=moves.size();
    for(int k=0;k<sz;++k){
        int col=moves[k]-1;
        if(cnt[col]==N) continue;
        int item=board[cnt[col]][col];
        board[cnt[col]][col]=0;
        cnt[col]++;
        //put to baguni
        if(baguni.empty()){baguni.push_back(item);continue;}
        if(baguni.back()==item){result+=2; baguni.pop_back();continue;}
        baguni.push_back(item);
    }
    
    return result;
}