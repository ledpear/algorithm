#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

#include <queue>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) 
{
	int answer = 0;
	--row_begin;
	--row_end;
	--col;
	// �⺻Ű, ������Ű, row�� ������ vector�� ����� �켱���� ť�� �ִ´�

	struct cmp {
		bool operator()(vector<int> lhs, vector<int> rhs)
		{
			if (lhs[1] == rhs[1])
				return lhs[0] < rhs[0];

			return lhs[1] > rhs[1];
		}
	};

	//ť�� �����
	priority_queue < vector<int>, vector<vector<int>>, cmp> pq;
	for (int i = 0; i < data.size(); ++i)
	{
		vector<int> temp = vector<int>{ data[i][0], data[i][col], i };
		pq.push(temp);
	}

	//ť�� ���鼭 ����Ѵ�
	for (int i = 0; i < data.size(); ++i)
	{
		//����ó��1 : ���� �������� pop
		if (i < row_begin)
		{
			pq.pop();
			continue;
		}

		//����ó��2 : �������� break
		if (i > row_end)
			break;

		//���
		vector<int> nums = data[pq.top()[2]];
		int sum = 0;
		for (int j = 0; j < nums.size(); ++j)
			sum += nums[j] % i;

		answer ^= sum;
	}

	return answer;
}

int main()
{
	{
		vector<vector<int>> data;
		data.push_back(vector<int>{2, 2, 6});
		data.push_back(vector<int>{1, 5, 10});
		data.push_back(vector<int>{4, 2, 9});
		data.push_back(vector<int>{3, 8, 3});

		int a = solution(data, 2, 2, 3);

	}
	
	return 0;
}