#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int index = 0, count, val, flag = 0;
    queue<int> q;
    vector<int> is_visited(priorities.size(), 0);
    
    
    while(true)
    {
        if(is_visited[index] == 1)
        {
            index++;
            continue;
        }
        
        if(index == priorities.size())
            index = 0;
        
        val = priorities[index];
        
        count = index + 1;
        
        while(count != index)
        {
            if(count == priorities.size())
                count = 0;
            
            if(is_visited[count]==1)
            {
                count++;
                continue;
            }
            
            if(val < priorities[count++])
            {
                flag = 1;
                break;
            }
        }
        
        if(flag == 0 && index == location)
        {
            answer = q.size() + 1;
            break;
        }
        else if(flag == 0)
        {
            is_visited[index] = 1;
            q.push(priorities[index]);
        }
        
        index++;
        flag = 0;
    }
    
    return answer;
}