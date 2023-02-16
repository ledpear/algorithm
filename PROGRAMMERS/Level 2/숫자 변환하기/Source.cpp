#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

#include <queue>
#include <climits>
using namespace std;

int solution(int x, int y, int n) {
	int answer = INT_MAX;
	//BFS�� �ذ�����
	vector<bool> log(1000001);
	queue<pair<int, int>> q;
	//���� ��ġ�� �ִ´�
	q.push(pair<int, int>(x, 0));

	while (q.empty() == false)
	{
		int pos = q.front().first;
		int score = q.front().second;
		q.pop();

		//��ġ�ϸ� ���� �־��ְ� ����
		if (pos == y)
		{
			answer = min(score, answer);
			break;
		}

		//n�� ���� ��Ȳ
		int nextPos = pos + n;
		if (nextPos <= y && log[nextPos] == false)
		{
			log[nextPos] = true;
			q.push(pair<int, int>(nextPos, score + 1));
		}
		// 2�� ���� ��Ȳ
		nextPos = pos * 2;
		if (nextPos <= y && log[nextPos] == false)
		{
			log[nextPos] = true;
			q.push(pair<int, int>(nextPos, score + 1));
		}
		// 3�� ���� ��Ȳ
		nextPos = pos * 3;
		if (nextPos <= y && log[nextPos] == false)
		{
			log[nextPos] = true;
			q.push(pair<int, int>(nextPos, score + 1));
		}
	}

	if (answer == INT_MAX)
		answer = -1;

	return answer;
}

int main()
{
	return 0;
}