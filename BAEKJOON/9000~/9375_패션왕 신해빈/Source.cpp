#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;

int main()
{
	int nTest;
	cin >> nTest;

	for (int i = 0; i < nTest; i++)
	{
		map<string, int> mClothing;

		int nCount;
		cin >> nCount;
		string strName, strType;

		for (int j = 0; j < nCount; j++)
		{
			cin >> strName >> strType;

			auto mTemp = mClothing.find(strType);
			if (mTemp == mClothing.end())
				mClothing.insert({ strType, 2 });
			else
				mTemp->second += 1;
		}

		int nResult = 1;
		for (auto iter = mClothing.begin(); iter != mClothing.end(); iter++)
		{
			nResult *= iter->second;
		}
		nResult--;
		cout << nResult << '\n';
	}

	system("pause");


	return 0;
}