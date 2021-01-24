#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

typedef vector<vector<int>> Conference;

enum ConferenceTime
{
	eStart = 0,
	eEnd
};

bool compare(vector<int> a, vector<int> b)
{
	if (a[eEnd] == b[eEnd])
		return a[eStart] < b[eStart];
	else
		return a[eEnd] < b[eEnd];
}

int main()
{
	int nSize;
	cin >> nSize;

	Conference vArr(nSize, vector<int>(2));	//0: start, 1: end

	for (int i = 0; i < nSize; i++)
		cin >> vArr[i][eStart] >> vArr[i][eEnd];

	sort(vArr.begin(), vArr.end(), compare);

	int nCount = 1;
	int nEndTime = vArr[0][eEnd];

	for (int i = 1; i < vArr.size(); i++)
	{
		if (nEndTime <= vArr[i][eStart])
		{
			nCount++;
			nEndTime = vArr[i][eEnd];
		}
	}

	cout << nCount << '\n';		

	return 0;
}