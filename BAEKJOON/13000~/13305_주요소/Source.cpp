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
	vector<int> vDist(nSize - 1);
	vector<int> vCity(nSize);
	for (int i = 0; i < nSize - 1; i++)
		cin >> vDist[i];
	for (int i = 0; i < nSize; i++)
		cin >> vCity[i];

	long long nCost = 0;
	long long nPrice = 1000000001;
	for (int i = 0; i < nSize - 1; i++)
	{
		if (nPrice > vCity[i])	//최저값보다 작으면 기름값 갱신
			nPrice = vCity[i];
		nCost += nPrice * vDist[i]; // 최저값 * 거리
	}

	cout << nCost << '\n';

	system("pause");

	return 0;
}