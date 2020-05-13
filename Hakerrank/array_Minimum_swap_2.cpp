/*
    [Hackerrank] Practice > Interview Preparation Kit > Arrays > Minimum Swap 2
    ** 배열에 들어있는 값이 배열크기보다 작고, 중복되지 않으면 다른 배열 만들어서 그 위치를 저장해서 바로 쓸 수도 있음....제발.
    from: https://www.hackerrank.com/interview/interview-preparation-kit/arrays/challenges
*/
#include <iostream>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.

int minimumSwaps(vector<int> arr) {
    int sz= arr.size();
    int result=0;
    vector<int> pos(sz+1);
    for(int i=0;i<sz;++i){
        pos[arr[i]]=i;
    }
    for(int i=0;i<sz;++i){
        if(arr[i]==i+1)continue;
        int temp= arr[i];
        arr[i]=arr[pos[i+1]];
        arr[pos[i+1]]=temp;
        pos[temp]=pos[i+1];
        pos[i+1]=i;
        result++;
    }
    return result;
}

int main()
{

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin>>arr_item;

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    cout << res << "\n";


    return 0;
}
