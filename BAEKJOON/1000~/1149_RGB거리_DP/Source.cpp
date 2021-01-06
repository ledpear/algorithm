#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

enum {
	eR = 0,
	eG,
	eB,
	eRGB_Max
};

int main()
{
	int input;
	cin >> input;
	vector<vector<int>> vRGB(eRGB_Max, vector<int>(input));	// 0 : R, 1 : G, 2 : B

	for (int i = 0; i < input; i++)
	{
		cin >> vRGB[eR][i] >> vRGB[eG][i] >> vRGB[eB][i];
	}

	vector<vector<int>> dp(eRGB_Max, vector<int>(input));
	int nColor = 0;
	int LastColor[eRGB_Max] = { -1, -1, -1 };
	for (int i = 0; i < input; i++)
	{
		for (int StartColor = 0; StartColor < eRGB_Max; StartColor++)
		{
			if (i > 0)
			{
				if (StartColor == eR)
				{
					dp[StartColor][i] += min(dp[eG][i - 1], dp[eB][i - 1]) + vRGB[eR][i];
				}
				else if (StartColor == eG)
				{
					dp[StartColor][i] += min(dp[eR][i - 1], dp[eB][i - 1]) + vRGB[eG][i];
				}
				else if (StartColor == eB)
				{
					dp[StartColor][i] += min(dp[eR][i - 1], dp[eG][i - 1]) + vRGB[eB][i];
				}
			}
			else
			{
				dp[StartColor][i] = vRGB[StartColor][i];
			}
		}
	}

	cout << min({ dp[eR][input - 1], dp[eG][input - 1], dp[eB][input - 1] }) << endl;

	return 0;
}