/*
    [Hackerrank] Practice > Interview Preparation Kit > Arrays > 2D Array - DS
    from: https://www.hackerrank.com/interview/interview-preparation-kit/arrays/challenges
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Complete the hourglassSum function below.

int hourglassSum(vector<vector<int> > arr) {
    int result=INT_MIN;
    int sz = arr.size();
    int temp=0;
    for(int i=0;i<sz-2;++i){
        for(int j=0;j<sz-2;++j){
            temp=arr[i][j]+arr[i][j+1]+arr[i][j+2]
                +arr[i+1][j+1]
                +arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            if(temp>result) result=temp;
        }
    }
    return result;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int> > arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    cout << result << "\n";

    

    return 0;
}
