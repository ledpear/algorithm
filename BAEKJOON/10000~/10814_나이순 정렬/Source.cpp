#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int input;
	cin >> input;
	vector<vector<string>> data(201);

	int nTemp;
	string strTemp;
	for (int i = 0; i < input; i++)
	{
		cin >> nTemp >> strTemp;
		data[nTemp].push_back(strTemp);
	}

	for (int i = 1; i <= 200; i++)
	{
		if ((nTemp = data[i].size()) != 0)
		{
			for (int j = 0; j < nTemp; j++)
			{
				printf("%d %s\n", i, data[i][j].c_str());
			}
		}
	}

	system("pause");

	return 0;
}