#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

//641이 최대

int main()
{
	int size = 0;
	cin >> size;
	char targetNum[5001];
	scanf("%s", targetNum);

	//순차적으로 진행한다
	//pos는 문자의 위치를 의미한다
	//pos 앞의 2개까지 숫자를 제외한 가장 작은 경우의 수를 계산해야한다.
	//그럴경우 현재 숫자가 유효한지 확인해야한다.
	//만약 유효한 숫자 앞에 숫자가 없다면 1 아니면 그 숫자 +1이다.

	vector<int> dpArr(size, 1);
	for (int pos = 1; pos < size; ++pos)
	{
		int minCount = 5001;
		for (int numRange = 1; numRange <= 3; ++numRange)
		{
			int makeNum = 0;
			bool isInvalid = false;

			//숫자를 만든다.(끝 숫자가 0이면 안된다.)
			for (int indexOffset = 0; indexOffset < numRange; ++indexOffset)
			{
				const int currentPos = pos - indexOffset;
				//범위 체크
				if(currentPos < 0)
				{
					isInvalid = true;
					break;
				}

				const int currentNum = (targetNum[currentPos] - 48);
				//(끝 숫자가 0이면 안된다.)
				if (numRange - 1 == indexOffset && currentNum == 0)
				{
					isInvalid = true;
					break;
				}

				makeNum += currentNum * pow(10, indexOffset);
			}

			//조건 체크
			if (isInvalid == true)
				continue;

			//0이면 안된다.
			if (makeNum == 0)
				continue;

			//641이 넘으면 안된다.
			if (makeNum > 641)
				continue;

			//앞의 수가 없으면 1이다.
			const int rangePos = pos - numRange;
			if (rangePos < 0)
			{
				minCount = 1;
				break;
			}
			else
				minCount = min(minCount, dpArr[rangePos] + 1);
		}
		dpArr[pos] = minCount;
	}

	cout << dpArr[size - 1];
}