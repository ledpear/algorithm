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
	vector<vector<string>> data(201);	// 입력 나이가 1에서 200 사이기 때문에 201로 초기화

	int nTemp;
	string strTemp;
	for (int i = 0; i < input; i++)
	{
		cin >> nTemp >> strTemp;
		data[nTemp].push_back(strTemp);	// 입력 나이에 해당하는 배열에 string 추가
	}

	for (int i = 1; i <= 200; i++)
	{
		if ((nTemp = data[i].size()) != 0)	//추가된 string이 있으면
		{
			for (int j = 0; j < nTemp; j++)
			{
				printf("%d %s\n", i, data[i][j].c_str());	//순서대로 출력
			}
		}
	}

	system("pause");

	return 0;
}