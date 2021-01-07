#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int input = 0;
	cin >> input;
	vector<int> dp(input + 1, 0);
	int i = 2;
	while (i <= input)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}
		i++;
	}
	int Result = dp[input];
	cout << Result << endl;

	return 0;
}