#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int nSize;
	cin >> nSize;
	vector<int> nDp;
	int number;
	for (int i = 0; i < nSize; i++)
	{
		cin >> number;
		if (nDp.size() == 0 || nDp.back() < number)
			nDp.push_back(number);
		else
			*lower_bound(nDp.begin(), nDp.end(), number) = number;
	}

	cout << nDp.size() << '\n';

	return 0;
}