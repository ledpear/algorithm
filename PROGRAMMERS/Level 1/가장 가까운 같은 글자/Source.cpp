#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

#include <map>
using namespace std;

vector<int> solution(string s) 
{
	vector<int> answer;
	map<char, int> search;
	for (int index = 0; index < s.length(); ++index)
	{
		const char c = s[index];
		//없다면 넣고 -1을 삽입
		if (search.find(c) == search.end())
		{
			search.insert(pair<char, int>(c, index));
			answer.push_back(-1);
		}
		//있다면 현 위치와 이전 위치의 차이를 삽입하고 map에 있는 위치를 갱신1
		else
		{
			const int diff = index - search[c];
			answer.push_back(diff);

			search[c] = index;
		}
	}

	return answer;
}

int main()
{
	return 0;
}