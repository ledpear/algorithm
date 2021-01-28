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
	while (true)
	{
		string strInput;
		getline(cin, strInput);
		if (strInput.compare(".") == 0)
			break;
		else
		{
			stack<char> sArr;
			int i = 0;
			bool bResult = true;
			while (strInput[i] != '.')
			{
				if (strInput[i] == '(' || strInput[i] == '[')
					sArr.push(strInput[i]);
				else if (strInput[i] == ')')
				{
					if (sArr.empty())
					{
						bResult = false;
						break;
					}
					else if (sArr.top() == '(')
						sArr.pop();
					else
					{
						bResult = false;
						break;
					}
				}
				else if (strInput[i] == ']')
				{
					if (sArr.empty())
					{
						bResult = false;
						break;
					}
					else if (sArr.top() == '[')
						sArr.pop();
					else
					{
						bResult = false;
						break;
					}
				}

				i++;
			}

			if (!bResult || !sArr.empty())
				cout << "no\n";
			else
				cout << "yes\n";
		}
	}
	return 0;
}