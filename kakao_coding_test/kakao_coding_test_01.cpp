/* 
* kakao_coding_test_01.cpp
*
* user_id와 user_name을 저장하는 테이블을 만든다.
*
* record를 분리해 cmd, user_id, user_name의 값을 구한다.
*
* 명령어가 Enter입니까?
* cmd, user_id를 cmd_info 테이블에 저장한다.
* user_id, user_name을 user_info 테이블에 저장한다.
*
* 명령어가 Change입니까?
* user_info 테이블에 있는 user의 정보를 바꿔준다.
*
* 명령어가 Leave입니까?
* cmd, user_id를 cmd_info 테이블에 저장한다.
*
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<vector<string>> cmd_info;
    map<string,string> user_info;

	string cmd;
	string user_id;
	string user_name;

	for (int i = 0; i < record.size(); i++)
	{
		cmd = record[i].substr(0, record[i].find(' '));
		if (cmd != "Leave")
		{
			user_id = record[i].substr(record[i].find(' ') + 1, record[i].find(' ', record[i].find(' ') + 1) - record[i].find(' ') - 1 );
			user_name = record[i].substr(record[i].find(' ', record[i].find(' ') + 1) + 1);
		}
		else
		{
			user_id = record[i].substr(record[i].find(' ') +1);
		}

		if (cmd == "Enter")
		{
			user_info[user_id] = user_name;
			cmd_info.push_back({ cmd, user_id });
		}
		else if (cmd == "Change")
		{
			//if (user_info[user_id].size() != 0)
			//{
				user_info[user_id] = user_name;
			//}
		}
		else if (cmd == "Leave")
		{
			//if (user_info[user_id].size() != 0)
			//{
			cmd_info.push_back({ cmd,user_id });
			//}
		}

		cmd.clear();
		user_id.clear();
		user_name.clear();

	}

	for (int i = 0; i < cmd_info.size(); i++)
	{
		cmd = cmd_info[i][0];
		if (cmd == "Enter")
		{
			answer.push_back(user_info[cmd_info[i][1]] + "님이 들어왔습니다.");
		}
		else
		{
			answer.push_back(user_info[cmd_info[i][1]] + "님이 나갔습니다.");
		}
	}

	return answer;
}