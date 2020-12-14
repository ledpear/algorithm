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
				//�ش� ���尡 1�̸� Ž������
				int nSize = 1;
				
				vPass[nY][nX] = true;

				while (true)
				{
					//����� �迭�� ũ�⸦ �ʰ��ϸ� ������� �ϳ� ���� break
					if (nY + nSize >= nHeight || nX + nSize >= nWidth)
					{
						--nSize;
						break;
					}
					bool bResult = true;

					int y = nY + nSize;
					int x = nX + nSize;
					//y���� Ȯ��
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
					//y���� 0�� �ȳ������� x���� Ȯ��, 
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

					if (bResult)	// ��� ��� ������ ����� Ű���� Ȯ��
					{
						++nSize;
					}
					else            // ������� �������� break
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

