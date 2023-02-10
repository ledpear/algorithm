#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

//r이 p가 될것이다
bool compare(string l, string r)
{
	int length = l.length();
	for (int i = 0; i < length; ++i)
	{
		if (l[i] > r[i])
			return false;
		else if (l[i] < r[i])
			return true;
	}
	return true;
}

int solution(string t, string p) 
{
	int answer = 0;
	for (int i = 0; i < t.size() - p.size() + 1; ++i)
	{
		string currNum = t.substr(i, p.size()).c_str();
		if (compare(currNum, p))
			++answer;
	}

	return answer;
}

int main()
{
	int result = solution("10203", "15");
	return 0;
}