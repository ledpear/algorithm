#include <vector>
#include <iostream>

using namespace std;

int dp[21][21][21] = { 0, };

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	if (a > 20 || b > 20 || c > 20)
	{
		return w(20, 20, 20);
	}
	if (dp[a][b][c] != 0) return dp[a][b][c];
	if (a < b && b < c)
	{
		return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else
	{
		return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

int main()
{
	int a, b, c;
	int nResult;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		nResult = w(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << nResult << endl;
	}
	system("pause");
	return 0;
}