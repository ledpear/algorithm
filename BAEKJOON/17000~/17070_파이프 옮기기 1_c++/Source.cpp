#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//define

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

//custum function
class Solution
{
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

public:
	Solution(int matrixSize, matrix inputMatrix)
	{
		this->matrixSize = matrixSize;
		this->inputMatrix = inputMatrix;
	}
	~Solution()
	{
	}

	int solution()
	{
		init();
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
				goRight(nowPipe);
				goDiagonal(nowPipe);
			}
			else if (nowPipe.pipeFront.second == nowPipe.pipeRear.second)
			{
				goDiagonal(nowPipe);
				goDown(nowPipe);
			}
			else
			{
				goRight(nowPipe);
				goDiagonal(nowPipe);
				goDown(nowPipe);
			}
		}

		return count;
	}

private:
	int matrixSize;
	matrix inputMatrix;
	queue<Pipe> BFS_Queue;

	void init()
	{
		BFS_Queue = queue<Pipe>();
	}

	void goRight(Pipe nowPipe)
	{
		if (nowPipe.pipeRear.second + 1 < matrixSize &&
			inputMatrix[nowPipe.pipeRear.first][nowPipe.pipeRear.second + 1] == 0)
		{
			nowPipe.pipeFront = nowPipe.pipeRear;
			++nowPipe.pipeRear.second;
			BFS_Queue.push(nowPipe);
		}
	}

	void goDown(Pipe nowPipe)
	{
		if (nowPipe.pipeRear.first + 1 < matrixSize &&
			inputMatrix[nowPipe.pipeRear.first + 1][nowPipe.pipeRear.second] == 0)
		{
			nowPipe.pipeFront = nowPipe.pipeRear;
			++nowPipe.pipeRear.first;
			BFS_Queue.push(nowPipe);
		}
	}

	void goDiagonal(Pipe nowPipe)
	{
		if (nowPipe.pipeRear.second + 1 < matrixSize && nowPipe.pipeRear.first + 1 < matrixSize &&
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
};

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

	Solution sol(matrixSize, inputMatrix);

	//Output
	cout << sol.solution() << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}