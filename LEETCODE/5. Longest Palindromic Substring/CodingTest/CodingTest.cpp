// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	string s;
	

	int nMax = 0;

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 1; j <= s.size() - i; j++)
		{
			string temp = s.substr(i, j);
			
			int strPos;
			bool bResult = true;

			// 검사할 문자열의 사이즈가 1이 아닐 때
			if (temp.size() != 1)
			{
				if (s[i + j + 1] == temp[temp.size() - 1])//반복하는지 검사할 다음 문자가 끝이나 끝 전이랑 같은지 확인
				{
					strPos = temp.size() - 1;
				}
				else if (s[i + j + 1] == temp[temp.size() - 2])
				{
					strPos = temp.size() - 2;
				}
				else //둘다 같지 않으면 반복하지 않는 것이기 때문에 Fail처리
				{
					strPos = -1;
				}

				// 반복되는 문자인지 판단
				if (strPos != -1)
				{
					for (--strPos; strPos >= 0; strPos--)
					{
						int s_pos = i + j + (temp.size() - strPos - 1);

						bResult = (s[s_pos] == temp[strPos]);
						if (!bResult) false;
					}
				}
			}
			else //사이즈가 1일 때
			{

			}
			
			// 결과 적용
			if (bResult)
			{
				if (nMax < temp.size())
					nMax = temp.size();
			}
		}
	}

    return 0;
}

