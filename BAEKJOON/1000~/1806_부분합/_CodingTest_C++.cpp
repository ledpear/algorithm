#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int INF = 100000000;

int main()
{
	int n, s;
	cin >> n >> s;
	vector<int> numbers(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> numbers[i];

	int minLength = INF;
	int numberSum = 0;
	int startIndex = 0;
	int endIndex = 0;
	for (int endIndex = 0; endIndex < n; ++endIndex)
	{
		numberSum += numbers[endIndex];
		while (numberSum >= s)
		{
			if (startIndex > endIndex)
				break;

			minLength = min(minLength, endIndex - startIndex + 1);
			numberSum -= numbers[startIndex];
			++startIndex;
		}
	}

	if (minLength == INF)
		minLength = 0;

	cout << minLength << endl;
}