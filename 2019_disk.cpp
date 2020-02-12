#include <iostream>
using namespace std;
const int maxN= 50+1;
const int maxM= 50+1;
const int maxT= 50+1;
int N;
int M;
int T;
struct info{
    int x;
    int d; //0:CW 1:CCW
    int k;
};
info I[maxT];
int disk[maxN][maxM];
int temp[maxN][maxM];

void read(){
    cin>>N>>M>>T;
    for(int i=1;i<=N;++i){
        for(int j=0;j<M;++j){
            cin>>disk[i][j];
        }
    }
    for(int i=1;i<=T;++i){
        cin>>I[i].x>>I[i].d>>I[i].k;
    }
}
void rotate(int t){
    int x= I[t].x;
    int d= I[t].d;//0: +1 1:-1
    int k= I[t].k;
    if(d==1){k*=-1;}

    for(int i=1;i<=N;++i){
        if(i%x!=0) continue;
        for(int j=0;j<M;++j){
            temp[i][(j+k+M)%M]=disk[i][j];
        }
    }
    for(int i=1;i<=N;++i){
        if(i%x!=0) continue;
        for(int j=0;j<M;++j){
            disk[i][j]=temp[i][j];
        }
    }
}
void adj(){
    bool check=false;
    for(int i=1;i<=N;++i){
        for(int j=0;j<M;++j){
            temp[i][j]=disk[i][j];
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=0;j<M;++j){
            if(temp[i][j]==0)continue;
            int right =(j+1 + M)%M;
            int left = (j-1 + M)%M;
            bool same=false;
            if(temp[i][j]==temp[i][right]) { same=true; disk[i][right]=0;}
            if(temp[i][j]==temp[i][left]) {same=true; disk[i][left]=0;}
            if(i>1 && temp[i][j]==temp[i-1][j]) {same=true; disk[i-1][j]=0;}
            if((i<N-1) && temp[i][j]==temp[i+1][j]) {same =true; disk[i+1][j]=0;}
            if(same){disk[i][j]=0;check=true;}
        }
    }
    if(!check){
        int sum=0;
        int count=0;
        for(int i=1;i<=N;++i){            
            for(int j=0;j<M;++j){
                if(disk[i][j]!=0){
                    sum+=disk[i][j];
                    count++;
                }
            }
        }

        if(count==0) return;
        float avg=(float)sum/count;
        for(int i=1;i<=N;++i){
            for(int j=0;j<M;++j){
                if(disk[i][j]==0)continue;
                if(disk[i][j]>avg){
                    disk[i][j]-=1;
                }
                else if(disk[i][j]<avg){
                    disk[i][j]+=1;
                }
            }
        }
    }
}
int sumDisk(){
    int sum=0;
    for(int i=1;i<=N;++i){
        for(int j=0;j<M;++j){
            sum+=disk[i][j];
        }
    }
    return sum;
}
int main(void){
    int Test;
    cin>>Test;
    for(int testcase=0;testcase<Test;++testcase){
        read();
        for(int t=1;t<=T;++t){
            rotate(t);
            adj();
        }
        cout<<"#"<<testcase<<" "<<sumDisk()<<"\n";
    }
    return 0;
}