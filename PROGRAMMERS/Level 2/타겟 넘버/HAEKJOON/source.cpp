#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void TargetNumber(vector<int> numbers, int step, int target, int sum, int &score)
{
	if (step == numbers.size())
	{
		if (sum == target)
			score++;
	}
	else
	{
		int nPlus, nMinus;
		nPlus = sum + numbers[step];
		nMinus = sum - numbers[step];
		TargetNumber(numbers, step + 1, target, nPlus, score);
		TargetNumber(numbers, step + 1, target, nMinus, score);
	}
}

int main()
{
	int target;
	vector<int> numbers;
	map<int, int> map;

	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);

	target = 3;
	int nScore = 0;

	TargetNumber(numbers, 0, target, 0, nScore);
	
	
	system("pause");
	return nScore;
}