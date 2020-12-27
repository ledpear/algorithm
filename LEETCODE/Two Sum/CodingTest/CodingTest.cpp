// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int target;
	vector<int> nums;

	vector<int> answer;

	for (int i = 0; i < nums.size() - 1; i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				answer.push_back(nums[i]);
				answer.push_back(nums[j]);
			}
		}
	}
	return answer;

    return 0;
}

