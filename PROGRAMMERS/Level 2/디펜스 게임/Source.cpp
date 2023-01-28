#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#include <queue>
#include <functional>
int solution(int n, int k, vector<int> enemy)
{
	//순서대로 들어오는 값을 더하는데
	//그중 높은 값은 더하지 않는다
	//벡터를 만들고 크기순으로 insert한다
	const int count = enemy.size();
	//vector<int> clear;
	priority_queue<int> clear;
	int sum = 0;

	//라운드를 순차적으로 돈다
	for (int round = 0; round < count; ++round)
	{
		const int enemyNum = enemy[round];
		int index = 0;
		
		//1. 큐의 크기가 K보다 작으면 일단 넣는다
		if (clear.size() < k)
		{
			clear.push(enemyNum);
			continue;
		}

		//2. 큐의 top(가장 작은 값)보다 작거나 같으면 sum에 더해주고 값이 넘어가면 끝난다
		if ( enemyNum <= clear.top() )
		{
			sum += enemyNum;
			if(sum > n)
				return round;

			continue;
		}

		//3. 큐에 있는 값보다 크면 큐의 top을 pop해서 sum에 넣어주고 큐에 넣는다
		sum += clear.top();
		if (sum > n)
			return round;

		clear.pop();
		clear.push(enemyNum);
	}

	return count;
}

int main()
{
	int answer = 0;
	answer = solution(7, 3, vector<int>({ 4, 2, 4, 5, 3, 3, 1 }));
	return 0;
}