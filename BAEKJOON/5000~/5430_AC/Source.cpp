#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nTest;
	cin >> nTest;

	for (int test = 0; test < nTest; test++)
	{
		string strCommand, strArr, strTemp;
		int nSize;
		deque<int> dq;
		bool bDir = true, bResult = true;

		cin >> strCommand;
		cin >> nSize;
		cin >> strArr;

		for (int i = 1; i < strArr.size()-1; i++)
		{
			if (strArr[i] != ',')
			{
				strTemp += strArr[i];
			}				
			else
			{
				dq.push_back(stoi(strTemp));
				strTemp = "";
			}
			if(i == strArr.size() - 2)
				dq.push_back(stoi(strTemp));
		}
		
		
		string strResult = "[";

		for (int i = 0; i < strCommand.size(); i++)
		{
			if (strCommand[i] == 'R')
			{
				bDir = !bDir;
			}
			else if (strCommand[i] == 'D')
			{
				if (dq.empty())
				{
					bResult = false;
					break;
				}
				else
				{
					if (bDir)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}

		while (!dq.empty() && bResult)
		{
			if (bDir)
			{
				strResult += to_string(dq.front());
				dq.pop_front();
			}
			else
			{
				strResult += to_string(dq.back());
				dq.pop_back();
			}

			if (dq.size() > 0)
				strResult += ',';
		}
		strResult += ']';

		if(bResult)
			cout << strResult << '\n';
		else
			cout << "error\n";
	}
	system("pause");
	return 0;
}