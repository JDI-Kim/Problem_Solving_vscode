#include <iostream>
#include <algorithm>

using namespace std;
const int N=5;
char c[N];
int n[N];
int numbers[10];
int colors[4];
int score;

bool isCont;
bool c_state;
int n_state[5];


void read(){
    for(int i=0;i<4;++i){
        colors[i]=0;
    }
    for(int i=0;i<10;++i){
        numbers[i]=0;
    }
    for(int i=0;i<N;++i){
        cin>>c[i] >>n[i];
        numbers[n[i]]++;
        if(c[i]=='R') {colors[0]++;continue;}
        if(c[i]=='B') {colors[1]++;continue;}
        if(c[i]=='Y') {colors[2]++;continue;}
        if(c[i]=='G') {colors[3]++;continue;}
    }
}
void init(){
    score=0;
    isCont=false;
    c_state=false;
    for(int i=0;i<5;++i){
        n_state[i]=-1;
    }
}
void findCstate(){
    for(int i=0;i<4;++i){
        if(colors[i]==5){
            c_state=true;
            break;
        }
    }
}
void findCont(){
 if(   n[0]+1 ==n[1] && n[1]+1 ==n[2] 
    && n[2]+1 ==n[3] && n[3]+1 ==n[4])
    isCont=true;
}
void findNstate(){
    for(int i=1; i<10; ++i){
        if(numbers[i]==4){n_state[4]=i;return;}
        if(numbers[i]==3){n_state[3]=i;}
        if(numbers[i]==2){
            if(n_state[2]==-1)  n_state[2]=i;
            else { n_state[0]=i;  return;}
        }
    }
}
int solve(){
    //5장 모두 같은색이고 연속인경우
   sort(n,n+N);
    findCont();
    findCstate();
    
    if(c_state&&isCont){
        return n[4]+900;
    }
    //4장의 숫자가 같은 경우
    findNstate();
    if(n_state[4]>0){
        return  n_state[4]+800;
    }
    if(n_state[3]>0 && n_state[2]>0){
       return n_state[3]*10+n_state[2]+700;
    }
    if(c_state){
        return n[4]+600;
    }
    if(isCont){
        return n[4]+500;
    }
    if(n_state[3]>0){
        return n_state[3]+400;
    }
    if(n_state[0]>0){
        return max(n_state[0],n_state[2])*10+min(n_state[0],n_state[2])+300;
    }
    if(n_state[2]>0){
        return n_state[2]+200;
    }
    return n[4]+100;
    //3장의 숫자 같고 2장의 숫자 같은 경우
    //5장 같은 색인경우
    //5장 연속인경우
    //3장의 숫자같고 2장의 숫자는 다른 경우
    //2장의 숫자같고 2장의 숫자 같은 경우
    //2장의 숫자 같은 경우
    //어느것도 아닌 경우
    
    
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Test;
    cin>>Test;
    for(int  test=1;test<=Test;++test){
        read();
        init();
        score=solve();
        cout<<"#"<<test<<" "<<score<<"\n";
    }
    return 0;
}