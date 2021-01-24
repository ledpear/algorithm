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

	string strTemp = "";
	bool bMinus = false;
	int nSum = 0;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '+' || input[i] == '-')
		{
			if (bMinus)
				nSum -= stoi(strTemp);
			else
				nSum += stoi(strTemp);

			strTemp = "";

			if (input[i] == '-')
				bMinus = true;
		}
		else
			strTemp += input[i];
	}
	if (bMinus)
		nSum -= stoi(strTemp);
	else
		nSum += stoi(strTemp);

	cout << nSum << '\n';

	return 0;
}