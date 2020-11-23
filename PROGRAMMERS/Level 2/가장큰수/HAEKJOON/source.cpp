#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>

using namespace std;

bool cmd(string a, string b)
{
	return a + b > b + a;
}

int main()
{
	vector<int> numbers;

	numbers.push_back(3);
	numbers.push_back(30);
	numbers.push_back(34);
	numbers.push_back(5);
	numbers.push_back(9);

	vector<string> strNumbers;
	for (int i = 0; i < numbers.size(); i++)
		strNumbers.push_back(to_string(numbers[i]));

	sort(strNumbers.begin(), strNumbers.end(), cmd);
	string strResult = "";

	for (int i = 0; i < strNumbers.size(); i++)
		strResult += strNumbers[i];

	return 0;
}