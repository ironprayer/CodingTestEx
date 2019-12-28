#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
	int flag = 1;
    char cur_brack;
    stack<char> st_char;
    
    for(int i = 0; i < arrangement.size(); i++)
    {
        cur_brack = arrangement[i];
		
        if(cur_brack == '(')
        {
            st_char.push(cur_brack);
            flag = 1;
            continue;
        }
		else
		{
			if(flag == 0)
			{
				answer += 1;
				st_char.pop();
			}
			else
			{
				st_char.pop();
				answer += st_char.size();
                flag = 0;
			}
		}

    }
    return answer;
}