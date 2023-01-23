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
	{
		int max = static_cast<int>( sqrtf(end) ) + 1;
		vector<bool> check = vector<bool>(max);
		for (int i = 2; i < max; ++i)
		{
			if (check[i] == false)
			{
				decimal.push_back(i);

				int j = 2;
				while (i * j < max)
				{
					check[i * j] = true;
					++j;
				}
			}
		}
	}

	{
		for (int i = begin; i <= end; ++i)
		{
			if (decimal.empty())
			{
				answer.push_back(0);
				continue;
			}

			if( i < decimal[0])
			{
				answer.push_back(0);
				continue;
			}

			int num = 1;
			for (int j = 0; j < decimal.size(); ++j)
			{
				if (i < decimal[j])
					break;

				if (i % decimal[j] == 0)
				{
					num = i / decimal[j];
					if (num > 10000000)
						num = decimal[j];
					else
						break;
				}
			}

			answer.push_back(num);
		}
	}
	

	return answer;
}

int main()
{
	vector<int> test;
	{
		test = solution(999990000, 1000000000);
	}
	test = solution(1, 25);

	return 0;
}