#if 1
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void v_sort(vector<pair<double, int>>&);

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<int> no_clear;
	vector<pair<double, int>> temp;
	int stages_all_user = stages.size();
	no_clear.assign(stages.size(), 0);

	for (int i = 0; i < stages.size(); i++)
	{
		no_clear[stages[i] - 1] += 1;
	}

	for (int i = 0; i < N; i++)
	{
		if (stages_all_user == 0)
		{
			temp.push_back(make_pair(0, i + 1));
			continue;
		}

		temp.push_back(make_pair(static_cast<double>(no_clear[i]) / stages_all_user, i + 1));
		stages_all_user -= no_clear[i];
	}

	v_sort(temp);
	//sort(temp.begin(), temp.end(),[](pair<double,int> a, pair<double,int> b){return a.first>b.first;});
	//sort(temp.begin(), temp.end(),[](pair<double,int> a, pair<double,int>b){return a==b;});
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i].first << ", " << temp[i].second << endl;
		answer.push_back(temp[i].second);
	}

	return answer;
}

//버블정렬을 사용했다.
void v_sort(vector<pair<double, int>>& failure_rate)
{
	pair<double, int> temp;
	int v_size = failure_rate.size();

	for (int i = 0; i < v_size; i++)
	{
		for (int j = v_size - 1; j > i; j--)
		{
			if (failure_rate[j - 1].first < failure_rate[j].first)
			{
				temp = failure_rate[j];
				failure_rate[j] = failure_rate[j - 1];
				failure_rate[j - 1] = temp;
			}
		}
	}
}
#endif

#if 0
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> temp;
    int no_clear_count = 0;
    int stages_all_count = 0;
    
    for(int i = 1; i< N+1; i++)
    {
        for(int j = 0; j < stages.size(); j++)
        {
            if(stages[j] == i)
            {
                no_clear_count++;
                stages_all_count++;
            }
            else if(stages[j] > i)
            {
                stages_all_count++;
            }
        }
        if(stages_all_count != 0)
        {
            temp.push_back(make_pair(static_cast<double>(no_clear_count) / stages_all_count, i));

        }
        else
        {
            temp.push_back(make_pair(0,i));
        }
        
        no_clear_count = 0;
        stages_all_count = 0;
    }
    sort(temp.begin(), temp.end(),[](pair<double,int> a, pair<double,int> b){return a.first>b.first;});
    //sort(temp.begin(), temp.end(),[](pair<double,int> a, pair<double,int>b){return a==b;});
    for(int i = 0; i <temp.size(); i++)
    {
        answer.push_back(temp[i].second);
    }
    
    return answer;
}
#endif