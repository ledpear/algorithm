#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int solution(string t, string p) 
{
	int answer = 0;
	int target = atoi(p.c_str());

	for (int i = 0; i < t.size() - p.size() + 1; ++i)
	{
		int currNum = atoi(t.substr(i, p.size()).c_str());
		if (currNum <= target)
			++answer;
	}

	return answer;
}

int main()
{
	int result = solution("10203", "15");
	return 0;
}