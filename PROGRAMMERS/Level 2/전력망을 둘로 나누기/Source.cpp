#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
//잘렸을 때 연결된 노드 수를 리턴하는 함수
int search(const int startNode, const int fromNode, vector<vector<int>>& route)
{
	int result = 1;
	for (int targetNode : route[startNode])
	{
		if (targetNode == fromNode)
			continue;

		result += search(targetNode, startNode, route);
	}
	return result;
}

int solution(int n, vector<vector<int>> wires) 
{
	//각 노드 당 갈 수 있는 노드가 저장된 vector 만들기
	vector<vector<int>> route = vector<vector<int>>(n + 1);
	for (vector<int> wire : wires)
	{
		const int from = wire[0];
		const int to = wire[1];

		route[from].push_back(to);
		route[to].push_back(from);
	}

	//하나씩 못돌게 하면서 탐색
	int answer = n;
	for (int i = 0; i < n - 1; ++i)
	{
		vector<int> cutWires = wires[i];
		int nodeASearch = search( cutWires[0], cutWires[1], route);
		int nodeBSearch = search( cutWires[1], cutWires[0], route);

		answer = min(answer, abs(nodeASearch - nodeBSearch));
	}

	//가장 적은 값을 리턴(min)
	return answer;
}

int main()
{
	vector<vector<int>> wires;
	wires.push_back(vector<int>{1, 3});
	wires.push_back(vector<int>{2, 3});
	wires.push_back(vector<int>{3, 4});
	wires.push_back(vector<int>{4, 5});
	wires.push_back(vector<int>{4, 6});
	wires.push_back(vector<int>{4, 7});
	wires.push_back(vector<int>{7, 8});
	wires.push_back(vector<int>{7, 9});
	int result = solution(9, wires);
	return 0;
}