#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void BaguniClear(vector<int> &vBoard, int &count)
{
	int nSize = vBoard.size();
	for (int i = 0; i < vBoard.size() - 1; i++)
	{
		if (vBoard[i] == vBoard[i+1])
		{
			vBoard.erase(vBoard.begin() + i, vBoard.begin() + i + 2);
			count++;
			break;
		}
	}
}

int main()
{
	vector<vector<int>> board;
	vector<int> moves;

	vector<int> temp;
	temp.push_back(0);
	temp.push_back(0);
	temp.push_back(0);
	temp.push_back(0);
	temp.push_back(0);
	board.push_back(temp);
	temp.clear();
	temp.push_back(0);
	temp.push_back(0);
	temp.push_back(1);
	temp.push_back(0);
	temp.push_back(3);
	board.push_back(temp);
	temp.clear();
	temp.push_back(0);
	temp.push_back(2);
	temp.push_back(5);
	temp.push_back(0);
	temp.push_back(1);
	board.push_back(temp);
	temp.clear();
	temp.push_back(4);
	temp.push_back(2);
	temp.push_back(4);
	temp.push_back(4);
	temp.push_back(2);
	board.push_back(temp);
	temp.clear();
	temp.push_back(3);
	temp.push_back(5);
	temp.push_back(1);
	temp.push_back(3);
	temp.push_back(1);
	board.push_back(temp);
	temp.clear();

	moves.push_back(1);
	moves.push_back(5);
	moves.push_back(3);
	moves.push_back(5);
	moves.push_back(1);
	moves.push_back(2);
	moves.push_back(1);
	moves.push_back(4);
	moves.push_back(2);
	moves.push_back(5);
	moves.push_back(2);
	moves.push_back(3);
	moves.push_back(3);
	moves.push_back(5);
	moves.push_back(3);
	moves.push_back(5);


	int answer = 0;

	int nSize = board.size();
	int *nPoint = new int[nSize];
	memset(nPoint, 0, sizeof(int) * nSize);

	for (int x = 0; x < nSize; x++)
	{
		for (int y = 0; y < nSize; y++)
		{
			if (board[y][x] == 0)
			{
				nPoint[x] = y + 1;
			}

		}
	}

	vector<int> vBaguni;
	int nCount = 0;
	for (int i = 0; i < moves.size(); i++)
	{
		if (nPoint[moves[i] - 1] < 5)
		{
			vBaguni.push_back(board[nPoint[moves[i] - 1]++][moves[i] - 1]);
			if (vBaguni.size() >= 2)
				BaguniClear(vBaguni, nCount);
		}
	}
	cout << nCount * 2 << endl;
	system("pause");
	return 0;
}