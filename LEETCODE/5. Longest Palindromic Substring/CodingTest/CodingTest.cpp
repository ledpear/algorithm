// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	string s = "abbcccbbbcaaccbababcbcabca";
	
	string strResult;
	string MaxResult = "";
	int nMax = 0;

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 1; j <= s.size() - i; j++)
		{
			if (i + j * 2 - 1> s.size())
			{
				if (MaxResult.compare("") == 0)	MaxResult += s[i];
				break;
			}

			string temp = s.substr(i, j);
			string strFirst, strSecond;
			strFirst = temp;
			strSecond = temp;
			strResult = temp;

			int strFirstPos, strSecondPos;
			bool bResult = false;
			bool bOverlap = false;

			int ComparePos = i + j;

			bool FirstCompare = false;
			bool SecondCompare = false;

			// 검사할 문자열의 사이즈가 1이 아닐 때
			if (temp.size() != 1)
			{
				if (i + j * 2 <= s.size() && s[ComparePos] == temp[temp.size() - 1])//반복하는지 검사할 다음 문자가 끝이나 끝 전이랑 같은지 확인
				{
					strFirstPos = temp.size() - 1;
					bOverlap = true;
					strFirst += s[ComparePos];
					FirstCompare = true;
				}
				if (s[ComparePos] == temp[temp.size() - 2])
				{
					strSecondPos = temp.size() - 2;
					strSecond += s[ComparePos];
					SecondCompare = true;
				}

				bResult = FirstCompare || SecondCompare;

				// 반복되는 문자인지 판단
				if (bResult)
				{
					bool FirstSuccess = FirstCompare;
					bool SecondSuccess = SecondCompare;
					
					if (FirstCompare)
					{
						int Pos = ComparePos;
						for (--strFirstPos; strFirstPos >= 0; strFirstPos--)
						{
							if (FirstSuccess = s[++Pos] == temp[strFirstPos])
							{
								strFirst += s[Pos];
							}
							if (!FirstSuccess) break;
						}
					}
					if (SecondCompare)
					{
						int Pos = ComparePos;
						for (--strSecondPos; strSecondPos >= 0; strSecondPos--)
						{
							if (SecondSuccess = s[++Pos] == temp[strSecondPos])
							{
								strSecond += s[Pos];
							}
							if (!SecondSuccess) break;;
						}
					}
					if (FirstSuccess)
					{
						strResult = strFirst;
					}
					else if (SecondSuccess)
					{
						strResult = strSecond;
					}

					bResult = FirstSuccess || SecondSuccess;
				}
			}
			else //사이즈가 1일 때
			{
				bResult = true;
				if (s[i] == s[i + 1])//반복하는지 검사할 다음 문자가 끝이나 끝 전이랑 같은지 확인
				{
					strResult += s[i + 1];
					bOverlap = true;
				}
			}
			
			// 결과 적용
			if (bResult)
			{
				if (nMax < strResult.size())
				{
					nMax = strResult.size();
					MaxResult = strResult;
				}					
			}
		}
	}

    return 0;
}

