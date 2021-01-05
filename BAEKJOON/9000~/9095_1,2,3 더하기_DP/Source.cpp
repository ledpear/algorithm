#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int input;
	cin >> input;
	vector<int> vTest(input);

	for (int i = 0; i < input; i++)
	{
		cin >> vTest[i];
	}

	vector<int> dp(12, 0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 0; i < input; i++)
	{
		int data = vTest[i];

		if (dp[data] != 0)
			cout << dp[data] << endl;
		else
		{
			int x = 4;

			while (x <= data)
			{
				if (dp[x] == 0)
				{
					dp[x] = dp[x - 1] + dp[x - 2] + dp[x - 3];
				}
				x++;
			}

			cout << dp[data] << endl;
		}
	}

	return 0;
}