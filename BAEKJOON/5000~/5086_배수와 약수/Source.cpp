#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int a, b;
	while (true)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)	break;
		if (a == 0 || b == 0)	cout << "neither\n";
		else
		{
			int count = 1;
			bool bResult = false;
			if (a > b)
			{
				while (a >= b * count)
				{
					if (a == b * count)
					{
						bResult = true;
						cout << "multiple\n";
					}
					count++;
				}
			}
			else
			{
				while (b >= a * count)
				{
					if (b == a * count)
					{
						bResult = true;
						cout << "factor\n";
					}
					count++;
				}
			}
			if (!bResult) cout << "neither\n";
		}
		
	}
	return 0;
}