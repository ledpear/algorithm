#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int nVol;
	cin >> nVol;
	vector<int> vInput(nVol);
	for (int i = 0; i < nVol; i++)
	{
		cin >> vInput[i];
	}
	vector<int> vDP(nVol);
	
	if (nVol == 1)
	{
		cout << vInput[0] << '\n';
	}
	else if (nVol == 2)
	{
		cout << vInput[0] + vInput[1] << '\n';
	}
	else if (nVol == 3)
	{
		cout << max({ vInput[0] + vInput[2], vInput[1] + vInput[2], vInput[0] + vInput[1] }) << '\n';
	}
	else
	{
		vDP[0] = vInput[0];
		vDP[1] = vInput[0] + vInput[1];
		vDP[2] = max({ vInput[0] + vInput[2], vInput[1] + vInput[2], vInput[0] + vInput[1] });

		for (int i = 3; i < nVol; i++)
		{
			vDP[i] = max({ vInput[i] + vDP[i - 2], vDP[i - 1], vInput[i] + vInput[i-1] + vDP[i - 3]});
		}

		cout << vDP[nVol - 1] << '\n';
	}

	return 0;
}