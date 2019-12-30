#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
	stack<int> price_s;
	stack<int> time_s;
	int count = 0;
	int price;
	
	for(int i = 0; i < prices.size(); i++)
		answer.push_back(0);
	
	for(int i = 0 ; i < prices.size(); i++)
	{
		price = prices[i];
		
		if(price_s.empty())
		{
			price_s.push(price);
			time_s.push(i);
		}
		else{
			while(price_s.top() > price)
			{
				answer[time_s.top()] = i - time_s.top();
				price_s.pop();
				time_s.pop();
                
                if(price_s.empty())
                    break;
			}
			
			price_s.push(price);
			time_s.push(i);
		}
		
		if(i == prices.size() -1 )
		{
			while(!price_s.empty())
			{
				answer[time_s.top()] = i - time_s.top();
				price_s.pop();
				time_s.pop();
			}
			
		}
		
	}
	
    return answer;
}