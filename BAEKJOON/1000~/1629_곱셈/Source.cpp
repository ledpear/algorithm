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

	unsigned long long A, B, C;
	cin >> A >> B >> C;

	//cout << Sol(A, B, C) << '\n';

	int nTemp = B;
	vector<int> vBinary;
	vector<unsigned long long> vVal;
	unsigned long long Result = 1;

	while (nTemp != 0)
	{
		vBinary.push_back(nTemp % 2);
		nTemp /= 2;
	}

	for (int i = 0; i < vBinary.size(); i++)
	{
		if (i == 0)
			vVal.push_back(A % C);
		else
			vVal.push_back((vVal[i - 1] * vVal[i - 1]) % C);

		if (vBinary[i])
		{
			Result = (Result * vVal[i]) % C;
		}
	}

	cout << Result << '\n';

	system("pause");

	return 0;
}