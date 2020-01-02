#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int cur_index = 0;
    priority_queue<int, vector<int>> pq;
    
    //key point : datas에 들어있는 날짜는 오름차순 정렬되어 있습니다.
    
    while(stock < k)
    {
        //1.stock보다 작은 날짜의 공급량을 힙에 넣는다.
        //2.stock < 날짜일 때 최대값을 뽑는다.
        //3.반복문을 벗어날 때까지 1,2번을 반복한다.
        if(stock < dates[cur_index])
        {
            stock += pq.top();
            pq.pop();
            answer++;
        }
        else
        {
            pq.push(supplies[cur_index++]);
        }
    }
    return answer;
}