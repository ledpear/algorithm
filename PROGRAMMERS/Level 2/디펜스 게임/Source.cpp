#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#include <queue>
#include <functional>
int solution(int n, int k, vector<int> enemy)
{
	//������� ������ ���� ���ϴµ�
	//���� ���� ���� ������ �ʴ´�
	//���͸� ����� ũ������� insert�Ѵ�
	const int count = enemy.size();
	//vector<int> clear;
	priority_queue<int> clear;
	int sum = 0;

	//���带 ���������� ����
	for (int round = 0; round < count; ++round)
	{
		const int enemyNum = enemy[round];
		int index = 0;
		
		//1. ť�� ũ�Ⱑ K���� ������ �ϴ� �ִ´�
		if (clear.size() < k)
		{
			clear.push(enemyNum);
			continue;
		}

		//2. ť�� top(���� ���� ��)���� �۰ų� ������ sum�� �����ְ� ���� �Ѿ�� ������
		if ( enemyNum <= clear.top() )
		{
			sum += enemyNum;
			if(sum > n)
				return round;

			continue;
		}

		//3. ť�� �ִ� ������ ũ�� ť�� top�� pop�ؼ� sum�� �־��ְ� ť�� �ִ´�
		sum += clear.top();
		if (sum > n)
			return round;

		clear.pop();
		clear.push(enemyNum);
	}

	return count;
}

int main()
{
	int answer = 0;
	answer = solution(7, 3, vector<int>({ 4, 2, 4, 5, 3, 3, 1 }));
	return 0;
}