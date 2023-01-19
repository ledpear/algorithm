#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int playGame(const vector<int>& cards, vector<bool>& opend, int start)
{
	//����� ����(������ ���� ��)
	int num = start;
	int count = 0;
	while (opend.at(num) == false)
	{
		opend[num] = true;
		++count;
		num = cards[num] - 1;
	}

	//���� 1���׷쿡�� �� �����Ѵٸ� ó��������Ѵ�
	//count�� cards�� size�� ������ return 0�Ѵ�
	if (cards.size() == count)
		return 0;

	return count;
}

int solution(vector<int> cards) 
{
	//0���� ��ȸ�ϸ鼭 1�� �׷�� 2���׷��� ����Ѵ�
	//��ü ��ȸ�Ͽ� ���� ���� ������ ��ȯ
	//��ȸ�ϴ°� solution���� �ϰ� ������ �Լ��� ���� ���� ����
	int answer = 0;
	const int size = cards.size();

	for (int i = 0; i < size - 1; ++i)
	{
		vector<bool> opend(size);

		//1�� �׷� ����
		int firstScore = playGame(cards, opend, i);

		//1������ �� ���ƹ��ȴ�
		if (firstScore == 0)
			continue;

		int secondBestScore = 0;
		for (int j = i + 1; j < size; ++j)
		{
			//2�� �׷�
			//1�� �׷쿡�� ������ ���ڴ� �Ѿ��
			if (opend.at(j) == true)
				continue;

			//1�� �׷��� �� ����� �����ϴϱ� �迭 ���� ���� ���
			vector<bool> secondOpend = opend;

			//2�� �׷� ����
			int secondScore = playGame(cards, secondOpend, j);

			//���� ����
			if (secondBestScore < secondScore)
				secondBestScore = secondScore;
		}

		//�ְ� ���� ���
		const int totalScore = firstScore * secondBestScore;
		if (answer < totalScore)
			answer = totalScore;
	}

	return answer;
}

int main()
{
	return 0;
}