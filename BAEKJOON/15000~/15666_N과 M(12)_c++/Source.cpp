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

void printPermutation(vector<int>& arrNum, vector<int>& nowArr, int permutationSize, int lastIndex = 0)
{
	if (nowArr.size() == permutationSize)
	{
		for (auto num : nowArr)
		{
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}

	for (int index(lastIndex); index < arrNum.size(); ++index)
	{
		nowArr.push_back(arrNum[index]);
		printPermutation(arrNum, nowArr, permutationSize, index);
		nowArr.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	vector<bool> inputNumCheck(10001);
	int inputSize(0), permutationSize(0);
	cin >> inputSize >> permutationSize;
	vector<int> arrNum;
	
	for (int index(0); index < inputSize; ++index)
	{
		int temp(0);
		cin >> temp;
		if (!inputNumCheck[temp])
		{
			arrNum.push_back(temp);
			inputNumCheck[temp] = true;
		}
	}
	sort(arrNum.begin(), arrNum.end());
	//Solution
	//Output
	vector<int> nowArr;
	printPermutation(arrNum, nowArr, permutationSize);

	////////////////////////////////////
	system("pause");
	return 0;
}