#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
#define INF -987654321

int main()
{
	string input;
	cin >> input;

	vector<int> vNumber;
	vector<char> vOper;
	string strTemp1 = "";
	string strTemp2 = "";

	strTemp1 += input[0];
	
	string strMinus = "";
	bool bPlus = false;
	for (int i = 1; i < input.size(); i++)
	{
		if (input[i] == '+' || input[i] == '-')
		{
			if (bPlus)
			{
				int nTemp = stoi(strTemp1) + stoi(strTemp2);
				strTemp2 = to_string(nTemp);
				bPlus = false;
			}

			if (input[i] == '-')
			{
				if(strTemp2.compare("") == 0)
					strMinus += strTemp1;
				else
					strMinus += strTemp2;
				
				strMinus += '-';
				strTemp1 = "";
				strTemp2 = "";
			}
			else if (input[i] == '+')
			{
				bPlus = true;
				strTemp2 = strTemp1;
				strTemp1 = "";
			}
		}
		else
		{
			strTemp1 += input[i];
		}
	}

	if (bPlus)
	{
		int nTemp = stoi(strTemp1) + stoi(strTemp2);
		strMinus += to_string(nTemp);
	}
	else
		strMinus += strTemp1;

	strTemp1 = strMinus[0];
	bool bFirst = true;
	int nSum = INF;
	for (int i = 1; i < strMinus.size(); i++)
	{
		if (strMinus[i] == '-')
		{
			if (bFirst)
			{
				nSum = stoi(strTemp1);
				bFirst = false;
			}
			else
			{
				nSum -= stoi(strTemp1);
			}
			strTemp1 = "";
		}
		else
		{
			strTemp1 += strMinus[i];
		}
	}

	if (nSum == INF)
		nSum = stoi(strTemp1);
	else
		nSum -= stoi(strTemp1);

	cout << nSum << '\n';

	return 0;
}