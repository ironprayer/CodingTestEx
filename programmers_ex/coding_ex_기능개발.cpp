#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day(progresses.size(), 0);
    int tmp, count, index = 0;
    
    for(int i = 0; i < progresses.size(); i++)
    {
        tmp = progresses[i];
        count = 0;
        
        while(tmp < 100)
        {
            tmp += speeds[i];
            count++;
        }
        day[i] = count;
    }
    
    tmp = day[index++];
    count = 1;
    while(index < day.size())
    {
        cout << tmp << endl;
        if(tmp >= day[index])
        {
            count++;
            index++;
        }
        else{
            tmp = day[index++];
            answer.push_back(count);
            count = 1;
        }
        
    }
    
    answer.push_back(count);

    return answer;
}