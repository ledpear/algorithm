#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define INF		INT_MAX

int FindMin(vector<int> vWeight, vector<bool> vVisit)
{
	int nMin = INF;


}

int main()
{
	int V, E;
	cin >> V >> E;

	vector<int> vWeight(V + 1, INF);
	vector<bool> vVisit(V + 1, false);
	int StartNode;
	cin >> StartNode;

	vWeight[StartNode] = 0;

	return 0;
}