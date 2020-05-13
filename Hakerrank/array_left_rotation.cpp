/*
    [Hackerrank] Practice > Interview Preparation Kit > Arrays > Arrays: Left Rotation
    * mod %
    from: https://www.hackerrank.com/interview/interview-preparation-kit/arrays/challenges
*/
#include <iostream>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the rotLeft function below.
vector<int> rotLeft(vector<int> a, int d) {
    vector<int> b=a;
    int n = a.size();
    for(int i = 0; i < n; ++i){
        a[(i+n-d)%n]=b[i];
    }
    return a;
}

int main()
{
    int n,d;

    cin>>n>>d;

    string a_temp_temp;;


    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item ;
        cin>>a_item;

        a[i] = a_item;
    }

    vector<int> result = rotLeft(a, d);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";


    return 0;
}
