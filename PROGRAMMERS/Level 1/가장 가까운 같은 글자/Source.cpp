#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

vector<int> solution(string s) 
{
	vector<int> answer;
	vector<int> search = vector<int>('z' - 'a' + 1, -1);
	for (int index = 0; index < s.length(); ++index)
	{
		const int num = s[index] - 'a';
		//없다면 갱신하고 -1을 삽입
		if (search[num] == -1)
		{
			search[num] = index;
			answer.push_back(-1);
		}
		//있다면 현 위치와 이전 위치의 차이를 삽입하고 map에 있는 위치를 갱신
		else
		{
			const int diff = index - search[num];
			answer.push_back(diff);

			search[num] = index;
		}
	}

	return answer;
}

int main()
{
	return 0;
}