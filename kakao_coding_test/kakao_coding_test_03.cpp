#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <map>

using namespace std;

/*
속성 1개가 후보키일 때 속성 조합에서 제외한다. 최소성이 갖춰지지 않는다.
속성을 조합할 때 속성의 최대 개수보다 하나 적어야 한다.

* 속성 1개가 후보키일 때 속성 조합에서 제외한다. => 어떻게 구현할꺼야? / index를 제외시켜줘야 하는데.
* 후보키가 되려면 중복된 값이 없어야 하기 때문에 중복체크를 해준다.
*/

int solution(vector<vector<string>> relation) {

	int answer = 0;
	int col = 0;
	int row = 0;
	int count = 0;
	int n = 0;
	int end_count;

	string temp_str = "";
	vector<int> col_use_info;
	vector<string> result_str;
	set<string> candidate_verify;

	col_use_info.assign( relation[0].size(),1);
	end_count = relation[0].size();

	while (count < end_count)
	{
		//count에 따라 스트링을 조합해야 한다.
		//vector<string> temp에 저장했다가 candidate_verify에 넘겨준다.

		//스트링을 count 개수만큼 조합해서 벡터에 넣는 것을 구현한다.
		for (int i = 0; i <= count; i++)
		{

			if (i == 0)
				temp_str += relation[col][n];
			else
				temp_str += relation[col][row + n];
			//조건문
		}

		//n++ // +1 , +2 , +3... 결정해주는 변수
		cout << count << "  : " << temp_str << endl;
		result_str.push_back(temp_str);
		temp_str.clear();

		if (col != relation.size() - 1)
		{
			col++;
			continue;
		}
		col = 0;

		if (col_use_info[n] != 0 && col_use_info[row + n] != 0)
		{
			//후보키 검증 ****************************************************
			for (int i = 0; i < result_str.size(); i++)
			{
				candidate_verify.insert(result_str[i]);
			}
			if (count == 0 && candidate_verify.size() == result_str.size())
			{
				col_use_info[row] = 0;
				answer += 1;
				end_count -= 1;
				cout << result_str[0]<< endl;
			}
			else if (candidate_verify.size() == result_str.size())
			{
				answer += 1;
				cout << result_str[0] << endl;
			}
			candidate_verify.clear();
			//************************************************************
		}

		result_str.clear();
		//if (row 상승 조건, n 상승 조건)
		if (row + n < relation[0].size() - 1)
		{
			n++;
			continue;
		}


		if (row < relation[0].size() - 1)
		{
			row++;
			n = 1;
			continue;
		}

		//*********************************************************
		if (row + 1 == relation[0].size())
		{
			count++;
			row = 0;
		}
	}


	return answer;
}



#if 0

for(int i = 0; i < relation[0].size())
	{
		for(int j = 0; j < relation.size(); j++)
		{
			candidate_verify.insert(relation[j][i]); 
		}
		
		if(candidate_verify.size() == relation.size())
		{
			col_sue_info[i] = 0;
			answer += 1;
		}
		
		candidate_verify.clear();
	}
	
	
	
	//후보키 검증 **********************************************
	for(int j = 0; j < relation.size(); j++)
	{
		candidate_verify.insert(relation[j][col]);
	}
		
	if(count == 0 && candidate_verify.size() == relation.size())
	{
		col_use_info[i] = 0;
		answer += 1;
		end_count -= 1;
	}
	else if(candidate_verify.size() == relation.size())
	{
		answer += 1;
	}
	col++;		
	candidate_verify.clear();
	//*******************************************************
#endif