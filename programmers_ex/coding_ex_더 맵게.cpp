#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int min;
    priority_queue <int, vector<int>, greater<int>> pq;
    
    //min heap에 모든 스코빌 값을 넣음.
    for(int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    
    while( (min = pq.top()) < K)
    {
        pq.pop();
        
        //모든 음식의 스코빌 지수를 K이상으로 만들 수 없는 경우
        if(pq.empty())
        {
            return -1;
        }
        
        pq.push(min + (pq.top() * 2));
        pq.pop();
        answer++;
    }
    
    return answer;
}