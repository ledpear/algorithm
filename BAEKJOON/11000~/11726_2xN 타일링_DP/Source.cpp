#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int input;
	cin >> input;

	vector<int> dp(input+1, 0);
	int i = 3;

	if (input == 1)
		cout << 1 << endl;
	else if (input == 2)
		cout << 2 << endl;
	else
	{
		dp[1] = 1;
		dp[2] = 2;
		while (i <= input)
		{
			dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
			i++;
		}
		cout << dp[input] << endl;
	}

	return 0;
}