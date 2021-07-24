#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//define

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

//custum function
string solution(string mainStr, string subStr)
{
	int mainSize = mainStr.size();
	int subSize = subStr.size();

	//main�� ������ result�� ��ź�� �������� �ε����� �̵���Ű�� ������ �ӵ��� ����Ų��.
	string resultStr(mainStr);
	int mainIndex(0), resultIndex(0);

	for(mainIndex; mainIndex < mainSize; ++mainIndex)
	{
		resultStr[resultIndex] = mainStr[mainIndex];
		if (resultIndex >= subSize - 1 && mainStr[mainIndex] == subStr[subSize - 1])
		{
			bool same = true;
			for (int subIndex(0); subIndex < subSize; ++subIndex)
			{
				if (subStr[subIndex] != resultStr[resultIndex - (subSize - subIndex) + 1])
				{
					same = false;
					break;
				}
			}
			if (same)
			{
				resultIndex -= subSize;
			}
		}
		++resultIndex;
	}

	return resultStr.substr(0, resultIndex);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	string inputStr(""), bombStr("");
	cin >> inputStr;
	cin >> bombStr;

	//Solution
	string resultStr = solution(inputStr, bombStr);


	//Output
	if (resultStr.size() != 0)
	{
		cout << resultStr << '\n';
	}
	else
	{
		cout << "FRULA\n";
	}

	////////////////////////////////////
	system("pause");
	return 0;
}