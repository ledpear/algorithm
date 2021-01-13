#include <vector>
#include <iostream>
#include <string>

using namespace std;

void BackTracking(string strResult, int MaxNum, int size, vector<bool> vUsed)
{
	if (strResult.size() == size)
	{
		int i;
		for (i = 0; i < size - 1; i++)
		{
			cout << strResult[i] << " ";
		}
		cout << strResult[i] << "\n";
	}
	else
	{
		for (int i = 1; i <= MaxNum; i++)
		{
			string strTemp = strResult;
			vector<bool> vTemp = vUsed;

			strTemp += to_string(i);
			vTemp[i] = true;

			BackTracking(strTemp, MaxNum, size, vTemp);
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	int size = M;
	int MaxNum = N;

	string strResult = "";
	vector<bool> vUsed(N + 1, 0);
	
	BackTracking(strResult, MaxNum, size, vUsed);

	system("pause");

	return 0;
}