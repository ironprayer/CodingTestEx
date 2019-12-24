#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> r_answer;
    int receive;
    for(int i = heights.size()-1; i >= 0; i--)
    {
        receive = 0;
        for(int j = i - 1; j >= 0; j--)
        {
            if(heights[i] < heights[j])
            {
                receive = j + 1;
                break;
            }
        }
        r_answer.push(receive);
    }
    
    while(!r_answer.empty()){
        answer.push_back(r_answer.top());
        r_answer.pop();
    }
    
    return answer;
}