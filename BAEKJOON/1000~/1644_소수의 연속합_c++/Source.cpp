#include <iostream>
#include <vector>

using namespace std;

//custum function
vector<int> getPrimeNum(int limit)
{
	vector<int> primeNumArr;
	vector<bool> primeNumCheck(limit + 1);

	//에라토스테네스의 체
	for (int num(2); num <= limit; ++num)
	{
		//방문하지 않은 수이면 소수이다
		if (!primeNumCheck[num])
		{
			//배열에 추가하고
			primeNumArr.push_back(num);
			//배수들을 방문처리 해준다
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
	//에라토스테네스의 체를 활용하여 입력된 값 이하의 소수 배열을 생성한다
	//생성된 소수 배열을 연속적으로 더해 가면서 목표 값이랑 동일한지 확인 한다
	//단 더한 값이 목표값보다 커지면 해당 반복을 중지한다
	//Declaration
	int target = 0;
	int answer = 0;
	cin >> target;

	//Solution
	vector<int> primeNumArr = getPrimeNum(target);
	//큰 값부터 확인한다.
	for (int index = primeNumArr.size() - 1; index >= 0; --index)
	{
		int sumVal = primeNumArr[index];
		int sumIndex = index;

		//연속해서 더한 값이 목표 값과 일치하는지 확인하면서 진행하고
		//더한 값이 목표값보다 커지면 종료한다
		while (sumVal <= target)
		{
			if (sumVal == target)
			{
				++answer;
				break;
			}

			if (sumIndex > 0)
			{
				sumVal += primeNumArr[--sumIndex];
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