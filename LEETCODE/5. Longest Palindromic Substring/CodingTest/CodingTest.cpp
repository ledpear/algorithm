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

			// �˻��� ���ڿ��� ����� 1�� �ƴ� ��
			if (temp.size() != 1)
			{
				if (i + j * 2 <= s.size() && s[ComparePos] == temp[temp.size() - 1])//�ݺ��ϴ��� �˻��� ���� ���ڰ� ���̳� �� ���̶� ������ Ȯ��
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

				// �ݺ��Ǵ� �������� �Ǵ�
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
			else //����� 1�� ��
			{
				bResult = true;
				if (s[i] == s[i + 1])//�ݺ��ϴ��� �˻��� ���� ���ڰ� ���̳� �� ���̶� ������ Ȯ��
				{
					strResult += s[i + 1];
					bOverlap = true;
				}
			}
			
			// ��� ����
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

