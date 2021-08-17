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
	int target(0);
	cin >> target;

	//Solution
	vector<int> primeNumArr = getPrimeNum(target);
	int answer(0);
	for (int index(primeNumArr.size() - 1); index >= 0; --index)
	{
		int sumVal = primeNumArr[index];
		int sumIndex = index - 1;

		while (sumVal <= target)
		{
			if (sumVal == target)
			{
				++answer;
				break;
			}

			if (sumIndex >= 0)
			{
				sumVal += primeNumArr[sumIndex--];
			}
			else
			{
				break;
			}
		}
	}

	//Output
	cout << answer << '\n';

	return 0;
}