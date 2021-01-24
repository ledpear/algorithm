#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	string input;
	cin >> input;

	vector<int> vNumber;
	vector<char> vOper;
	string strTemp = "";

	strTemp += input[0];
	for (int i = 1; i < input.size(); i++)
	{
		if (input[i] == '+' || input[i] == '-')
		{
			vNumber.push_back(stoi(strTemp));
			vOper.push_back(input[i]);
			strTemp = "";
		}
		else
		{
			strTemp += input[i];
		}
	}
	vNumber.push_back(stoi(strTemp));

	vector<bool> vUsed(vNumber.size(), false);
	for (int i = 0; i < vOper.size(); i++)
	{
		if (vOper[i] == '+')
		{
			vNumber[i] += vNumber[i + 1];
			vUsed[i + 1] = true;
		}
	}

	int nSum = vNumber[0];
	for (int i = 1; i < vNumber.size(); i++)
	{
		if (!vUsed[i])
			nSum -= vNumber[i];
	}

	cout << nSum << endl;

	return 0;
}