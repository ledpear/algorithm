#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int nMin = 1000000001;
int nMax = -1000000001;
vector<int> vOperator(4);	// +, -, *, /
vector<int> vNumber;

enum {
	Plus = 0,
	Minus,
	Multi,
	Div
};

void BackTracking(int cal, int count)
{
	if (count >= vNumber.size())
	{
		if (cal > nMax) nMax = cal;
		if (cal < nMin) nMin = cal;
		return;
	}
		
	if (vOperator[Plus] > 0)
	{
		vOperator[Plus]--;
		BackTracking(cal + vNumber[count], count + 1);
		vOperator[Plus]++;
	}
	if (vOperator[Minus] > 0)
	{
		vOperator[Minus]--;
		BackTracking(cal - vNumber[count], count + 1);
		vOperator[Minus]++;
	}
	if (vOperator[Multi] > 0)
	{
		vOperator[Multi]--;
		BackTracking(cal * vNumber[count], count + 1);
		vOperator[Multi]++;
	}
	if (vOperator[Div] > 0)
	{
		vOperator[Div]--;
		BackTracking(cal / vNumber[count], count + 1);
		vOperator[Div]++;
	}
}

int main()
{
	int input;
	cin >> input;
	int temp;
	for (int i = 0; i < input; i++)
	{
		cin >> temp;
		vNumber.push_back(temp);
	}

	cin >> vOperator[Plus] >> vOperator[Minus] >> vOperator[Multi] >> vOperator[Div];

	BackTracking(vNumber[0], 1);

	cout << nMax << "\n";
	cout << nMin << "\n";

	system("pause"); 

	return 0;
}