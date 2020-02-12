#include<iostream>
#include<algorithm>
using namespace std;
int info[10];
int point[33]={
    0,//0
    2,4,6,8,10, 12,14,16,18,20, 22,24,26,28,30, 32,34,36,38, //1~19
    13,16,19,//20~22
    22,24, //23,24
    28,27,26,//25~27
    25,30,35,//28~30
    40,//31
    0//32
};
int route[4][24]={
    {0,1,2,3,4,5, 6,7,8,9,10, 11,12,13,14,15,   16,17,18,19,31,32, 0,0},
    {0,1,2,3,4,5, 20,21,22,   28,29,30,31,32,0,0,0,0,0,0,0,0,0,0},
    {0,1,2,3,4,5, 6,7,8,9,10, 23,24,   28,29,30,31,32,0,0,0,0,0,0},
    {0,1,2,3,4,5, 6,7,8,9,10, 11,12,13,14,15,   25,26,27,28,29,30,31,32}
};
int mal[4]; //has the index of points //pan
int mal_route[4];
int maxScore;
struct _mal{
    int R;
    int I;
};
_mal M[4];
void read(){
    for(int i=0;i<10;++i){
        cin>>info[i];
    }
}
bool existOn(int mal,_mal temp){
    for(int i=1;i<4;++i){
        int index= (mal+i)%4;
        if(route[M[index].R][M[index].I]==route[temp.R][temp.I]){
            return true;
        }
    }
    return false;
}
bool canMove(int mal, int move){
    _mal temp=M[mal];
    int curPos=route[M[mal].R][M[mal].I];
    if(curPos==32) return false;
    //check if it is on the corner
    if(curPos==5){ temp.R=1; temp.I=5;}
    else if(curPos==10){ temp.R=2; temp.I=10;}
    else if(curPos==15){temp.R=3;temp.I=15;}

    //move
    if(temp.R==0){temp.I=min(temp.I+move,21);}
    else if(temp.R==1){temp.I=min(temp.I+move,13);}
    else if(temp.R==2){temp.I=min(temp.I+move,17);}
    else if(temp.R==3){temp.I=min(temp.I+move,23);}

    int nxtPos=route[temp.R][temp.I];
    if(nxtPos==32) {
        M[mal]=temp;
        return true;
    }
    if(existOn(mal,temp)){
        return false;
    }else{
        M[mal]=temp;
        return true;
    }   
}
void printMal(){
    for(int i=0;i<4;++i){
        cout<<"Mal["<<i<<"]="<<point[route[M[i].R][M[i].I]]<<" ";
    }
    cout<<"\n";
}
void solve(int start,int sum){
    if(start==10){
        maxScore=max(maxScore,sum);
        return;
    }
   for(int j=0;j<4;++j){
       _mal curMal=M[j];
        if(canMove(j,info[start])){
           // printMal();
          //  cout<<"sum: "<<sum+point[route[M[j].R][M[j].I]]<<"\n\n";
            solve(start+1,sum+point[route[M[j].R][M[j].I]]);
            
        }
        M[j]=curMal;
    } 
}
int main(void){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int t=0;t<T;++t){
        read();
        for(int i=0;i<4;++i){
            M[i].R=0;M[i].I=0;
        }
        maxScore=0;
        solve(0,0);
        cout<<"#"<<t<<" "<<maxScore<<"\n";
    }
    return 0;
}