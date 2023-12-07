#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int INF = 200000000;

int main()
{
	int size = 0;
	cin >> size;

	vector<vector<int>> matrixs(size, vector<int>(2, 0));
	for (int i = 0; i < size; ++i)
		cin >> matrixs[i][0] >> matrixs[i][1];

	//dpArr[i][j] : i부터 j까지의 행렬곱의 최소 연산 값
	vector<vector<int>> dpArr(size, vector<int>(size, INF));

	//자기자신의 위치는 0이어야 정상적으로 계산이된다.
	for (int i = 0; i < size; ++i)
		dpArr[i][i] = 0;
	
	for (int range = 1; range < size; ++range)
	{
		for (int startPos = 0; startPos + range < size; ++startPos)
		{
			const int endPos = startPos + range;
			for (int divPos = startPos; divPos < endPos; ++divPos)
			{
				const int newVal = dpArr[startPos][divPos] + dpArr[divPos + 1][endPos] + (matrixs[startPos][0] * matrixs[divPos][1] * matrixs[endPos][1]);
				dpArr[startPos][endPos] = min(dpArr[startPos][endPos], newVal);
			}
		}
	}

	int answer = dpArr[0][size - 1];
	cout << answer << endl;
}