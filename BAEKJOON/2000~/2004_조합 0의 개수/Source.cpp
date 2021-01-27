#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
#define max 1000000000000
typedef pair<unsigned long long, int> node;

int main()
{
	int n, m;
	cin >> n >> m;
	
	unsigned long long nNum = 1;

	int nCount = 0;

	for (int i = 1; i <= m; i++)
	{
		nNum = ((nNum * (n - i + 1)) / i) % max;

		while (true)
		{
			if (nNum % 10 == 0)
			{
				nCount++;
				nNum /= 10;
			}
			else
			{
				break;
			}
		}
	}
	cout << nCount << '\n';

	system("pause");

	return 0;
}