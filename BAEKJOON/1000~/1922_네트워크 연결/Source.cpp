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

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::ios_base;

using ull = unsigned long long;
using location = pair<int, int>;
using matrix = vector<vector<int>>;

using namespace std;

//define
//custum function

struct cmp 
{
	bool operator()(vector<int> a, vector<int> b) {
		return a[2] > b[2];
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Input
	//노드의 크기
	int nodeSize = 0;
	cin >> nodeSize;

	int edgeSize = 0;
	cin >> edgeSize;

	priority_queue<vector<int>, vector<vector<int>>, cmp> nodeEdges;
	for (int i = 0; i < edgeSize; ++i)
	{
		int to, from, cost;
		cin >> to >> from >> cost;
		vector<int> inputVecter;
		inputVecter.push_back(to);
		inputVecter.push_back(from);
		inputVecter.push_back(cost);
		nodeEdges.push(inputVecter);
	}

	//Solution
	//크루스칼 알고리즘을 적용하자
	//유니온 파인드를 적용하여 찾자
	vector<int> unionFind;
	for (int i = 0; i <= nodeSize; ++i)
		unionFind.push_back(i);

	//pq에서 cost가 작은 순으로 시작
	int count = 0;
	int result = 0;
	while (nodeEdges.empty() == false)
	{
		int nodeA = nodeEdges.top()[0];
		int nodeB = nodeEdges.top()[1];
		int cost = nodeEdges.top()[2];
		nodeEdges.pop();

		if (unionFind[nodeA] == unionFind[nodeB])
			continue;

		//같은 그룹에 있지 않다면
		//큰 쪽 노드를 작은 쪽 노드로 바꿔준다
		int beforeGroup = unionFind[min(nodeA, nodeB)];
		int afterGroup = unionFind[max(nodeA, nodeB)];
		for (int i = 1; i <= nodeSize; ++i)
		{
			if (unionFind[i] == beforeGroup)
				unionFind[i] = afterGroup;
		}

		result += cost;
		++count;
		if (count == nodeSize - 1)
			break;
	}

	//Output
	cout << result << endl;

	////////////////////////////////////
	system("pause");
	return 0;
}