#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

enum {
	eWeek_SUN = 0,
	eWeek_MON,
	eWeek_TUE,
	eWeek_WED,
	eWeek_THU,
	eWeek_FRI,
	eWeek_SAT,
	eWeek_MAX
};

string strWeek[eWeek_MAX] = {
	"SUN",
	"MON",
	"TUE",
	"WED",
	"THU",
	"FRI",
	"SAT"
};

int nMonth[12] = {
	31,
	29,
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31
};

int main()
{
	int a, b;
	a = 5;
	b = 24;
	int nScore = 1;
	for (int i = 0; i < a; i++)
	{
		nScore += nMonth[i];
	}
	nScore += b;
	cout << strWeek[nScore % 7] << endl;
	system("pause");
	return nScore;
}