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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int arrSize(0);
	cin >> arrSize;
	int leftPos(0), rightPos(arrSize - 1);
	vector<int> numArr(arrSize);
	for (int index(0); index < arrSize; ++index)
	{
		cin >> numArr[index];
	}

	//Solution
	int minVal = int(2e9);
	int resultLeft(0), resultRight(0);
	while (leftPos != rightPos)
	{
		int nowVal = numArr[leftPos] + numArr[rightPos];

		if (abs(nowVal) < minVal)
		{
			minVal = abs(nowVal);
			resultLeft = numArr[leftPos];
			resultRight = numArr[rightPos];
		}

		if (nowVal == 0)
		{			
			break;
		}
		else if (nowVal < 0)
		{
			++leftPos;
		}
		else
		{
			--rightPos;
		}
	}

	//Output
	cout << resultLeft << ' ' << resultRight << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}