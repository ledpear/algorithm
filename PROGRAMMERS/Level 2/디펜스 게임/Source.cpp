#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int solution(int n, int k, vector<int> enemy) 
{
	//������� ������ ���� ���ϴµ�
	//���� ���� ���� ������ �ʴ´�
	//���͸� ����� ũ������� insert�Ѵ�
	const int count = enemy.size();
	int answer = 0;
	vector<int> clear;
	int sum = 0;

	//���带 ���������� ����
	for (int round = 0; round < count; ++round)
	{
		const int enemyNum = enemy[round];
		int index = 0;
		//�� ��ġ�� ã�´�
		for (index; index < clear.size(); ++index)
		{
			//��ġ�� ã�Ҵ�
			if (clear[index] < enemyNum)
				break;

			//������(k)�ȿ� ���� ������ �׳� push back
			if (index >= k)
			{
				index = count;
				break;
			}
		}
		
		if(clear.size() == index)
			clear.push_back(enemyNum);
		else if (index == count )
		{
			sum += enemyNum;
			if (sum > n)
			{
				answer = round;
				break;
			}

			clear.push_back(enemyNum);
		}
		else
		{
			if (clear.size() >= k)
				sum += clear[k-1];

			if (sum > n)
			{
				answer = round;
				break;
			}

			clear.insert(clear.begin() + index, enemyNum);
		}
	}

	return answer;
}

int main()
{
	int answer = 0;
	answer = solution(7, 3, vector<int>({ 4,2,4,5,3,3,1 }));
	return 0;
}