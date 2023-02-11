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
		//���ٸ� �ְ� -1�� ����
		if (search.find(c) == search.end())
		{
			search.insert(pair<char, int>(c, index));
			answer.push_back(-1);
		}
		//�ִٸ� �� ��ġ�� ���� ��ġ�� ���̸� �����ϰ� map�� �ִ� ��ġ�� ����1
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