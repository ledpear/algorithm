#include <vector>
#include <iostream>
#include <string>

using namespace std;

void BackTracking(string strResult, int startNum, int MaxNum, int size)
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
		for (int i = startNum; i <= MaxNum; i++)
		{
			string strTemp = strResult;
			strTemp += to_string(i);
			BackTracking(strTemp, i, MaxNum, size);
		}
	}
}

int main()
{
	int MaxNum, size;
	cin >> MaxNum >> size;
	string strResult = "";
	BackTracking(strResult, 1, MaxNum, size);

	system("pause");
	return 0;
}