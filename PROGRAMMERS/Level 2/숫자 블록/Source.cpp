#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

vector<int> solution(long long begin, long long end) 
{
	//시작 숫자부터 1과 자신을 제외한 최대 약수를 구하면 된다...
	vector<int> answer;
	//최대 약수를 구하기 위해 소수부터 구한다.
	vector<int> decimal;
	const int maxVal = static_cast<int>(sqrtf(end));
	for (int i = begin; i <= end; ++i)
	{
		if (decimal.empty())
		{
			answer.push_back(0);
			continue;
		}

		if (i < decimal[0])
		{
			answer.push_back(0);
			continue;
		}

		int num = 1;
		for (int j = 2; j <= maxVal; ++j)
		{
			if (i < j)
				break;

			if (i % j == 0)
			{
				int result = i / j;
				if (result <= 10000000 && j <= 10000000)
					num = max(num, result);
			}
		}

		answer.push_back(num);
	}	

	return answer;
}

int main()
{
	vector<int> test;
	{
		long begin = 1000000000 - 9;
		long end = 1000000000;
		test = solution(begin, end);
	}
	test = solution(1, 25);

	return 0;
}