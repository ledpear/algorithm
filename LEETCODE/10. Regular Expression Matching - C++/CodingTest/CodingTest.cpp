// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

// bool CheckMatch(string s, string p, int m_s_pos, int m_p_pos)
// {
// 	bool bResult;
// 	int s_pos = m_s_pos;
// 	int p_pos = m_p_pos;
// 
// 	if (p[p_pos] == '.')
// 	{
// 		s_pos--;
// 	}
// 	else if (p[p_pos] == '*')
// 	{
// 
// 	}
// 
// 	return bResult;
// }

int main()
{
	string s;
	string p;
	int s_pos = s.size() - 1;
	for (int p_pos = p.size() - 1; p_pos >= 0; p_pos--)
	{
		if (p[p_pos] == '.')
		{
			s_pos--;
		}
		else if (p[p_pos] == '*')
		{

		}
	}

    return 0;
}

