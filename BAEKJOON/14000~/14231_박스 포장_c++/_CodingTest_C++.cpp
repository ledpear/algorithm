#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int size = 0;
	cin >> size;
	vector<int> boxs(size, 0);
	for (int& box : boxs)
		cin >> box;

	//sol
	vector<int> dpArr(size, 1);
	int result = 0;
	for (int current = 1; current < size; ++current)
	{
		const int currentNum = boxs[current];
		int maxCount = 0;
		//dpArr를 뒤로 순회해서 자신보다 작으면서 가장 큰 카운트를 찾는다.
		for (int target = current - 1; target >= 0; --target)
		{
			const int targetNum = boxs[target];
			if (currentNum > targetNum)
				maxCount = max(maxCount, dpArr[target]);
		}

		dpArr[current] += maxCount;
	}

	cout << *max_element(dpArr.begin(), dpArr.end());
}