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
			if(vUsed[i]) continue;
			string strTemp = strResult;
			strTemp += to_string(i);
			vUsed[i] = true;
			BackTracking(strTemp, MaxNum, size, vUsed);
		}
	}
}

int main()
{
	int MaxNum, size;
	cin >> MaxNum >> size;
	string strResult = "";
	vector<bool> vUsed(MaxNum + 1, false);
	BackTracking(strResult, MaxNum, size, vUsed);

	system("pause");
	return 0;
}