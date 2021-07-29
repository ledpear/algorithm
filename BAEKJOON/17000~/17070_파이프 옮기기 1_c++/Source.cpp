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

using namespace std;

//define

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

class Pipe
{
public:
	location pipeFront, pipeRear;
	Pipe()
	{
		pipeFront = { 0, 0 };
		pipeRear = { 0, 1 };
	}	
};

//custum function
void goRight(matrix& inputMatrix, queue<Pipe>& BFS_Queue, Pipe nowPipe, int mapSize)
{
	if (nowPipe.pipeRear.second + 1 < mapSize && 
		inputMatrix[nowPipe.pipeRear.first][nowPipe.pipeRear.second + 1] == 0)
	{
		nowPipe.pipeFront = nowPipe.pipeRear;
		++nowPipe.pipeRear.second;
		BFS_Queue.push(nowPipe);
	}
}

void goDown(matrix& inputMatrix, queue<Pipe>& BFS_Queue, Pipe nowPipe, int mapSize)
{
	if (nowPipe.pipeRear.first + 1 < mapSize && 
		inputMatrix[nowPipe.pipeRear.first + 1][nowPipe.pipeRear.second] == 0)
	{
		nowPipe.pipeFront = nowPipe.pipeRear;
		++nowPipe.pipeRear.first;
		BFS_Queue.push(nowPipe);
	}
}

void goDiagonal(matrix& inputMatrix, queue<Pipe>& BFS_Queue, Pipe nowPipe, int mapSize)
{
	if (nowPipe.pipeRear.second + 1 < mapSize && nowPipe.pipeRear.first + 1 < mapSize && 
		inputMatrix[nowPipe.pipeRear.first][nowPipe.pipeRear.second + 1] == 0 &&
		inputMatrix[nowPipe.pipeRear.first + 1][nowPipe.pipeRear.second] == 0 &&
		inputMatrix[nowPipe.pipeRear.first + 1][nowPipe.pipeRear.second + 1] == 0)
	{
		nowPipe.pipeFront = nowPipe.pipeRear;
		++nowPipe.pipeRear.first;
		++nowPipe.pipeRear.second;
		BFS_Queue.push(nowPipe);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int matrixSize(0);
	cin >> matrixSize;
	matrix inputMatrix(matrixSize, vector<int>(matrixSize));
	for (int x(0); x < matrixSize; ++x)
	{
		for (int y(0); y < matrixSize; ++y)
		{
			cin >> inputMatrix[x][y];
		}
	}

	queue<Pipe> BFS_Queue;
	BFS_Queue.push(Pipe());
	int count = 0;

	//Solution
	while (!BFS_Queue.empty())
	{
		Pipe nowPipe = BFS_Queue.front();
		BFS_Queue.pop();

		if (nowPipe.pipeRear.first == matrixSize - 1 && nowPipe.pipeRear.second == matrixSize - 1)
		{
			++count;
			continue;
		}

		if (nowPipe.pipeFront.first == nowPipe.pipeRear.first)
		{
			goRight(inputMatrix, BFS_Queue, nowPipe, matrixSize);
			goDiagonal(inputMatrix, BFS_Queue, nowPipe, matrixSize);
		}
		else if (nowPipe.pipeFront.second == nowPipe.pipeRear.second)
		{
			goDiagonal(inputMatrix, BFS_Queue, nowPipe, matrixSize);
			goDown(inputMatrix, BFS_Queue, nowPipe, matrixSize);
		}
		else
		{
			goRight(inputMatrix, BFS_Queue, nowPipe, matrixSize);
			goDiagonal(inputMatrix, BFS_Queue, nowPipe, matrixSize);
			goDown(inputMatrix, BFS_Queue, nowPipe, matrixSize);
		}
	}

	//Output
	cout << count << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}