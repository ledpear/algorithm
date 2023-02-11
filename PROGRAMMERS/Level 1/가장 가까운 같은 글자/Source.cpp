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
		//���ٸ� �����ϰ� -1�� ����
		if (search[num] == -1)
		{
			search[num] = index;
			answer.push_back(-1);
		}
		//�ִٸ� �� ��ġ�� ���� ��ġ�� ���̸� �����ϰ� map�� �ִ� ��ġ�� ����
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