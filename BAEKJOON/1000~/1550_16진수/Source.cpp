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

typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;

	ull cnt = 1;
	ull Result = 0;

	for (int i = input.size() - 1; i >= 0; i--)
	{
		if ('0' <= input[i] && input[i] <= '9')
		{
			Result += cnt * (input[i] - '0');
		}
		else if ('A' <= input[i] && input[i] <= 'F')
		{
			Result += cnt * (input[i] - 'A' + 10);
		}
		cnt *= 16;
	}

	cout << Result << '\n';

	system("pause");

	return 0;
}