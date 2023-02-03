#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int nextNum(int num)
{
	if (num == static_cast<int>('z'))
		return static_cast<int>('a');
	else
		return num + 1;
}

string solution(string s, string skip, int index) 
{
	string answer = "";

	//스킵할 알파벳을 찾는다
	vector<bool> skipAlpha = vector<bool>('z' - 'a' + 1);
	for (char c : skip)
	{
		skipAlpha[c - 'a'] = true;
	}	

	for (char c : s)
	{
		//건너뛸 횟수
		int count = 0;
		//현재 숫자
		int num = static_cast<int>(c);
		while (true)
		{
			//스킵할 알파벳이면 count는 올리지 않고 num만 올린다
			if (skipAlpha[num - static_cast<int>('a')])
			{
				num = nextNum(num);
				continue;
			}

			++count;
			if (count > index)
				break;

			//z를 넘어가면 a 아니면 다음 글자
			num = nextNum(num);
		}

		answer.push_back(static_cast<char>(num));
	}

	return answer;
}

int main()
{
	string a = solution("ybcde", "az", 1);
	return 0;
}