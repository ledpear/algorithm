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
	//index�� ���Ϸ��� ���丮��
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

	//�ϴ� n�� ���� �������� ���Ѵ�.
	vector<long long> factorialNumber = getFactorialNumber(n);

	// ���� ���ڴ�
	// ((k / (n-1)�� ���丮��) + 1) ��° ����
	// ���Ѵ����� k�� 
	// k % (n-1)�� ���丮�� �ε� ���� 0�̶��  (n-1)�� ���丮���� �ȴ�

	vector<bool> log(n + 1);
	int currNum = n;
	while (answer.size() != n)
	{
		//���° ���ڸ� ã������ ���Ѵ�
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