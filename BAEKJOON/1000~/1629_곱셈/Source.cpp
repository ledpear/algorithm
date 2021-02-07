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
vector<unsigned long long> V;

int Sol(unsigned long long A, unsigned long long size, unsigned long long C)
{
	if (V[size] != 0)
		return V[size];
	if (size == 1)
	{
		V[size] = A; 
		return V[size] % C;
	}

	V[size] = (Sol(A, size / 2, C) * Sol(A, size / 2 + size % 2, C)) % C;
		
	return V[size];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	unsigned long long A, B, C;
	cin >> A >> B >> C;

	//cout << Sol(A, B, C) << '\n';

	int nTemp = B;
	vector<int> V;
	vector<unsigned long long> vVal;
	unsigned long long Result = 1;

	while (nTemp != 0)
	{
		V.push_back(nTemp % 2);
		nTemp /= 2;
	}

	for (int i = 0; i < V.size(); i++)
	{
		if (i == 0)
			vVal.push_back(A % C);
		else
			vVal.push_back((vVal[i - 1] * vVal[i - 1]) % C);

		if (V[i])
		{
			Result = (Result * vVal[i]) % C;
		}
	}

	cout << Result << '\n';

	system("pause");

	return 0;
}