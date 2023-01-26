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
	vector<int> clear = vector<int>(k);
	int sum = 0;

	//���带 ���������� ����
	for (int round = 0; round < count; ++round)
	{
		const int enemyNum = enemy[round];
		int index = 0;

		//�� ��ġ�� ã�´�
		if (round >= k && clear[k - 1] >= enemyNum)
		{
			sum += enemyNum;
			if (sum > n)
				return round;
		}
		else
		{
			for (index; index < clear.size(); ++index)
			{
				//��ġ�� ã�Ҵ�
				if (clear[index] < enemyNum)
				{
					if (round >= k)
						sum += clear[k - 1];

					if (sum > n)
						return round;

					for (int backIndex = clear.size() - 1; backIndex > index; --backIndex)
					{
						clear[backIndex] = clear[backIndex - 1];
					}
					clear[index] = enemyNum;

					break;
				}				
			}
		}
	}

	return count;
}

int main()
{
	int answer = 0;
	answer = solution(7, 3, vector<int>({ 4, 2, 4, 5, 3, 3, 1 }));
	return 0;
}