#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

vector<vector<int>> vMap;

struct qTree
{
	struct qTree* LT = nullptr;
	struct qTree* RT = nullptr;
	struct qTree* LB = nullptr;
	struct qTree* RB = nullptr;

	int nColor = -1; // -1, 0, 1
	int h;
	int w;
	int size;

	string strResult = "";
};

qTree* QuadTree(int h, int w, int size)
{
	qTree* qNode = new qTree;
	qNode->h = h;
	qNode->w = w;
	qNode->size = size;
	if (size == 1)
	{
		qNode->nColor = vMap[h][w];
		qNode->strResult += to_string(qNode->nColor);
		return qNode;
	}

	int nColor = vMap[h][w];
	int nHalf = size / 2;

	qNode->LT = QuadTree(h, w, nHalf);
	qNode->RT = QuadTree(h, w + nHalf, nHalf);
	qNode->LB = QuadTree(h + nHalf, w, nHalf);
	qNode->RB = QuadTree(h + nHalf, w + nHalf, nHalf);

	if (nColor == qNode->LT->nColor && nColor == qNode->RT->nColor && nColor == qNode->LB->nColor && nColor == qNode->RB->nColor)
	{
		qNode->nColor = nColor;
	}
	else
		qNode->nColor = -1;

	if (qNode->nColor >= 0)
		qNode->strResult = to_string(nColor);
	else
		qNode->strResult += '(' + qNode->LT->strResult + qNode->RT->strResult + qNode->LB->strResult + qNode->RB->strResult + ')';

	delete(qNode->LT);
	delete(qNode->RT);
	delete(qNode->LB);
	delete(qNode->RB);

	return qNode;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int nSzie;
	cin >> nSzie;
	vMap = vector<vector<int>>(nSzie, vector<int>(nSzie));

	for (int i = 0; i < nSzie; i++)
	{
		string strTemp;
		cin >> strTemp;

		for (int j = 0; j < nSzie; j++)
			vMap[i][j] = strTemp[j] - '0';
	}

	qTree* QT;

	QT = QuadTree(0, 0, nSzie);
	string strResult = QT->strResult;
	delete(QT);

	cout << strResult << '\n';

	return 0;
}