#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

//custum function
int BfsEgde(vector<int>& vVisit, const vector<vector<int>>& vEdges, int nStart, int nTarget)
{
	using node = pair<int, int>;
	int nCount(0);

	queue<node> qNode;
	qNode.push(node(nStart, nCount));
	vVisit[nStart] = true;

	while (qNode.empty() == false)
	{
		const int nNowNode = qNode.front().first;
		const int nDist = qNode.front().second;
		qNode.pop();

		//목적지인지 확인
		if (nNowNode == nTarget)
		{
			nCount = nDist;
			break;
		}

		//이동할 수 있는 곳은 이동
		for (auto& nTargetNode : vEdges[nNowNode])
		{
			if (vVisit[nTargetNode] == false)
			{
				vVisit[nTargetNode] = true;
				qNode.push(node(nTargetNode, nDist + 1));
			}
		}
	}

	return nCount;
}

int solution(string begin, string target, vector<string> words) 
{
	int answer(0), nTarget(-1);

	for (int i = 0; i < words.size(); ++i)
	{
		if (words[i] == target)
		{
			nTarget = i + 1;
		}
	}
	if (nTarget == -1)
	{
		return 0;
	}

	words.insert(words.begin(), begin);
	int nSize(words.size()), nWordLength(begin.size());
	vector<vector<int>> vEgdes(nSize);

	//엣지 구하기
	for (int i = 0; i < nSize; ++i)
	{
		for (int j = i + 1; j < nSize; j++)
		{
			int nCount(0);
			for (int nTextIndex = 0; nTextIndex < nWordLength; ++nTextIndex)
			{
				if (words[i][nTextIndex] != words[j][nTextIndex])
				{
					++nCount;
				}
				if (nCount > 1)
				{
					break;
				}
			}

			if (nCount == 1)
			{
				vEgdes[i].push_back(j);
				vEgdes[j].push_back(i);
			}
		}
	}

	vector<int> vVisit(nSize, 0);
	answer = BfsEgde(vVisit, vEgdes, 0, nTarget);

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration


	//Solution


	//Output
	cout << solution("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log", "cog"}) << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}