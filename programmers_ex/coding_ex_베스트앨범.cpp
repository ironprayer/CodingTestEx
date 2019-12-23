#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int add_suffix(int value, int index)
{
    return value * 10 + index;
}

int remove_suffix(int value)
{
    return value % 10;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    set<string> genre_kinds;
    set<int, greater<int>> genre_s;
    int total, count, index = 0;
    
    for(int i = 0; i < genres.size(); i++)
    {
        genre_kinds.insert(genres[i]);
    }
    
    vector<set<int>,greater<int>> play_v(genre_kinds.size(),set<int,greater<int>>());
    
    for(set<string>::iterator itr = genre_kinds.begin(); itr != genre_kinds.end(); itr++)
    {
        total = 0;
        for(int i = 0; i < genres.size(); i++)
        {
            if(*itr == genres[i])
            {
                total += plays[i];
                play_v[index].insert(add_suffix(plays[i],i));
            }
        }        
        genre_s.insert(add_suffix(total,index++));
    }
    
    for(set<int>::iterator itr = genre_s.begin(); itr != genre_s.end(); itr++)
    {
        index = remove_suffix(*itr);
        count = 0;
		set<int>::iterator itr2 = play_v[index].begin();
		if(play_v[index].size() == 1)
		{
			answer.push_back(remove_suffix(*itr2));
		}
		else if(play_v[index].size() == 2)
		{
			if(*itr2 == *(itr2+1) + 1)
			{
				answer.push_back(remove_suffix(*(itr2+1)));
				answer.push_back(remove_suffix(*itr2);
			}
			else
			{
				answer.push_back(remove_suffix(*itr2));
				answer.push_back(remove_suffix((*itr2+1)));
			}
		}
		else
		{
			for(set<int>::iterator itr2 = play_v[index].begin(); itr2 != (play_v[index].end()-1); itr2++)
			{
				if(count == 2)
					break;
				
				if(count == 3)
				{
					answer.pop_back();
					continue;
				}
            
				if(*itr2 == *(itr2 + 1) + 1)
				{
					answer.push_back(remove_suffix(*(itr2 + 1)));
					answer.push_back(remove_suffix(*itr2));
					count += 2;
				}
				else
				{
					answer.push_back(remove_suffix(*itr2));
				}
			}
        }
    }
    
    
    return answer;
}

-----------------------------------------------------------------------------------
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int add_suffix(int value, int index)
{
    return value * 10 + index;
}

int remove_suffix(int value)
{
    return value % 10;
}


//수정해야할 것 | 501과 503은 501+1 == 503이 성립이 안됨. 이 경우를 추가해야 한다.
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    set<string> genre_kinds;
    set<int, greater<int>> genre_s;
    int total, count, index = 0;
    
    for(int i = 0; i < genres.size(); i++)
    {
        genre_kinds.insert(genres[i]);
    }
    
    vector<set<int>> play_v(genre_kinds.size(),set<int>());
    
    for(set<string>::iterator itr = genre_kinds.begin(); itr != genre_kinds.end(); itr++)
    {
        total = 0;
        for(int i = 0; i < genres.size(); i++)
        {
            if(*itr == genres[i])
            {
                total += plays[i];
                play_v[index].insert(add_suffix(plays[i],i));
            }
        }        
        genre_s.insert(add_suffix(total,index++));
    }
    
    for(set<int>::iterator itr = genre_s.begin(); itr != genre_s.end(); itr++)
    {
        index = remove_suffix(*itr);
        count = 0;
		set<int>::reverse_iterator itr2 = play_v[index].rbegin();
        set<int>::reverse_iterator itr3 = play_v[index].rend();
        itr3--;
		if(play_v[index].size() == 1){
			answer.push_back(remove_suffix(*itr2));
		}
		else if(play_v[index].size() == 2)
		{
            
			if(*itr2++ == *itr2 + 1)
			{
				answer.push_back(remove_suffix(*itr2--));
				answer.push_back(remove_suffix(*itr2));
			}
			else
			{
                itr2--;
				answer.push_back(remove_suffix(*itr2++));
				answer.push_back(remove_suffix((*itr2)));
			}
            
		}
		else
		{
			for(itr2 = play_v[index].rbegin(); itr2 != itr3; itr2++)
			{
				if(count == 2)
					break;
				
				if(count == 3)
				{
					answer.pop_back();
					continue;
				}
            
				if(*itr2++ == *itr2+ 1)
				{
					answer.push_back(remove_suffix(*itr2--));
					answer.push_back(remove_suffix(*itr2));
					count += 2;
				}
				else
				{
					answer.push_back(remove_suffix(*--itr2));
				}
			}
            
        }
        
    }
    
    
    return answer;
}