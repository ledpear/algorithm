// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int nLast = -1;
	string s;
	s = "abcabcdede";
	int answer = 0;

	// 1. ����� ����� ���Ѵ�.
	// 2. ����� ������ ��ŭ ���ڿ��� ó������ ������ ���ϸ鼭 ������ ����
	// 3. ����� �� ������ ����� ���ڸ� ����� string�� �����ϰ� ����� ���� ��ġ���� �˻�


	//int pos = 0;
	string temp;
	string Result = "";
	answer = s.size();
	for (int nSize = 1; nSize <= s.size() / 2; nSize++) //��� ũ��
	{
		for (int nPos = 0; /*s.size() - nPos >= nSize*/; nPos += nSize) //��� ������ ���ڿ�
		{
			if (nPos + nSize > s.size())
			{
				if(nPos < s.size())
					Result += s.substr(nPos);
				break;
			}

			temp = s.substr(nPos, nSize);
			if (s.substr(nPos + nSize, nSize) == temp)
			{
				int nCount = 1;
				while (true)
				{
					if (nPos + (nSize * (nCount + 1)) > s.size())
					{
						break;
					}
					else if (s.substr(nPos + (nSize * nCount), nSize) == temp)
					{
						nCount++;
					}
					else
					{
						break;
					}
				}
				Result += to_string(nCount);
				Result += s.substr(nPos, nSize);
				nPos = nPos + ((nCount - 1) * nSize);
			}
			else
			{
				if (nPos + nSize <= s.size())
				{
					Result += s.substr(nPos, nSize);
				}
				else
					Result += s.substr(nPos);
				continue;
			}
		}
		if (answer > Result.size())	answer = Result.size();
		Result = "";
	}

    return 0;
}

