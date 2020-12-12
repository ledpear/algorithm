// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	int brown = 24;
	int yellow = 24;

	vector<int> answer;

	int area = brown + yellow;

	int Hsize = 2;
	int Wsize = area / Hsize;
	while (true)
	{
		Hsize++;
		if (area % Hsize == 0)
		{
			Wsize = area / Hsize;

			if (brown == ((2 * (Hsize + Wsize)) - 4))
			{
				answer.push_back(Wsize);
				answer.push_back(Hsize);
				break;
			}
		}			
	}

    return 0;
}

