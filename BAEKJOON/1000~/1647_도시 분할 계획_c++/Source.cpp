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
//�켱���� ť �� ����ü
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
	//�ڱ� �ڽ��� �ֻ��� ����� �� ���� �ݺ�
	if (node == parentsArr[node])
	{
		return node;
	}

	//�ֻ��� ��带 ��ȯ�ް� ���� �����ϰ� �ִ� ���� �ֻ��� ��尡 �ƴϸ� ���ŵȴ�.
	return parentsArr[node] = find(parentsArr, parentsArr[node]);
}

bool unionNode(vector<int>& parentsArr, int nodeA, int nodeB)
{
	int nodeParentsA = find(parentsArr, nodeA);
	int nodeParentsB = find(parentsArr, nodeB);

	//���� ��尡 �ֻ��� ����� cycle�� �����.
	if (nodeParentsA == nodeParentsB)
	{
		return false;
	}
	
	//cycle�� ������ ������ Ʈ���� �������ش�.
	//���� ��尡 ������� �̸� ���� �ֻ��� ��带 �������ָ� ������ ������ find�� ���ŵȴ�.
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
		//������ �켱���� ť�� ����
		pq.push(edge(nodeA, nodeB, cost));
	}

	//Solution
	int count(0), maxCost(0), sumCost(0);
	vector<int> parentsArr(nodeSize + 1);
	//�� ����� ó�� �ֻ��� ���� �ڱ� �ڽ�
	for (int index(1); index <= nodeSize; ++index)
	{
		parentsArr[index] = index;
	}

	while (!pq.empty() && count < nodeSize - 1)
	{
		int nowNodeA(pq.top().lowNode), nowNodeB(pq.top().highNode), nowCost(pq.top().cost);
		pq.pop();

		//������ �����ϸ� ������ �߰��� ���̹Ƿ� ����� �����ְ� �ִ��� �����Ѵ�.
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