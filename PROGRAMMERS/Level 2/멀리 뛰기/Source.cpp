#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

long long solution(int n) 
{
	if (n <= 2)
		return n;

	vector<int> list = vector<int>{ 1, 2 };
	for (int i = 2; i < n; ++i)
	{
		list.push_back((list[i - 1] + list[i - 2]) % 1234567);
	}

	return list[n - 1];
}

int main()
{
	return 0;
}