#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int solution(int n) {
	//DP 알고리즘 적용
	//n이 1일때는 불가능하다
	if (n == 1)
		return 0;
	//짝수만 가능하다
	if (n % 2 != 0)
		return 0;
	
	//2부터 가능
	vector<int> dp = vector<int>{ 0,0,3,0,11 };
	for (int i = 5; i <= n; ++i)
	{
		if (i % 2 == 1)
		{
			dp.push_back(0);
			continue;
		}
		//가로 2를 차지하는 경우의 수 3 * dp[i - 2]
		long long num = (3ll * static_cast<long long>(dp[i - 2])) % 1000000007;
		//그 다음 2의 배수마다 곱하기 2를 한다
		
		int j = i - 4;
		while (j > 0)
		{
			num = (num + (2ll * static_cast<long long>(dp[j]))) % 1000000007;
			j -= 2;
		}

		num = (num + 2) % 1000000007;
		dp.push_back(num);
	}
	return dp[n];
}

int main()
{
	int n = solution(5000);
	return 0;
}