/*
    [programmers] 2017 카카오코드 예선 카카오프렌즈 컬러링북 * BFS
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
*/
#include <vector>
#include <queue>

using namespace std;

typedef struct {
    int x,y;
}pos;


int calculateArea(int m,int n, int x,int y,vector<vector<int>> &pic){
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int color=pic[y][x];
    int area=1;
    queue<pos> q;
    
    pos first={x,y};
    q.push(first);
    pic[first.y][first.x]=0;//visit check

    while(!q.empty()){
        pos p = q.front(); q.pop();
        for(int d=0;d<4;++d){
            int nX = p.x+dx[d];
            int nY = p.y+dy[d];
            if(nX<0 ||nX>=n ||nY<0 ||nY>=m) continue;
            if(pic[nY][nX]!=color) continue;
            area++;
            pic[nY][nX]=0;
            pos nP={nX,nY};
            q.push(nP);
        }        
    }
    return area;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
   
    int temp=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            temp=0;
            if(picture[i][j]==0)continue;
            temp=calculateArea(m,n,j,i,picture);
            if(temp>0) number_of_area++;
            if(temp>max_size_of_one_area) max_size_of_one_area = temp;
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}