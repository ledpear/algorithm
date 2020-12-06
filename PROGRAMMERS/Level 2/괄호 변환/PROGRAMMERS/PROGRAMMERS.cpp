// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

string bracket(string u, string v)
{

	int score = 0;
	bool perfect = true;
	for (int i = 0; i < u.size(); i++)
	{
		if (u[i] == '(')
		{
			score++;
		}
		else if (u[i] == ')')
		{
			score--;
			if (score < 0)
			{
				perfect = false;
				break;
			}
		}
	}
	if (score > 0)	perfect = false;

	if (!perfect)
	{
		string temp = "";
		temp += '(';

		score = 0;
		int i;
		for (i = 0; i < v.size(); i++)
		{
			if (v[i] == '(')
			{
				score++;
			}
			else if (v[i] == ')')
			{
				score--;
			}

			if (score == 0)
			{
				break;
			}
		}

		if(v != "")
			temp += bracket(v.substr(0, i + 1), v.substr(i + 1));
		
		temp += ')';

		string Utemp = "";
		for (int j = 1; j < u.size() - 1; j++)
		{
			if (u[j] == '(')
				Utemp += ')';
			else if (u[j] == ')')
				Utemp += '(';
		}

		temp += Utemp;
		return temp;
	}
	else
	{
		if(v == "")
			return u;
		int i;
		for (i = 0; i < v.size(); i++)
		{
			if (v[i] == '(')
			{
				score++;
			}
			else if (v[i] == ')')
			{
				score--;
			}

			if (score == 0)
			{
				break;
			}
		}

		return u + bracket(v.substr(0, i + 1), v.substr(i + 1));
	}
}

int main()
{
	int nLast = -1;
	string answer = "";
	string p = ")(";

	int score = 0;
	vector<int> SavePosition;

	for (int i = 0; i < p.size(); i++)
	{
		if (p[i] == '(')
		{
			score++;
		}
		else if (p[i] == ')')
		{
			score--;
		}

		if (score == 0)
		{
			answer = bracket(p.substr(0, i + 1), p.substr(i + 1));
			break;
		}
	}
    return 0;
}

