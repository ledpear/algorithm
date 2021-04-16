#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <functional>

using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> p;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nTestSize;
	cin >> nTestSize;

	for (int nTest = 0; nTest < nTestSize; nTest++)
	{
		int nSize_0, nSize_1;
		cin >> nSize_0 >> nSize_1;

		vector<int> vArr(nSize_0 + nSize_1);

		string input("");
		cin >> input;

		int len = input.size();

		for (int i = 0; i < len; ++i)
		{
			if (input[i] == '0')
				--nSize_0;
			else if (input[i] == '1')
				--nSize_1;
		}

		bool bResult = true;
		
		for (int i = 0; i <= len - i - 1; ++i)
		{
			int j = len - i - 1;

			if (input[i] == input[j] && input[i] == '?')
			{
				if (i != j)
				{
					if (nSize_0 >= 2)
					{
						input[i] = '0';
						input[j] = '0';
						nSize_0 -= 2;
					}
					else if (nSize_1 >= 2)
					{
						input[i] = '1';
						input[j] = '1';
						nSize_1 -= 2;
					}
					else
					{
						bResult = false;
						break;
					}
				}
				else
				{
					if (nSize_0 == 1)
					{
						input[i] = '0';
						nSize_0 -= 1;
					}
					else if (nSize_1 == 1)
					{
						input[i] = '1';
						nSize_1 -= 1;
					}
					else
					{
						bResult = false;
						break;
					}
				}
			}
			if (input[i] != input[j])
			{
				//
				if (input[i] == '?' && input[j] != '?')
				{
					if (input[j] == '0')
					{
						input[i] = '0';
						nSize_0 -= 1;
					}
					else if (input[j] == '1')
					{
						input[i] = '1';
						nSize_1 -= 1;
					}
				}
				else if (input[i] != '?' && input[j] == '?')
				{
					if (input[i] == '0')
					{
						input[j] = '0';
						nSize_0 -= 1;
					}
					else if (input[i] == '1')
					{
						input[j] = '1';
						nSize_1 -= 1;
					}
				}
				else
				{
					bResult = false;
					break;
				}
			}

			if(nSize_0 < 0 || nSize_1 < 0)
			{
				bResult = false;
				break;
			}
		}

		if (bResult && nSize_0 >= 0 && nSize_1 >= 0)
			cout << input << '\n';
		else
			cout << "-1\n";
	}

	system("pause");

	return 0;
}