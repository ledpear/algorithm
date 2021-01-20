#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int input;
	cin >> input;
	vector<int> vMap(input);
	for (int i = 0; i < input; i++)
		cin >> vMap[i];

	vector<int> vDP(input);

	if (input == 1)
		cout << vMap[0] << '\n';
	else if(input == 2)
		cout << vMap[1] + vMap[0] << '\n';
	else if(input == 3)
		cout << max(vMap[0] + vMap[2], vMap[1] + vMap[2]) << '\n';
	else
	{
		vDP[0] = vMap[0];
		vDP[1] = vMap[1] + vMap[0];
		vDP[2] = max(vMap[0] + vMap[2], vMap[1] + vMap[2]);

		for (int i = 3; i < input; i++)
		{
			vDP[i] = max(vMap[i] + vDP[i - 2], vMap[i] + vMap[i - 1] + vDP[i - 3]);
		}

		cout << vDP[input - 1] << '\n';
	}
	return 0;
}