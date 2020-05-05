/*

*/
#include<iostream>
#include <string>
#include <vector>

using namespace std;
bool checkKey(int numH_lock,vector<vector<int> > &key, vector<vector<int> > &lock ){
    int ckNum=numH_lock;
    int lockSz=lock.size();
    int keySz=key.size();
    int transLimit=keySz-1;
    
 
    for(int transY= -transLimit; transY <lockSz;++transY){
        for(int transX= -transLimit; transX<lockSz; ++transX){
            bool check=true;
            ckNum=numH_lock;
            for(int y=0;y<keySz;++y){
                int lockY=y+transY;
                if(lockY<0 || lockY>=lockSz) continue;
                for(int x=0;x<keySz;++x){
                    int lockX=x+transX;
                    if(lockX<0 || lockX>=lockSz) continue;
                    if(key[y][x]!=lock[lockY][lockX]){  check= false;break;} 
                    if(lock[lockY][lockX]==0) ckNum--;
                }
                if(check==false)break;
            }
            if(check&&ckNum==0) return true;
        }
    }
  
    return false;
    
}
void rotateKey(vector<vector<int> > &key,vector<vector<int> > &newkey){
    
    int keySZ=key.size();
    for(int i=0;i<keySZ;++i){
        for(int j=0;j<keySZ;++j){
            key[j][keySZ-i-1]=newkey[i][j];
            
        }
    }
}
bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
    bool answer = true;
    int numH_lock=0;
    int numD_key=0;
    int lockSz=lock.size();
    int keySz=key.size();
    
    for(int i=0;i<lockSz;++i){
        for(int j=0;j<lockSz;++j){
            if(lock[i][j]==0)numH_lock++;
        }
    }
    for(int i=0;i<keySz;++i){
        for(int j=0;j<keySz;++j){
            if(key[i][j]==0){ key[i][j]=1; continue;}
            key[i][j]=0; numD_key++;
        }
    }
    
    if(numD_key<numH_lock) return 0;
    int rot=0;
    while(!checkKey(numH_lock,key,lock)){ 
        if(rot==3) return false;
        vector<vector<int> > newkey=key;
        rotateKey(key,newkey);
        rot++;
    }    
    return answer;
}
int main(void){
    int T;
    cin>>T;
    for(int test=1;test<=T;++test){
        cout<<"#"<<test<<"\n";
        int n;
        int k,l;
        cin>>n;
        vector<vector<int> > key;
        vector<vector<int> > lock;
        for(int i=0;i<n;++i){
            vector<int> kk;
            for(int j=0;j<n;++j){
                
                cin>>k;
                kk.push_back(k);

            }
            key.push_back(kk);
        }        

        for(int i=0;i<n;++i){
            vector<int> ll;
            for(int j=0;j<n;++j){                
                cin>>l;
                ll.push_back(l);
            }
            lock.push_back(ll);
        }        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){                
                cout<<key[i][j]<<" ";                
            }
            cout<<"\n";
        }  
      for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){                
                cout<<lock[i][j]<<" ";                
            }
            cout<<"\n";
        } 
        cout<<solution(key, lock)<<"\n";
    }
    return 0;
}