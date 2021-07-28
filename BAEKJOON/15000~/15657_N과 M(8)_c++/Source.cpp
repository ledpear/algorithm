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
void printPermutation(int arrSzie, int permuSizes, int lastIndex, vector<int>& nowArr, vector<int>& numArr)
{
	if (permuSizes == nowArr.size())
	{
		for (auto num : nowArr)
		{
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}

	for (int index(lastIndex); index < arrSzie; ++index)
	{
		nowArr.push_back(numArr[index]);
		printPermutation(arrSzie, permuSizes, index, nowArr, numArr);
		nowArr.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int arrSize(0), permuSize(0);
	cin >> arrSize >> permuSize;
	vector<int> numArr(arrSize);
	for (auto& num : numArr)
	{
		cin >> num;
	}
	sort(numArr.begin(), numArr.end());

	//Solution
	vector<int> nowArr;
	printPermutation(arrSize, permuSize, 0, nowArr, numArr);

	////////////////////////////////////
	system("pause");
	return 0;
}