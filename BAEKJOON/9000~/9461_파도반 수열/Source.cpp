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
	vector<long long> vDP(102, 0);
	vDP[1] = 1;
	vDP[2] = 1;
	vDP[3] = 1;
	int temp;
	for (int nTest = 0; nTest < input; nTest++)
	{
		cin >> temp;
		if (vDP[temp] == 0)
		{
			for (int i = 4; i <= temp; i++)
			{
				vDP[i] = vDP[i - 2] + vDP[i - 3];
			}
		}
		cout << vDP[temp] << "\n";
	}

	system("pause");
	return 0;
}