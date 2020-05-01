/*
    [programmers] Summer/Winter Coding(~2018) Level 1. 예산 * 정렬
    출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sz=d.size();
    sort(&d[0],&d[0]+sz);
    int temp;
    for(int i=0;i<sz;++i){
        budget-=d[i];
        if(budget<0)break;
        answer++;
    }
    return answer;
}