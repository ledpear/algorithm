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
vector<int> getPrimeNum(int limit)
{
	vector<int> primeNumArr;
	vector<bool> primeNumCheck(limit + 1);

	for (int num(2); num <= limit; ++num)
	{
		if (!primeNumCheck[num])
		{
			primeNumArr.push_back(num);
			int checkNum(num);
			while (checkNum <= limit)
			{
				primeNumCheck[checkNum] = true;
				checkNum += num;
			}
		}
	}

	return primeNumArr;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int target(0), answer(0);
	cin >> target;

	//Solution
	vector<int> primeNumArr = getPrimeNum(target);
	vector<int> primeNumSum = primeNumArr;

	for (int index(1); index < primeNumSum.size(); ++index)
	{
		primeNumSum[index] += primeNumSum[index - 1];
	}

	for (int index(primeNumArr.size() - 1); index >= 0; --index)
	{
		if (primeNumSum[index] == target)
		{
			++answer;
		}

		for (int outOfRangeIndex(index - 1); outOfRangeIndex >= 0; --outOfRangeIndex)
		{
			int checkNum = primeNumSum[index] - primeNumSum[outOfRangeIndex];
			if (checkNum == target)
			{
				++answer;
			}
			else if (checkNum > target)
			{
				break;
			}
		}
	}

	//Output
	cout << answer << '\n';

	return 0;
}