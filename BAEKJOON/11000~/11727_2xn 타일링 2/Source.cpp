#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nInput;
	cin >> nInput;

	vector<int> vDP(nInput + 1);

	if (nInput == 1)
		cout << 1 << '\n';
	else if (nInput == 2)
		cout << 3 << '\n';
	else
	{
		vDP[1] = 1;
		vDP[2] = 3;
		for (int i = 3; i <= nInput; i++)
		{
			vDP[i] = (vDP[i - 2] * 2 + vDP[i - 1]) % 10007;
		}

		cout << vDP[nInput] << '\n';
	}
	
	system("pause");

	return 0;
}