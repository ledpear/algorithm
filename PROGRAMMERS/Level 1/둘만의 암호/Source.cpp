#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

string solution(string s, string skip, int index) 
{
	string answer = "";

	vector<bool> skipAlpha = vector<bool>('z' - 'a' + 1);
	for (char c : skip)
	{
		skipAlpha[c - 'a'] = true;
	}

	

	for (char c : s)
	{
		int count = 0;
		int num = static_cast<int>(c);
		while (count < index)
		{
			if (skipAlpha[num - static_cast<int>('a')])
			{
				++num;
				continue;
			}

			//z를 넘어가면 a 아니면 다음 글자
			if (num == static_cast<int>('z'))
				num = static_cast<int>('a');
			else
				++num;

			++count;
		}

		answer.push_back(static_cast<char>(num));
	}

	return answer;
}

int main()
{
	string a = solution("aukks", "wbqd", 5);
	return 0;
}