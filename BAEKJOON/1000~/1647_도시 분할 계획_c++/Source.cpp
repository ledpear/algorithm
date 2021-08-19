#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::ios_base;
using std::priority_queue;
using std::max;

//custum function
//우선순위 큐 용 구조체
struct edge
{
	int lowNode, highNode, cost;
	edge(int inputLowNode, int inputHighNode, int inputCost) 
		: lowNode(inputLowNode), highNode(inputHighNode), cost(inputCost) {};
};

struct compare
{
	bool operator()(edge e1, edge e2)
	{
		return e1.cost > e2.cost;
	}
	bool operator++() {

	}
};

//union find
int find(vector<int>& parentsArr, int node)
{
	//자기 자신이 최상위 노드일 때 까지 반복
	if (node == parentsArr[node])
	{
		return node;
	}

	//최상위 노드를 반환받고 만약 저장하고 있는 값이 최상위 노드가 아니면 갱신된다.
	return parentsArr[node] = find(parentsArr, parentsArr[node]);
}

bool unionNode(vector<int>& parentsArr, int nodeA, int nodeB)
{
	int nodeParentsA = find(parentsArr, nodeA);
	int nodeParentsB = find(parentsArr, nodeB);

	//같은 노드가 최상위 노드라면 cycle이 생긴다.
	if (nodeParentsA == nodeParentsB)
	{
		return false;
	}
	
	//cycle이 생기지 않으면 트리를 결합해준다.
	//낮은 노드가 상위노드 이며 한쪽 최상위 노드를 갱신해주면 나머지 노드들은 find시 갱신된다.
	if (nodeParentsA < nodeParentsB)
	{
		parentsArr[nodeParentsB] = nodeParentsA;
	}
	else
	{
		parentsArr[nodeParentsA] = nodeParentsB;
	}
	
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nodeSize(0), edgeSize(0);
	cin >> nodeSize >> edgeSize;
	priority_queue<edge, vector<edge>, compare> pq;

	for (int index(0); index < edgeSize; ++index)
	{
		int nodeA, nodeB, cost;
		cin >> nodeA >> nodeB >> cost;
		//간선을 우선순위 큐에 삽입
		pq.push(edge(nodeA, nodeB, cost));
	}

	//Solution
	int count(0), maxCost(0), sumCost(0);
	vector<int> parentsArr(nodeSize + 1);
	//각 노드의 처음 최상위 노드는 자기 자신
	for (int index(1); index <= nodeSize; ++index)
	{
		parentsArr[index] = index;
	}

	while (!pq.empty() && count < nodeSize - 1)
	{
		int nowNodeA(pq.top().lowNode), nowNodeB(pq.top().highNode), nowCost(pq.top().cost);
		pq.pop();

		//병합이 성공하면 간선이 추가된 것이므로 비용을 더해주고 최댓값을 갱신한다.
		if (unionNode(parentsArr, nowNodeA, nowNodeB))
		{
			maxCost = max(maxCost, nowCost);
			sumCost += nowCost;
			++count;
		}		
	}

	//Output
	cout << sumCost - maxCost << '\n';

	return 0;
}