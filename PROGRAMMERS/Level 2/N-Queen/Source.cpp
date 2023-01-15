#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

void search(vector<vector<bool>>& map, int row, int col, int& result)
{
	int size = map.size();
	if (row == size - 1)
	{
		for (int i = 0; i < size; ++i)
		{
			if (map[row][i] == false)
				++result;
		}
		return;
	}

	vector<vector<bool>> newMap = map;
	//���� ǥ��
	int gap = 1;
	for (int i = row + 1; i < size; ++i)
	{
		newMap[i][col] = true;
		{
			int pos = col + gap;
			if (pos < size)
				newMap[i][pos] = true;

		}
		{
			int pos = col - gap;
			if (pos >= 0 )
				newMap[i][pos] = true;
		}
		++gap;
	}

	int next = row + 1;
	for (int i = 0; i < size; ++i)
	{
		if (newMap[next][i] == false)
		{
			search(newMap, next, i, result);
		}
	}
}

int solution(int n) 
{
	// 0���� n-1���� Ž���ϴ� ��ü Ž��
	// ���� �� �ִ� ���� �˰ԵǸ� ���ڷ� �ѱ��
	// ���ٿ� �ϳ��� ������ �� �Ʒ��ٸ� ����ȴ�(nȸ)
	int answer = 0;

	vector<vector<bool>> map;
	for (int i = 0; i < n; ++i)
	{
		map.push_back(vector<bool>(n));
	}

	for (int i = 0; i < n; ++i)
	{
		search(map, 0, i, answer);
	}

	return answer;
}

int main()
{
	int result = solution(4);
	cout << result << endl;

	return 0;
}