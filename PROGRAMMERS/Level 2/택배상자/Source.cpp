#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

int solution(vector<int> order) 
{
	int answer = 0;
	int index = 0;
	int size = order.size();
	queue<int> main;
	vector<int> sub;

	for (int i = 1; i <= size; ++i)
	{
		main.push(i);
	}

	while (true)
	{	
		if (main.size() != 0 && order[index] == main.front())
		{
			++index;
			++answer;
			main.pop();
			continue;
		}		
		
		if (sub.size() != 0 && order[index] == sub.back())
		{
			++index;
			++answer;
			sub.pop_back();
			continue;
		}

		if (main.size() == 0)
			break;

		sub.push_back(main.front());
		main.pop();
	}

	return answer;
}

int main()
{
	{
		vector<int> list = { 4, 3, 1, 2, 5 };
		int answer = solution(list);
		cout << answer << endl;
	}

	{
		vector<int> list = { 5, 4, 3, 2, 1 };
		int answer = solution(list);
		cout << answer << endl;
	}

	return 0;
}
