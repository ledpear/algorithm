#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
#include <queue>

vector<int> solution(vector<int> numbers) 
{
	//순회하면서 max값은 기억한다
	//queue에 순차적으로 넣는다
	vector<int> answer;
	// 0: 숫자 1: 뒷 큰수
	deque<vector<int>> q;
	int index = numbers.size() - 1;
	int max = 0;
	for (index; index >= 0; --index)
	{
		//최댓값이 나보다 작거나 같으면 무조건 -1
		int num = numbers[index];
		if (max <= num)
		{
			q.push_front(vector<int>{num, -1});
			if (max < num)
				max = num;

			continue;
		}

		//큐를 순회
		for (vector<int> backNum : q)
		{
			//뒤에 값이 나보다 크거나
			if ( num < backNum[0])
			{
				q.push_front(vector<int>{num, backNum[0]});
				if (max < backNum[0])
					max = backNum[0];

				break;
			}

			//나보다 작지만 뒷 큰수가 더 클때
			if (num < backNum[1])
			{
				q.push_front(vector<int>{num, backNum[1]});
				if (max < backNum[1])
					max = backNum[1];

				break;
			}
		}		
	}

	for (vector<int> backNum : q)
	{
		answer.push_back(backNum[1]);
	}

	return answer;
}

int main()
{
	vector<int> a;
	{
		a = solution(vector<int>{2, 3, 3, 5});
	}
	{
		a = solution(vector<int>{9,1,5,3,6,2});
	}
	return 0;
}