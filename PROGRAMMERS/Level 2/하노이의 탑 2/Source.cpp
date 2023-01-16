#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

void hanoi(int from, int to, int size, vector<vector<int>>& answer)
{
	if (size == 1)
	{
		answer.push_back(vector<int>{from, to});
		return;
	}

	int empty = 6 - from - to;

	hanoi(from, empty, size - 1, answer);
	answer.push_back(vector<int>{from, to});
	hanoi(empty, to, size - 1, answer);
}

vector<vector<int>> solution(int n) 
{
	vector<vector<int>> answer;
	hanoi(1, 3, n, answer);
	return answer;
}

int main() 
{
	solution(15);
}