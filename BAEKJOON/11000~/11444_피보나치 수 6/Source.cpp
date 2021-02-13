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
typedef vector<vector<ull>> matrix;
#define MOD 1000000007

bool StringOdd(string A)
{
	int n = A[A.size() - 1] - '0';
	return n % 2 != 0;
}

string StringDiv(string A)
{
	string Result = "";
	int nTemp = 0;

	for (int i = 0; i < A.size(); i++)
	{
		nTemp += stoi(A.substr(i, 1));
		Result += to_string(nTemp / 2);
		if (i == 0 && Result[0] == '0')
			Result = "";
		nTemp %= 2;
		nTemp *= 10;
	}
	return Result;
}

matrix operator* (const matrix &A, const matrix &B)
{
	ull nSize = A.size();
	matrix Result = matrix(2, vector<ull>(nSize, 0));

	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			for (int k = 0; k < nSize; k++)
			{
				Result[i][j] += (A[i][k] * B[k][j]);// % MOD;
			}
			Result[i][j] %= MOD;
		}
	}

	return Result;
}

matrix power(string strN)
{
	matrix m, temp;
	m = matrix(2, vector<ull>(2, 0));
	temp = matrix(2, vector<ull>(2, 1));
	m[0][0] = 1;
	m[1][1] = 1;
	temp[1][1] = 0;
	
	while (!strN.empty())
	{
		if (StringOdd(strN))
		{
			m = m * temp;
		}
		temp = temp * temp;
		strN = StringDiv(strN);
	}

	return m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;

	matrix m = power(input);
	
	cout << m[1][0] << '\n';
	system("pause");

	return 0;
}