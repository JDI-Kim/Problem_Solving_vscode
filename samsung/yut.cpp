#include <iostream>
#include <algorithm>

using namespace std;
const int maxN = 10;
int test[4];
int input[maxN];
                // 0  1  2  3  4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20, 
int scores[33] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 
                //  21  22  23
                    13, 16, 19,
                //  24  25
                    22, 24, 
                //  26  27  28
                    28, 27, 26, 
                //  29  30  31 32
                    25, 30, 35, 0};

                  // 0  1  2  3  4  5   6   7   8   9   10   11  12  13  14  15    16  17  18  19  20,  21  22  23  24  25  26  27  28  29              
int path[4][30] = { {0, 1, 2, 3, 4, 5,  6,  7,  8,  9,  10,  11, 12, 13, 14, 15,   16, 17, 18, 19, 20,  32, -1, -1, -1, -1, -1, -1, -1, -1},
                    {0, 1, 2, 3, 4, 5,  21, 22, 23, 29, 30,  31, 20,     32, -1,   20, 20, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                    {0, 1, 2, 3, 4, 5,  6,  7,  8,  9,  10,  24, 25, 29, 30, 31,   20,     32, 20, 20,  20, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                    {0, 1, 2, 3, 4, 5,  6,  7,  8,  9,  10,  11, 12, 13, 14, 15,   26, 27, 28, 29, 30,  31, 20,     32, 20, 20, 20, -1, -1, -1}
                  };

           
int maxScore = 0;
int malPos[4];
int malRoute[4];
const int limitRoute[4]={ 21, 13, 17, 23};

void read(){
    for(int i=0; i<10; ++i){
        cin>>input[i];
    }
}

void init(){
    maxScore = 0;
    for(int i = 0 ; i< 4; ++i){
        malPos[i]=0;
        malRoute[i]=0;

        test[i]=0;
    }
}

bool canMove(int count, int mal){
    int curPos = malPos[mal];
    int R = malRoute[mal];
    if(curPos == limitRoute[R] ) return false; //goal position;

    
    int walk = input[count];
    if( R==0) {
        if(curPos == 5 ){ R = 1; }
        else if(curPos == 10){ R = 2; }
        else if(curPos == 15){ R = 3; }
    } 
    int nxtPos = min( curPos + walk, limitRoute[R]);
    
    if(nxtPos < limitRoute[R]){
        for(int i = 0; i<4; ++i)
        {
            if(i == mal)continue;
            if(path[R][nxtPos] == path[malRoute[i]][malPos[i]]) return false;
        }
    }
    malPos[mal] = nxtPos;
    malRoute[mal] = R;    

    return true;
}

void selectMal(int count, int curScore){

    if(count == 10){
        // for(int i =0 ;i<4; ++i){
        //     cout<<test[i]<<" ";
        // }
        // cout<<"\n";
        maxScore = max(maxScore, curScore);
        return;
    }

    for(int i = 0; i < 4; ++i){
        int prevPos = malPos[i];
        int prevR = malRoute[i];
        test[i]++;
        if(canMove(count, i)){                  
            int num = path[malRoute[i]][malPos[i]];
            selectMal(count+1, curScore + scores[num] );            
        }
        malPos[i] = prevPos;
        malRoute[i] = prevR;
        test[i]--;
       
    }

}
void solve(){
    selectMal(0,0);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Test;
    cin>>Test;

    for(int test = 1; test<=Test; ++test){
        read();
        init();
        solve();
        cout<<maxScore<<"\n";
    }
    
    return 0;
}