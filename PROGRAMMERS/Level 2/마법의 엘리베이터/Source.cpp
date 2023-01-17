#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

void search(int storey, bool isUP, int count, int& answer)
{
	if (storey < 10)
	{
		int sit1 = count + storey;
		int sit2 = count + (11 - storey);
		count = sit1 < sit2 ? sit1 : sit2;

		if (answer > count || answer == -1)
			answer = count;

		return;
	}

	const int num = storey % 10;
	storey /= 10;
	if (isUP)
	{
		count += (10 - num);
		storey += 1;
	}
	else
		count += num;

	search(storey, true, count, answer);
	search(storey, false, count, answer);
}

int solution(int storey) 
{
	int answer = -1;
	int count = 0;

	//모두 찾는다
	search(storey, true, count, answer);
	search(storey, false, count, answer);

	return answer;
}

int main()
{
	int answer = solution(678);
	return 0;
}