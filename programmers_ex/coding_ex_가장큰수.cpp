
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
두 번째 답안(해결)
compare함수로 문자 벡터 정렬한다.
  ->문자를 더해 비교한다. 더 큰 경우 TRUE 반환
answer에 문자 벡터를 반복문을 통해 더해준다.
answer[0] == '0'일 경우 "00000*"인 것을 나타내므로 "0"을 반환해준다.
*/

bool compare(string& str1, string& str2)
{
    if(str1+str2 > str2+str1)
        return true;
    else
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_v;
    for(int i = 0; i < numbers.size(); i++)
    {
        str_v.push_back(to_string(numbers[i]));
    }
    
    sort(str_v.begin(), str_v.end(), compare);
    
    for(int i = 0; i < str_v.size(); i++)
    {
        answer += str_v[i];
    }
    
    if (answer[0] == '0')
        return "0";
    
    return answer;
}


/*
처음 답안(시간 초과)
swap과 perm 함수를 사용해 순열을 구한다.
sort 함수로 내림차순으로 정렬한다.
*/

void swap(vector<int>& nums, int index1, int index2)
{
    int temp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
}

vector<string> perm(vector<int>& nums, int depth, int n, int k)
{
    static vector<string> str_v;
    if(depth == k)
    {
        string str;
        for(int i = 0; i < nums.size(); i++)
        {
            str += to_string(nums[i]);
        }
        str_v.push_back(str);
        
    }
    
    for(int i = depth; i < n; i++)
    {
        swap(nums, i, depth);
        perm(nums,depth + 1, n, k);
        swap(nums, i, depth);
    }
    
    return str_v;
}


string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_v = perm(numbers, 0, numbers.size(), numbers.size());
    
    sort(str_v.begin(), str_v.end(), greater<string>());
    
    answer = str_v[0];
    
    return answer;
}

