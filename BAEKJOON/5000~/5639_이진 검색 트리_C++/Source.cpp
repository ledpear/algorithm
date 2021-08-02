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

void postOrderPrint(vector<int> &inputArr, int front, int end)
{
	if (front >= end)
	{
		return;
	}

	int nowVal = inputArr[front];

	int pos = end;
	for (int index(front + 1); index < end; ++index)
	{
		if (nowVal < inputArr[index])
		{
			pos = index;
			break;
		}
	}

	postOrderPrint(inputArr, front + 1, pos);
	postOrderPrint(inputArr, pos, end);
	cout << nowVal << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	vector<int> inputArr;
	while (true)
	{
		int tempNum(0);
		cin >> tempNum;
		if (cin.eof() == true)
		{
			break;
		}
		else
		{
			inputArr.push_back(tempNum);
		}
	}

	//Solution
	//Output
	postOrderPrint(inputArr, 0, inputArr.size());

	////////////////////////////////////
	system("pause");
	return 0;
}