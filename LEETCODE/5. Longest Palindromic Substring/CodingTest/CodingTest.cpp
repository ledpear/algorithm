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

			// �˻��� ���ڿ��� ����� 1�� �ƴ� ��
			if (temp.size() != 1)
			{
				if (s[i + j + 1] == temp[temp.size() - 1])//�ݺ��ϴ��� �˻��� ���� ���ڰ� ���̳� �� ���̶� ������ Ȯ��
				{
					strPos = temp.size() - 1;
				}
				else if (s[i + j + 1] == temp[temp.size() - 2])
				{
					strPos = temp.size() - 2;
				}
				else //�Ѵ� ���� ������ �ݺ����� �ʴ� ���̱� ������ Failó��
				{
					strPos = -1;
				}

				// �ݺ��Ǵ� �������� �Ǵ�
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
			else //����� 1�� ��
			{

			}
			
			// ��� ����
			if (bResult)
			{
				if (nMax < temp.size())
					nMax = temp.size();
			}
		}
	}

    return 0;
}

