#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int val = 1001, count = 0, index = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> is_visitied(jobs.size(), 0);
    
    //가장 처음 시작되는 작업 찾기
    for(int i = 0; i < jobs.size(); i++)
    {
        if(val > jobs[i][0])
        {
            val = jobs[i][0];
            index = i;
        }else if(val == jobs[i][0])
        {
            if(jobs[index][1] - jobs[index][0] > jobs[i][1] - jobs[i][0])
            {
                index = i;
            }
        }
    }
    
    answer = jobs[index][1] - val;
    is_visitied[index] = 1;
    val = jobs[index][1];
    count++;
    
    
    while(count < jobs.size())
    {
        if(val >=  )
    }
    
    
    
    
    
    return answer;
}