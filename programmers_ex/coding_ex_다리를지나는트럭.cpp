/*
* 처음 답안
*
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    queue<int> q;
    int index = 0, cur_index = 0, count = 0;
    int weight_total = 0;
    
    while(cur_index < truck_weights.size())
    {
        /* 큐안에 있는 값과 answer 값 확인
        if(!q.empty())
            cout << q.front() << "," << answer << endl;
        */
        if(q.size() == bridge_length)
        {
            weight_total -= q.front();
            q.pop();
            
            if(weight_total + truck_weights[cur_index] <= weight)
            {
                answer += 1;
                q.push(truck_weights[cur_index++]);
                continue;
            }
        }
        
        if(weight_total + truck_weights[cur_index] > weight)
        {
            weight_total -= q.front();
            q.pop();
            count = 0;
        }
        else
        {

            weight_total += truck_weights[cur_index];
            if(count == 0)
            {
                answer += bridge_length - q.size();
                count = 1;
            }
            else
            {
                answer += 1;
            }
            q.push(truck_weights[cur_index++]);
            
        }
              
    }
    return answer;
}