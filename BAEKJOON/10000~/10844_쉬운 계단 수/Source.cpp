#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int input;
	cin >> input;

	vector<vector<int>> vDP(10, vector<int>(input));

	for (int i = 1; i < 10; i++)
		vDP[i][0] = 1;
	vDP[0][0] = 0;

	for (int i = 1; i < input; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				vDP[j][i] = vDP[1][i - 1] % 1000000000;
			else if(j == 9)
				vDP[j][i] = vDP[8][i - 1] % 1000000000;
			else
				vDP[j][i] = (vDP[j+1][i - 1] + vDP[j-1][i - 1]) % 1000000000;
		}
	}

	int output = 0;

	for (int i = 0; i < 10; i++)
		output = (output + vDP[i][input - 1] ) % 1000000000;

	cout << output << '\n';

	system("pause");

	return 0;
}