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
	// 기본키, 정해진키, row로 구성된 vector를 만들고 우선순위 큐에 넣는다

	struct cmp {
		bool operator()(vector<int> lhs, vector<int> rhs)
		{
			if (lhs[1] == rhs[1])
				return lhs[0] < rhs[0];

			return lhs[1] > rhs[1];
		}
	};

	//큐를 만든다
	priority_queue < vector<int>, vector<vector<int>>, cmp> pq;
	for (int i = 0; i < data.size(); ++i)
	{
		vector<int> temp = vector<int>{ data[i][0], data[i][col], i };
		pq.push(temp);
	}

	//큐를 빼면서 계산한다
	for (int i = 0; i < data.size(); ++i)
	{
		//예외처리1 : 시작 순서까지 pop
		if (i < row_begin)
		{
			pq.pop();
			continue;
		}

		//예외처리2 : 끝났으면 break
		if (i > row_end)
			break;

		//계산
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