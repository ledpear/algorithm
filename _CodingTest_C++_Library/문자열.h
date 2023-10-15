#pragma once
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void parsing(const string& data, vector<string>& result, const char delimiter = ' ')
{
	string token;
	stringstream splitStream(data);

	while (getline(splitStream, token, delimiter))
		result.push_back(token);
}