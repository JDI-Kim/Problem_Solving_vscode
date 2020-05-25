/*
    [Hackerrank] Day 18. queue and stack. Palindrome. 앞으로 읽으나 뒤로 읽으나 같은 문자열 판단은 큐에 넣고 스택에 넣어서 하나씩 비교하면 된다.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    //Write your code here
    vector<char> s;
    vector<char> q;
    int sHead=0;
    int sTail=0;
    int qHead=0;
    int qTail=0;
    
    public: 
    void pushCharacter(char ch){
        s.push_back(ch);
        sTail++;
    }

    void enqueueCharacter(char ch) {
        q.push_back(ch);
        qTail++;
    }

    char popCharacter() {
        if(qTail==0) {cout<<"stack is empty.\n"; return '\0';}
        qTail--;
        return s[qTail];
    }
    char dequeueCharacter() {
        if(qHead==qTail){cout<<"Queue is empty.\n"; return '\0';}
        char ret = q[qHead];
        qHead++;
        return ret;
    }
};

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}