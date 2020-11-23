#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int nScore = 0;

	string answer = "";
	string s = "abdafsdfasdfasdfasdfcdae";

	int nSize = s.length();
	int nPos = nSize / 2;

	if (nSize % 2 == 0)
	{
		answer = s.substr(nPos - 1, 2);
	}
	else
	{
		answer = s[nPos];
	}




	system("pause");
	return nScore;
}