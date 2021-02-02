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

	int nBlank;
	for (int i = 0; i < nInput; i++)
	{
		nBlank = nInput - i - 1;
		for (int j = 0; j < nBlank; j++)
			cout << ' ';

		for (int j = 0; j <= i; j++)
			cout << '*';
		for (int j = 0; j < i; j++)
			cout << '*';

		cout << '\n';
	}

	system("pause");

	return 0;
}