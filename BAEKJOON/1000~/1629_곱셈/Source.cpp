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

int Sol(unsigned long long A, unsigned long long size, unsigned long long C)
{
	if (size == 1)
		return A;
	return (Sol(A, size / 2, C) * Sol(A, size / 2 + size % 2, C)) % C;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	unsigned long long A, B, C;
	cin >> A >> B >> C;

	cout << Sol(A, B, C) << '\n';

	system("pause");

	return 0;
}