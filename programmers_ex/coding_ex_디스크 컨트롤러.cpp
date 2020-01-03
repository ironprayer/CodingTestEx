#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool vc_cmp(vector<int> v1, vector<int> v2)
{
	if(v1[0] < v2[0])
		return true;
    else
        return false;
}
class pq_cmp{
public:    
    bool operator()(vector<int> v1, vector<int> v2)
    {
        if(v1[1] > v2[1])
            return true;
        else
            return false;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
	int time = 0, t_start, t_end, flag = 0;
    priority_queue<vector<int>, vector<vector<int>>, pq_cmp> pq;

    //jobs을 시작 시간을 기준으로 오름차순 정렬한다. 
    sort(jobs.begin(), jobs.end(), vc_cmp);
	
	for(int i = 0; i < jobs.size(); i++)
	{
        
		t_start = jobs[i][0];
		t_end = jobs[i][1];
		
		if(pq.empty())
		{
			time += t_start + t_end;
			answer += t_end;
            pq.push({t_start, t_end});
            flag = 1;
            continue;
		}
		
		if(t_start <= time)
		{
			pq.push({t_start, t_end});
		}
		else
		{
            /*
            if(pq.empty())
                continue;
            */

            if(flag == 0)
            {
			    time += pq.top()[1];
			    answer += time - pq.top()[0];
            }
            else
                flag = 0;
			pq.pop();
		}
    }
	
	while(!pq.empty())
	{

        if(flag == 0)
        {
		    time += pq.top()[1];
		    answer += time - pq.top()[0];
        }else
            flag = 0;
		pq.pop();
	}
    
    return answer / jobs.size();
}