#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int solution(int n) {
	//DP �˰��� ����
	//n�� 1�϶��� �Ұ����ϴ�
	if (n == 1)
		return 0;
	//¦���� �����ϴ�
	if (n % 2 != 0)
		return 0;
	
	//2���� ����
	vector<int> dp = vector<int>{ 0,0,3,0,11 };
	for (int i = 5; i <= n; ++i)
	{
		if (i % 2 == 1)
		{
			dp.push_back(0);
			continue;
		}
		//���� 2�� �����ϴ� ����� �� 3 * dp[i - 2]
		long long num = (3ll * static_cast<long long>(dp[i - 2])) % 1000000007;
		//�� ���� 2�� ������� ���ϱ� 2�� �Ѵ�
		
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