#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int solution(int a, int b, int n) 
{
	//a개를 가져다 주면 b개를 준다
	int answer = 0;

	int count = n;
	while (true)
	{
		//받을 수 있는 수 계산
		int bonus = (count / a) * b;
		//결과에 더한다
		answer += bonus;

		//총량 업데이트
		count = (count % a) + bonus;

		//a보다 작으면 끝
		if (count < a)
			break;
	}

	return answer;
}

int main()
{
	int a = 0;
	a = solution(2, 1, 20);
	a = solution(3, 1, 20);
	return 0;
}