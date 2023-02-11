#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <cassert>

using namespace std;

vector<long long> getFactorialNumber(int size)
{
	//index는 구하려는 팩토리얼
	vector<long long> result = vector<long long>{ 1, 1 };
	for (int i = 2; i <= size; ++i)
		result.push_back(i * result[i - 1]);

	return result;
}

int searchNumber(int targetCount, vector<bool>& log)
{
	int searchCount = 0;
	int index = 1;
	for (; index < log.size(); ++index)
	{
		if (log[index] == true)
			continue;

		++searchCount;

		if (searchCount == targetCount)
		{
			log[index] = true;
			break;
		}
	}

	return index;
}

vector<int> solution(int n, long long k)
{
	vector<int> answer;

	//일단 n에 따른 가짓수를 구한다.
	vector<long long> factorialNumber = getFactorialNumber(n);

	// 구할 숫자는
	// ((k / (n-1)의 팩토리얼) + 1) 번째 숫자
	// 구한다음에 k는 
	// k % (n-1)의 팩토리얼 인데 만약 0이라면  (n-1)의 팩토리얼이 된다

	vector<bool> log(n + 1);
	int currNum = n;
	while (answer.size() != n)
	{
		//몇번째 숫자를 찾을건지 구한다
		const long long currFactorialNum = factorialNumber[currNum - 1];
		if (currFactorialNum == 1)
		{
			answer.push_back(searchNumber(k, log));
			answer.push_back(searchNumber(1, log));
			break;
		}

		assert(k > 0);
		const long long target = ((k - 1) / currFactorialNum) + 1;
		answer.push_back(searchNumber(target, log));
		k %= factorialNumber[currNum - 1];
		if (k == 0)
			k = factorialNumber[currNum - 1];

		--currNum;
	}

	return answer;
}

void print(vector<int> arr)
{
	for (int num : arr)
		cout << num << ' ';
	cout << endl;
}

void solPrint(int n)
{
	vector<long long> size = getFactorialNumber(n);
	for (int i = 1; i <= size[n]; ++i)
	{
		print(solution(n, i));
	}
}

int main()
{
	for (int i = 1; i <= 7; ++i)
		solPrint(i);

	vector<int> answer = solution(3, 6);

	return 0;
}