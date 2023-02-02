#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

vector<int> solution(int n, long long k) 
{
	vector<int> answer;
	
	vector<long long> result = vector<long long>{ 1, 1 };
	//�ϴ� n�� ���� �������� ���Ѵ�.
	for (int i = 2; i <= n; ++i)
	{
		result.push_back(i * result[i - 1]);
	}

	//�� ������ ������ ������ ã�´�
	//1. ���� ����
	//2. �������� ���� ������ n
	int count = n;
	int div = n;
	vector<bool> used = vector<bool>(n + 1);
	int value = k;
	while (count > 2)
	{
		--count;
		//ó������ K �� ������ ��
		//�� ������ [���� ������] �ϸ� 
		int targetCount = (value - 1) / result[count];
		for (int index = 1; index <= n; ++index)
		{
			if (used[index] == true)
				continue;

			if (targetCount == 0)
			{
				answer.push_back(index);
				used[index] = true;
				break;
			}

			--targetCount;
		}

		value = value % result[count];
	}

	int num1 = 0;
	int num2 = 0;
	for (int index = 1; index <= n; ++index)
	{
		if (used[index] == true)
			continue;

		if (num1 == 0)
			num1 = index;
		else
		{
			num2 = index;
			break;
		}
	}

	if (value == 1)
	{
		answer.push_back(num1);
		answer.push_back(num2);
	}
	else
	{
		answer.push_back(num2);
		answer.push_back(num1);
	}

	return answer;
}

int main()
{
	vector<int> answer;
	{
		answer = solution(3, 5);
	}
	{
		answer = solution(4, 4);
	}
	return 0;
}