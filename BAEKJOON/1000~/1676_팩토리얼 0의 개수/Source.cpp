#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define max 1000000000000

int main()
{
	int nInput;
	cin >> nInput;
	unsigned long long nNum = 1;
	int nCount = 0;
	for (int i = 2; i <= nInput; i++)
	{
		nNum *= i;

		while (true)
		{
			if (nNum % 10 == 0)
			{
				nCount++;
				nNum /= 10;
			}
			else
			{
				nNum = nNum % max;
				break;
			}
		}
	}

	cout << nCount << '\n';

	system("pause");

	return 0;
}