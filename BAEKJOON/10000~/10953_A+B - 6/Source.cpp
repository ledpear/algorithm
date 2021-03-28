#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//define

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

//custum function
vector<string> parsing(const string& data, const char delimiter = ' ') {
	vector<string> result;
	string token;
	stringstream splitStream(data);

	while (getline(splitStream, token, delimiter)) {
		result.push_back(token);
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int testSize(0);
	cin >> testSize;

	//Solution
	for (int testCase = 0; testCase < testSize; ++testCase)
	{
		string input("");
		cin >> input;

		vector<string> strArr = parsing(input, ',');

		int result = stoi(strArr[0]) + stoi(strArr[1]);

		//Output
		cout << result << '\n';
	}

	////////////////////////////////////
	system("pause");
	return 0;
}