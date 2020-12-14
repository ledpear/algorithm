// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	//vector<vector<int>> board = { {0, 0, 0, 0},{0, 0, 0, 1}};
	vector<vector<int>> board = { {0, 1, 1, 1},{1, 1, 1, 1},{1, 1, 1, 1},{0, 0, 1, 0} };
	
	int nHeight = board.size();
	int nWidth = board[0].size();

	vector<vector<int>> vPass(nHeight, vector<int>(nWidth, 0));

	int nMax = -1;

	for (int nY = 0; nY < nHeight; nY++)
	{
		for (int nX = 0; nX < nWidth; nX++)
		{
			if (board[nY][nX] == 1 && vPass[nY][nX] == 0)
			{
				//해당 보드가 1이면 탐색시작
				int nSize = 1;
				
				vPass[nY][nX] = true;

				while (true)
				{
					//사이즈가 배열의 크기를 초과하면 사이즈에서 하나 빼고 break
					if (nY + nSize >= nHeight || nX + nSize >= nWidth)
					{
						--nSize;
						break;
					}
					bool bResult = true;

					int y = nY + nSize;
					int x = nX + nSize;
					//y방향 확인
					for (int i = nY; i <= y; i++)
					{
						if (board[i][x] == 0)
						{
							bResult = false;
							break;
						}
						else
							vPass[i][x] = true;
					}
					//y에서 0이 안나왔으면 x방향 확인, 
					if (bResult)
					{
						for (int i = nX; i < x; i++)
						{
							if (board[y][i] == 0)
							{
								bResult = false;
								break;
							}
							else
								vPass[i][x] = true;
						}
					}

					if (bResult)	// 모두 통과 했으면 사이즈를 키워서 확인
					{
						++nSize;
					}
					else            // 통과하지 못했으면 break
					{
						--nSize;
						break;
					}
				}

				if (nMax < nSize) nMax = nSize;
			}

			
		}
	}
	int answer;
	if (nMax == -1)
		answer = 0;
	else
		answer = ++nMax * nMax;

    return 0;
}

