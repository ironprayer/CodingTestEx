#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int quote_num = 0;
    
    sort(citations.begin(), citations.end());
    
    
    for(int i = 0; i < citations.size(); i++)
    {
        quote_num = citations[i];
        if(quote_num <= i + 1 && quote_num > citations.size()- i - 1)
        {
            answer = quote_num;
        }
    }
    
    answer = citations.size();
    
    return answer;
}