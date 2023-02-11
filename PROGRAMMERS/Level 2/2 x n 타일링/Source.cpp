#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int solution(int n) 
{
	int answer = 0;
	//�ϴ� DP �˰��� �����ؾ��Ѵ�
	//���ΰ� [1]�̸� 1
	//���ΰ� [2]�̸� 2
	//�� �������ʹ� ���� ��ġ(����1ĭ���)�� ����� n-1��°
	//+
	//����2ĭ����� ����� (n-2)��° (����2����ġ�� �ߺ��Ǵϱ� ����)
	//�ϸ�ɵ�

	vector<int> dp = vector<int>{ -1,1,2 };
	for (int i = 3; i <= n; ++i)
	{
		int num = (dp[i - 1] + dp[i - 2]) % 1000000007;
		dp.push_back(num);
	}

	return dp[n];
}

int main()
{
	solution(4);
	return 0;
}