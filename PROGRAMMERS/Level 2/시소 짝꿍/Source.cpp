#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#include <unordered_map>
#include <unordered_set>
using namespace std;

long long solution(vector<int> weights) 
{
	long long answer = 0;

	vector<long long> weightCount = vector<long long>(1001, 0);
	//�����԰� ���� ����� Ȯ���Ѵ�
	for (int weight : weights)
	{
		++weightCount[weight];
	}

	//�����Ը� ��ȸ�ϸ鼭 1:2, 2:3, 3:4�� ������ �����԰� �ִ��� Ȯ���Ѵ�.
	for (int weight : weights)
	{
		//1:2
		{
			int checkWeight = weight * 2;
			if (checkWeight <= 1000)
				answer += weightCount[checkWeight];
		}

		if (weight % 2 == 0)
		{
			int checkWeight = (weight / 2) * 3;
			if (checkWeight <= 1000)
				answer += weightCount[checkWeight];
		}

		if (weight % 3 == 0)
		{
			int checkWeight = (weight / 3) * 4;
			if (checkWeight <= 1000)
				answer += weightCount[checkWeight];
		}
	}

	//�����԰� ���� ����� 1~N������ ������ answer�� ���Ѵ�
	for (long long count : weightCount)
	{
		if (count < 2)
			continue;

		answer += (count * (count - 1)) / 2;
	}

	return answer;
}

int main()
{
	vector<int> weights = { 100, 180, 360, 100, 270 };
	int result = solution(weights);
	return 0;
}