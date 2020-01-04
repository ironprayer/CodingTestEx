#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int count = 0, num;
    char ch;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    priority_queue<int, vector<int>> max_pq;
    
    for(int i = 0; i < operations.size(); i++)
    {
        ch = operations[i][0];
        num = atoi(operations[i].substr(2, operations[i].size() - 2).c_str());
        
        switch(ch)
        {
            case 'I':
                min_pq.push(num);
                max_pq.push(num);
                count++;
                break;
            case 'D':
                if(count == 0)
                {
                    break;
                }
                else if(num == 1)
                {
                    max_pq.pop();
                }
                else
                {
                    min_pq.pop();
                }
                count--;
        }
    
    }
    
    if(count == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(max_pq.top());
        answer.push_back(min_pq.top());
    }
    
    return answer;
}