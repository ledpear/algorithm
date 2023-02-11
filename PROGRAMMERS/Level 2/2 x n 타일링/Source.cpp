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
	//일단 DP 알고리즘 적용해야한다
	//가로가 [1]이면 1
	//가로가 [2]이면 2
	//그 다음부터는 세로 배치(가로1칸사용)할 경우의 n-1번째
	//+
	//가로2칸사용할 경우의 (n-2)번째 (세로2개배치는 중복되니깐 제외)
	//하면될듯

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