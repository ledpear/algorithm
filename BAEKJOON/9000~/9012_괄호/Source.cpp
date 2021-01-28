#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int nCount;
	cin >> nCount;
	for (int i = 0; i < nCount; i++)
	{
		string strInput;
		cin >> strInput;
		stack<int> sArr;
		bool bResult = true;

		for (int j = 0; j < strInput.size(); j++)
		{
			if (strInput[j] == '(')
				sArr.push(1);
			else if (strInput[j] == ')')
			{
				if (sArr.size() == 0)
				{
					bResult = false;
					break;
				}
				else
					sArr.pop();
			}
		}

		if (!bResult || sArr.size() != 0)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	system("pause");
	return 0;
}