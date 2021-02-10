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

	unsigned long long n, m;
	cin >> n >> m;
	unsigned long long nDiv, nMod;
	nDiv = 0;
	while (n >= m)
	{
		n -= m;
		nDiv++;
	}
	cout << nDiv << '\n';
	cout << n << '\n';

	return 0;
}