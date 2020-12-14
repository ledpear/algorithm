// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct vPoint {   // ����ü ����
	int X;
	int Y;
	int Size;
};

bool compare(vPoint a, vPoint b)
{
	return a.Size > b.Size;
}

int main()
{
	vector<vector<int>> board = { {0, 0, 1, 1},{1, 1, 1, 1}};
	//vector<vector<int>> board = { {0, 1, 1, 1},{1, 1, 1, 1},{1, 1, 1, 1},{0, 0, 1, 0} };
	
	int answer;
	int nHeight = board.size();
	int nWidth = board[0].size();

	vector<vector<int>> vPass(nHeight, vector<int>(nWidth, 0));

	vector<vPoint> vPoint;

	int nMax = -1;

	for (int nY = 0; nY < nHeight; nY++)
	{
		for (int nX = 0; nX < nWidth; nX++)
		{
			if (board[nY][nX] == 1)
			{
				//�ش� ���尡 1�̸� Ž������
				int nSize = 1;
				
				struct vPoint vTemp;
				vPass[nY][nX] = true;
				vTemp.X = nX;
				vTemp.Y = nY;

				while (true)
				{
					//����� �迭�� ũ�⸦ �ʰ��ϸ� ������� �ϳ� ���� break
					if (nY + nSize >= nHeight || nX + nSize >= nWidth)
					{
						--nSize;

						break;
					}

					int y = nY + nSize;
					int x = nX + nSize;
					bool bResult = true;

					if (board[nY][x] == 1 && board[y][nX] == 1)
					{
						++nSize;
					}
					else            // ������� �������� break
					{
						--nSize;
						break;
					}					
				}

				vTemp.Size = nSize;
				vPoint.push_back(vTemp);
			}
		}
	}

	sort(vPoint.begin(), vPoint.end(), compare);

	for (int i = 0; i < vPoint.size(); i++)
	{
		int nX = vPoint[i].X;
		int nY = vPoint[i].Y;
		int nSize = vPoint[i].Size;

		bool bResult = true;

		for (int j = nY; j <= nY + nSize; j++)
		{
			for (int i = nX; i <= nX + nSize; i++)
			{
				if (board[j][i] == 0)
				{
					bResult = false;
					break;
				}
			}
		}

		if (bResult)
		{
			answer = ++nSize * nSize;
			break;
		}
	}

    return 0;
}

