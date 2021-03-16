#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

typedef unsigned long long ull;
typedef pair<ull, ull> p;
typedef vector<vector<int>> vmap;

//custum function

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//2차원 배열을 사용해서 빈 공간은 0 뱀은 1로 표시
	//뱀은 큐로 구성
	//뱀의 시작 위치는 0,0 방향은 우
	//매 초마다 이동
	//Declaration
	int nSize, nApple, nCommend, nDir = 0, nCount = 0;
	vmap vMap;	//0은 아무것도 없음 1은 사과 2는 뱀몸
	vector<char> cCommend(10001);
	deque<p> dpSnake;

	//0     1     2     3 // Dir
	//우 -> 하 -> 좌 -> 상 // 오른쪽 방향전환 기준
	int nMoveX[4] = {1, 0, -1, 0};	
	int nMoveY[4] = {0, 1, 0, -1};

	//Input
	cin >> nSize;
	vMap = vmap(nSize, vector<int>(nSize, false));

	cin >> nApple;	
	for (int i = 0; i < nApple; i++)
	{
		int tempX, tempY;
		cin >> tempY >> tempX;
		vMap[tempY - 1][tempX - 1] = 1;
	}

	cin >> nCommend;
	for (int i = 0; i < nCommend; i++)
	{
		int nTemp;
		char cTemp;
		cin >> nTemp >> cTemp;
		cCommend[nTemp] = cTemp;
	}

	//Solution
	dpSnake.push_back(p(0, 0));
	vMap[0][0] = 2;
	while (true)
	{
		nCount++;

		//머리 이동
		p pHead = dpSnake.back();
		int nPosX, nPosY;

		nPosX = pHead.first + nMoveX[nDir];
		nPosY = pHead.second + nMoveY[nDir];

		dpSnake.push_back(p(nPosX, nPosY));

		//사과가 있지 않으면 꼬리하나 pop
		if (vMap[nPosY][nPosX] == 0)
		{
			vMap[dpSnake.front().second][dpSnake.front().first] = 0;
			dpSnake.pop_front();
		}

		//사과가 있는지 확인하고 뱀몸으로 변환
		vMap[nPosY][nPosX] = 2;
		
		//방향 전환 커맨드가 있으면 전환
		if (cCommend[nCount] == 'D')
		{
			nDir = (nDir + 1) % 4;
		}
		else if (cCommend[nCount] == 'L')
		{
			nDir -= 1;
			if (nDir < 0) nDir = 3;
		}

		//이동할 곳이 이동가능 한 곳인지 검사
		nPosX += nMoveX[nDir];
		nPosY += nMoveY[nDir];

		if (nPosX < 0 || nPosX >= nSize || nPosY < 0 || nPosY >= nSize || vMap[nPosY][nPosX] == 2)
			break;
	}

	//Output
	cout << nCount + 1 << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}