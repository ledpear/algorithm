#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

#include <set>
using namespace std;


int solution(vector<int> topping) 
{
	int answer = 0;
	//잘랐을 때 위치를 기준으로 왼쪽에 누적 종류를 구한다
	//오른 쪽도 구한다(단 뒤부터 탐색해야함)
	//1차이나게 비교하면서 같은 값이면 된다
	const int size = topping.size();
	//왼쪽 누적 종류
	vector<int> left = vector<int>(size, 0);
	{
		set<int> log;
		int count = 0;
		for (int i = 0; i < size; ++i)
		{
			if (log.find(topping.at(i)) == log.end())
			{
				++count;
				log.insert(topping.at(i));
			}
			left.at(i) = count;
		}
	}
	
	{
		set<int> log;
		int count = 0;
		for (int i = size - 1; i > 0; --i)
		{
			if (log.find(topping.at(i)) == log.end())
			{
				++count;
				log.insert(topping.at(i));
			}

			if(left[i - 1] == count)
				++answer;
		}
	}

	return answer;
}

int main()
{
	return 0;
}