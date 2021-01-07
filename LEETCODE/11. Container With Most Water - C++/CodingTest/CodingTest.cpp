// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		vector<pair<int, int>> Data;
		for (int i = 0; i < height.size(); i++)
		{
			Data.push_back({ i, height[i] });
		}
	}
};

int main()
{
    return 0;
}

